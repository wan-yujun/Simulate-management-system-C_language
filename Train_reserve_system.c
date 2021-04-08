#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
// 火车信息结构体
typedef struct Train		  
{
	char mode[20];			  // 车次            
	char start[50];			  // 出发地
	char end[50];			  // 目的地
	char time[10];			  // 日期
	char time1[20];			  // 出发时间
	char time2[20];			  // 到达时间
	float  price;			  // 票价
	char ticket[50];		  // 有无票
}train;

// 火车列数结构体
typedef struct List
{
	train s[300];			// 火车信息数组
	int acount;				// 记录当前火车信息数
}list;

list L, *p;

// 乘客信息结构体
typedef struct node
{
	int type;				// 乘客类别 		1表示成人票    2表示学生票
	char name[50];			// 乘客姓名
	char id_number[30];		// 证件号码
	char sex[20];			// 性别
	char phone_number[20];	// 手机号码
}passenger;

passenger yh;

// 主函数
void order_ticket();            		// 订票
void change_ticket();					// 改签
void refund_ticket();           		// 退票

// 调用函数
void pass_word();						// 支付密码
void train_ticket_detail(int i);		// 火车票订单详情
void print_progress_bar();      		// 打印进度条
void endorse_print();					// 改签订单详情
void id_card(int i);					// 乘客身份信息
void seek();							// 查询火车票
void meau();                    		// 主菜单页面
list *read_file(list *L);				// 读取文件内火车车次信息
void color(int m);              		// 修改命令行窗口顔色

int k, Q;								// 乘客选择火车车次序号			     k是乘客第一次选，  Q是乘客改签时选			
int buy_ticket;							// 判断第几次买票	 	 		    1表示第一次买票	   2表示第二次买票
int ticket_true = 0;					// 判断是否已经购票      			0表示没有    	   1表示已经购票
char data[20];							// 乘客输入日期
char start1[50];						// 乘客输入出发地
char end1[50];							// 乘客输入目的地
char check[50] = "售空";				// 判断车次是否还有票

int main()
{
	srand(time(NULL));			// 设置随机种子
    char cmd;
    while (1)
    {
        meau();					// 主菜单页面	
        cmd = getch();			// 接收字符
        switch (cmd)
        {
        case '1': order_ticket(); break;		// 订票
        case '2': change_ticket(); break;		// 改签
        case '3': refund_ticket(); break;		// 退票
        case '0': return 0;						// 退出系统
        }
    }
}

// 退票
void refund_ticket()
{
	system("cls");
	if (ticket_true == 1)
	{
		printf("退票申请\n\n\n\n");
		printf("退票的乘客");
		printf("\n\n%s", yh.name);
		if (yh.type == 2)
		{
			printf(" 学生");
		}
		else
		{
			printf(" 成人");
		}
		printf("\n\n\n费用说明\n\n\n");
		printf("铁路局退票费(预估)			   -￥0\n\n");
		if (yh.type == 1 && buy_ticket == 1)
		{
			printf("退还总额				    ￥%.1f  |  硬座", p->s[k].price);
		}
		if (yh.type == 1 && buy_ticket == 2)
		{
			printf("退还总额				    ￥%.1f  |  硬座", p->s[Q].price);
		}
		if (yh.type == 2 && buy_ticket == 1)
		{
			printf("退还总额			    ￥%d  |  硬座",(int) (p->s[k].price));
		}
		if (yh.type == 2 && buy_ticket == 2)
		{
			printf("退还总额			    ￥%d  |  硬座",(int) (p->s[Q].price));
		}
		printf("\n\n\n\n退票提示\n\n");
		printf("·退款将按照乘客分笔退款，预计7个工作日内退回原支付账户;\n");
		printf("·已在车站窗口办理退票，预计1-15个工作日内退回原支付账户;\n");
		printf("·退票手续费均由铁路局收取，同程不收取任何费用。");
		printf("\n\n\n按任意键返回主菜单");
		ticket_true = 0;
		getch();
	}
	else
	{
		system("cls");
		printf("您未预订火车票，不能退票\n\n");
		printf("按任意键返回主菜单");
		getch();
		return;
	}
}

// 改签
void change_ticket()
{
	int i;
	if (ticket_true == 1 && buy_ticket == 2)
	{
		system("cls");
		printf("乘客，非常抱歉，已改签的新车票不可再次改签，仅能退票\n\n\n");
		printf("按任意键返回上一层");
		getch();
		return;
	}
	if (ticket_true == 0)
	{
		system("cls");
		printf("您未预订火车票，不能改签\n\n");
		printf("按任意键返回主菜单");
		getch();
		return;
	}
	if (ticket_true == 1 && buy_ticket == 1)
	{
		up:
		system("cls");
		printf("序号\t车次\t出发地\t目的地\t日期\t出发时间\t到达时间\t票价\t有无票\n");
		for (i = 0; i < p->acount; i++)
		{
			if (strcmp(p->s[i].time, data) == 0 && strcmp(p->s[i].start, start1) == 0 && strcmp(p->s[i].end, end1) == 0)
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%.1f\t%s\n", i, p->s[i].mode, p->s[i].start, p->s[i].end, p->s[i].time, p->s[i].time1, p->s[i].time2, p->s[i].price, p->s[i].ticket);
			}
		}
		printf("\n请输入要改签的火车车次的序号:");
		scanf("%d", &Q);						// 改签时的选择火车车次序号
		if (Q == k)								// 判断第一次订票选的序号是否和改签时选的序号相同
		{
			system("cls");
			printf("		改签行程与原行程重复\n\n");
			printf("为避免您操作失误而耽误您的出行，请重新选择你的改签信息:\n\n");
			printf("按任意键返回上一层");
			getch();
			goto up;
		}
		else
		{
			if (strcmp(p->s[Q].ticket, check))
			{
				system("cls");
				printf("日期:%s\n\n", data);
				printf("%s	%s\n", p->s[Q].time1, start1);
				printf("%s	%s", p->s[Q].time2, end1);
				printf("\n\n");
				printf("车次	座席");
				printf("\n%s	硬座", p->s[Q].mode);
				printf("\n\n%s", yh.name);
				if (yh.type == 2)
				{
					printf(" 学生");
				}
				else
				{
					printf(" 成人");
				}
				if (yh.type == 1)
				{
					printf("					￥%.1f\n\n", p->s[Q].price);
				}
				else
				{
					p->s[Q].price *= 0.5;
					printf("					￥%d\n\n",(int) (p->s[Q].price));
				}
				printf("按任意键提交改签");
				getch();
				endorse_print(Q);
			}
			else
			{
				printf("\n该列车暂无余票，请按任意键重新选择。");
				getch();
				goto up;
			}
			
		}
	}
}

// 主菜单页面
void meau()
{
 //   COORD pos = {0, 0};
	// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    // color(3);
    system("cls");
    printf("\n");
	printf("\t欢迎进入火车订票系统\n");
	printf("*****************************\n");
	printf("*       火车订票客运系统    *\n");
    printf("*      1.订          票     *\n");
    printf("*      2.改          签     *\n");
    printf("*      3.退          票     *\n");
    printf("*      0.退  出  系  统     *\n");
    printf("*****************************\n");
    printf("请 选 择(0-3):\n");
}

// 订票
void order_ticket()
{
	seek();			// 查询火车票
}

// 查询火车票 
void seek()
{
	int i;
	system("cls");
	p = read_file(&L);		// 将结构体变量L的地址传给read_file函数中的形参(list *L)
	printf("目前只有2月14日或2月15日，九江——南昌或者南昌——九江的火车\n\n");
	printf("提示:(如需订购3月1号的火车票，就输入 3.1   其他日期类似)\n");
	printf("请输入订票日期:");
	scanf("%s", data);
	printf("请输入出发地:");
	scanf("%s", start1);
	printf("请输入目的地:");
	scanf("%s", end1);
	printf("火车票查询中...");
	Sleep(2*1000);
	look : 
	system("cls");
	printf("序号\t车次\t出发地\t目的地\t日期\t出发时间\t到达时间\t票价\t有无票\n");
	for (i = 0; i < p->acount; i++)
	{
		if (strcmp(p->s[i].time, data) == 0 && strcmp(p->s[i].start, start1) == 0 && strcmp(p->s[i].end, end1) == 0)
		{
			printf("%d\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%.1f\t%s\n", i, p->s[i].mode, p->s[i].start, p->s[i].end, p->s[i].time, p->s[i].time1, p->s[i].time2, p->s[i].price, p->s[i].ticket);
		}
	}
	printf("\n请输入要预订的火车车次的序号:");
	scanf("%d", &k);
	if (strcmp(p->s[k].ticket, check))
	{
		Sleep(200);
		id_card(k);
	}
	else
	{
		printf("\n该列车暂无余票，请按任意键重新选择。");
		getch();
		goto look;
	}
	train_ticket_detail(k);    // 火车订票详情
}

// 火车票订单详情
void train_ticket_detail(int i)
{
	int y, h;
	system("cls");
	printf("正在占座中···\n\n");
	printf("预计10秒后告知占座结果\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("车次	座席");
	printf("\n%s	硬座", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	printf("					占座中\n\n");
	Sleep(10*1000);
	system("cls");
	printf("待付款\n\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("车次	座席");
	printf("\n%s	硬座", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	y = (rand() % 15) + 1;
	h = (rand() % 105) + 1;
	printf("				%d车厢%d号\n\n\n", y, h);
	if (yh.type == 1)
	{
		printf("成人票					￥%.1f×1张\n\n", p->s[i].price);
		printf("订单总额				    ￥%.1f", p->s[i].price);
	}
	else
	{
		printf("学生票				￥%d×1张\n\n",(int) (p->s[i].price));
		printf("订单总额			    ￥%d",(int) (p->s[i].price));
	}
	printf("\n\n\n");
	printf("按任意键立即支付");
	getch();
	pass_word();	// 支付密码
	system("cls");
	printf("你已购票成功\n\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("车次	座席	检票口");
	printf("\n%s	硬座	以车站大屏显示为准", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	printf("				%d车厢%d号\n\n\n", y, h);
	ticket_true = 1;
	buy_ticket = 1;
	printf("按任意键返回主菜单");
	getch();
}

// 支付密码
void pass_word()
{
	char user[10];								// 输入密码
	char key[7]={'1','2','3','4','5','6'};		// 原始密码
	system("cls");
	printf("默认密码为123456\n\n");
	printf("请输入支付密码\n");
	loop:
	for (int i = 0; i < 10; i++)
	{
		user[i] = getch();
		if (user[i] != 13 && user[i] != 8)			// ASCII中的13是回车，8是删除键
		{
			printf("*");
		}
		if (user[i] == 13)			// 按下回车键，密码输入结束
		{
			user[i] = '\0';
			break;
		}
		if (user[i] == 8)			// 按下删除键，删除一个数重新输入
		{
			i -= 2;
			if (i == -2)			// 防止一直删除，造成程序崩溃
			{
				i = -1;
			}
			printf("\b");  // \b的含义是，将光标从当前位置向前（左）移动一个字符，并从此位置开始输出后面的字符。
			printf(" ");
			printf("\b");
		}
	}
	if (strcmp(key, user) == 0)
	{
		return;
	}
	else
	{
		system("cls");
		printf("密码错误，请重新输入:\n");
		goto loop;
	}
}

// 乘客身份信息
void id_card(int i)
{
	system("cls");
	printf("	请按照要求输入乘客信息\n");
	printf("乘客类型:	1:成人票	2:学生票\n");
	scanf("%d", &yh.type);
	printf("\n乘客姓名:");
	scanf("%s", yh.name);
	printf("\n默认证件为身份证\n\n证件号码:");
	scanf("%s", yh.id_number);
	printf("\n性别:");
	scanf("%s", yh.sex);
	printf("\n手机号码:(+86)");
	scanf("%s", yh.phone_number);
	printf("\n");
	printf("确认无误后按任意键继续下一步");
	getch();
	system("cls");
	if (yh.type == 1)
	{
		printf("总额￥%.1f", p->s[i].price);
		printf("\n\n按任意键提交订单\n");
		getch();
	}
	else
	{
		p->s[i].price *= 0.5;
		printf("总额￥%d", (int) (p->s[i].price));
		printf("\n\n按任意键提交订单\n");
		getch();
	}
	printf("\n");
	print_progress_bar();	// 核验乘客身份加载进度条
}

// 改签订单详情
void endorse_print(int Q)
{
	int i, m, Y, H;
	system("cls");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("车次	座席");
	printf("\n%s	硬座", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	printf("				改签占座中\n\n\n\n");
	for ( i = 0; i <= 100; i++)
	{
		printf("[");
		m = i / 5;
		for (int j = 0; j < 20; j++)
		{
			if (j < m)
			{
				printf("%c", '>');
			}
			else
			{
				printf(" ");
			}
		}
		printf("]");
		printf("		改签占座中%3d%%\r",i);
        Sleep(100);
	}
	system("cls");
	printf("正在改签占座中···\n\n");
	printf("预计10秒后告知占座结果\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("车次	座席");
	printf("\n%s	硬座", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	printf("					改签占座中\n\n");
	Sleep(10*1000);
	system("cls");
	printf("待付款\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("车次	座席");
	printf("\n%s	硬座", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	Y = (rand() % 15) + 1;
	H = (rand() % 105) + 1;
	printf("				%d车厢%d号\n\n\n", Y, H);
	if (yh.type == 1)
	{
		printf("成人票					￥%.1f×1张\n\n", p->s[Q].price);
		printf("订单总额				    ￥%.1f", p->s[Q].price);
	}
	else
	{
		printf("学生票				￥%d×1张\n\n",(int) (p->s[Q].price));
		printf("订单总额			    ￥%d",(int) (p->s[Q].price));
	}
	printf("\n\n\n");
	printf("按任意键立即支付");
	getch();
	pass_word();	// 支付密码
	system("cls");
	printf("改签成功\n\n");
	printf("日期:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("车次	座席	检票口");
	printf("\n%s	硬座	以车站大屏显示为准", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" 学生");
	}
	else
	{
		printf(" 成人");
	}
	printf("				%d车厢%d号\n\n", Y, H);
	printf("\n\n按任意键返回主菜单");
	getch();
	buy_ticket = 2;
}

// 打印进度条
void print_progress_bar()
{
	int i, m;
	for ( i = 0; i <= 100; i++)
	{
		printf("正在为您核验乘客身份		");
		printf("[");
		m = i / 5;
		for (int j = 0; j < 20; j++)
		{
			if (j < m)
			{
				printf("%c", '>');
			}
			else
			{
				printf(" ");
			}
		}
		printf("]");
		printf("%3d%%\r",i);   // '\r'回车，回到当前行的行首，而不会换到下一行，如果接着输出的话，本行以前的内容会被逐一覆盖
        Sleep(100);
	}
}

// 读取文件内火车车次信息
list *read_file(list *L)
{
	L->acount = 0;
	int i = 0;
	FILE *fp;
	if ((fp = fopen("C:\\Users\\admin\\Desktop\\火车车次信息.txt", "r")) == NULL)
	{
		printf("请先在桌面创建火车车次信息.txt文件后重新启动程序\n");
		getchar();
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%f\t%s\t", L->s[i].mode, L->s[i].start, L->s[i].end, L->s[i].time, L->s[i].time1, L->s[i].time2, &L->s[i].price, L->s[i].ticket);
		i++;
		L->acount++;
	}
	fclose(fp);
	return L;
}

// 修改命令行窗口顔色
void color(int m)
{
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m);
}