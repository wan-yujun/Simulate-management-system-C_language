#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
// ����Ϣ�ṹ��
typedef struct Train		  
{
	char mode[20];			  // ����            
	char start[50];			  // ������
	char end[50];			  // Ŀ�ĵ�
	char time[10];			  // ����
	char time1[20];			  // ����ʱ��
	char time2[20];			  // ����ʱ��
	float  price;			  // Ʊ��
	char ticket[50];		  // ����Ʊ
}train;

// �������ṹ��
typedef struct List
{
	train s[300];			// ����Ϣ����
	int acount;				// ��¼��ǰ����Ϣ��
}list;

list L, *p;

// �˿���Ϣ�ṹ��
typedef struct node
{
	int type;				// �˿���� 		1��ʾ����Ʊ    2��ʾѧ��Ʊ
	char name[50];			// �˿�����
	char id_number[30];		// ֤������
	char sex[20];			// �Ա�
	char phone_number[20];	// �ֻ�����
}passenger;

passenger yh;

// ������
void order_ticket();            		// ��Ʊ
void change_ticket();					// ��ǩ
void refund_ticket();           		// ��Ʊ

// ���ú���
void pass_word();						// ֧������
void train_ticket_detail(int i);		// ��Ʊ��������
void print_progress_bar();      		// ��ӡ������
void endorse_print();					// ��ǩ��������
void id_card(int i);					// �˿������Ϣ
void seek();							// ��ѯ��Ʊ
void meau();                    		// ���˵�ҳ��
list *read_file(list *L);				// ��ȡ�ļ��ڻ𳵳�����Ϣ
void color(int m);              		// �޸������д����ɫ

int k, Q;								// �˿�ѡ��𳵳������			     k�ǳ˿͵�һ��ѡ��  Q�ǳ˿͸�ǩʱѡ			
int buy_ticket;							// �жϵڼ�����Ʊ	 	 		    1��ʾ��һ����Ʊ	   2��ʾ�ڶ�����Ʊ
int ticket_true = 0;					// �ж��Ƿ��Ѿ���Ʊ      			0��ʾû��    	   1��ʾ�Ѿ���Ʊ
char data[20];							// �˿���������
char start1[50];						// �˿����������
char end1[50];							// �˿�����Ŀ�ĵ�
char check[50] = "�ۿ�";				// �жϳ����Ƿ���Ʊ

int main()
{
	srand(time(NULL));			// �����������
    char cmd;
    while (1)
    {
        meau();					// ���˵�ҳ��	
        cmd = getch();			// �����ַ�
        switch (cmd)
        {
        case '1': order_ticket(); break;		// ��Ʊ
        case '2': change_ticket(); break;		// ��ǩ
        case '3': refund_ticket(); break;		// ��Ʊ
        case '0': return 0;						// �˳�ϵͳ
        }
    }
}

// ��Ʊ
void refund_ticket()
{
	system("cls");
	if (ticket_true == 1)
	{
		printf("��Ʊ����\n\n\n\n");
		printf("��Ʊ�ĳ˿�");
		printf("\n\n%s", yh.name);
		if (yh.type == 2)
		{
			printf(" ѧ��");
		}
		else
		{
			printf(" ����");
		}
		printf("\n\n\n����˵��\n\n\n");
		printf("��·����Ʊ��(Ԥ��)			   -��0\n\n");
		if (yh.type == 1 && buy_ticket == 1)
		{
			printf("�˻��ܶ�				    ��%.1f  |  Ӳ��", p->s[k].price);
		}
		if (yh.type == 1 && buy_ticket == 2)
		{
			printf("�˻��ܶ�				    ��%.1f  |  Ӳ��", p->s[Q].price);
		}
		if (yh.type == 2 && buy_ticket == 1)
		{
			printf("�˻��ܶ�			    ��%d  |  Ӳ��",(int) (p->s[k].price));
		}
		if (yh.type == 2 && buy_ticket == 2)
		{
			printf("�˻��ܶ�			    ��%d  |  Ӳ��",(int) (p->s[Q].price));
		}
		printf("\n\n\n\n��Ʊ��ʾ\n\n");
		printf("���˿���ճ˿ͷֱ��˿Ԥ��7�����������˻�ԭ֧���˻�;\n");
		printf("�����ڳ�վ���ڰ�����Ʊ��Ԥ��1-15�����������˻�ԭ֧���˻�;\n");
		printf("����Ʊ�����Ѿ�����·����ȡ��ͬ�̲���ȡ�κη��á�");
		printf("\n\n\n��������������˵�");
		ticket_true = 0;
		getch();
	}
	else
	{
		system("cls");
		printf("��δԤ����Ʊ��������Ʊ\n\n");
		printf("��������������˵�");
		getch();
		return;
	}
}

// ��ǩ
void change_ticket()
{
	int i;
	if (ticket_true == 1 && buy_ticket == 2)
	{
		system("cls");
		printf("�˿ͣ��ǳ���Ǹ���Ѹ�ǩ���³�Ʊ�����ٴθ�ǩ��������Ʊ\n\n\n");
		printf("�������������һ��");
		getch();
		return;
	}
	if (ticket_true == 0)
	{
		system("cls");
		printf("��δԤ����Ʊ�����ܸ�ǩ\n\n");
		printf("��������������˵�");
		getch();
		return;
	}
	if (ticket_true == 1 && buy_ticket == 1)
	{
		up:
		system("cls");
		printf("���\t����\t������\tĿ�ĵ�\t����\t����ʱ��\t����ʱ��\tƱ��\t����Ʊ\n");
		for (i = 0; i < p->acount; i++)
		{
			if (strcmp(p->s[i].time, data) == 0 && strcmp(p->s[i].start, start1) == 0 && strcmp(p->s[i].end, end1) == 0)
			{
				printf("%d\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%.1f\t%s\n", i, p->s[i].mode, p->s[i].start, p->s[i].end, p->s[i].time, p->s[i].time1, p->s[i].time2, p->s[i].price, p->s[i].ticket);
			}
		}
		printf("\n������Ҫ��ǩ�Ļ𳵳��ε����:");
		scanf("%d", &Q);						// ��ǩʱ��ѡ��𳵳������
		if (Q == k)								// �жϵ�һ�ζ�Ʊѡ������Ƿ�͸�ǩʱѡ�������ͬ
		{
			system("cls");
			printf("		��ǩ�г���ԭ�г��ظ�\n\n");
			printf("Ϊ����������ʧ����������ĳ��У�������ѡ����ĸ�ǩ��Ϣ:\n\n");
			printf("�������������һ��");
			getch();
			goto up;
		}
		else
		{
			if (strcmp(p->s[Q].ticket, check))
			{
				system("cls");
				printf("����:%s\n\n", data);
				printf("%s	%s\n", p->s[Q].time1, start1);
				printf("%s	%s", p->s[Q].time2, end1);
				printf("\n\n");
				printf("����	��ϯ");
				printf("\n%s	Ӳ��", p->s[Q].mode);
				printf("\n\n%s", yh.name);
				if (yh.type == 2)
				{
					printf(" ѧ��");
				}
				else
				{
					printf(" ����");
				}
				if (yh.type == 1)
				{
					printf("					��%.1f\n\n", p->s[Q].price);
				}
				else
				{
					p->s[Q].price *= 0.5;
					printf("					��%d\n\n",(int) (p->s[Q].price));
				}
				printf("��������ύ��ǩ");
				getch();
				endorse_print(Q);
			}
			else
			{
				printf("\n���г�������Ʊ���밴���������ѡ��");
				getch();
				goto up;
			}
			
		}
	}
}

// ���˵�ҳ��
void meau()
{
 //   COORD pos = {0, 0};
	// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    // color(3);
    system("cls");
    printf("\n");
	printf("\t��ӭ����𳵶�Ʊϵͳ\n");
	printf("*****************************\n");
	printf("*       �𳵶�Ʊ����ϵͳ    *\n");
    printf("*      1.��          Ʊ     *\n");
    printf("*      2.��          ǩ     *\n");
    printf("*      3.��          Ʊ     *\n");
    printf("*      0.��  ��  ϵ  ͳ     *\n");
    printf("*****************************\n");
    printf("�� ѡ ��(0-3):\n");
}

// ��Ʊ
void order_ticket()
{
	seek();			// ��ѯ��Ʊ
}

// ��ѯ��Ʊ 
void seek()
{
	int i;
	system("cls");
	p = read_file(&L);		// ���ṹ�����L�ĵ�ַ����read_file�����е��β�(list *L)
	printf("Ŀǰֻ��2��14�ջ�2��15�գ��Ž������ϲ������ϲ������Ž��Ļ�\n\n");
	printf("��ʾ:(���趩��3��1�ŵĻ�Ʊ�������� 3.1   ������������)\n");
	printf("�����붩Ʊ����:");
	scanf("%s", data);
	printf("�����������:");
	scanf("%s", start1);
	printf("������Ŀ�ĵ�:");
	scanf("%s", end1);
	printf("��Ʊ��ѯ��...");
	Sleep(2*1000);
	look : 
	system("cls");
	printf("���\t����\t������\tĿ�ĵ�\t����\t����ʱ��\t����ʱ��\tƱ��\t����Ʊ\n");
	for (i = 0; i < p->acount; i++)
	{
		if (strcmp(p->s[i].time, data) == 0 && strcmp(p->s[i].start, start1) == 0 && strcmp(p->s[i].end, end1) == 0)
		{
			printf("%d\t%s\t%s\t%s\t%s\t%s\t\t%s\t\t%.1f\t%s\n", i, p->s[i].mode, p->s[i].start, p->s[i].end, p->s[i].time, p->s[i].time1, p->s[i].time2, p->s[i].price, p->s[i].ticket);
		}
	}
	printf("\n������ҪԤ���Ļ𳵳��ε����:");
	scanf("%d", &k);
	if (strcmp(p->s[k].ticket, check))
	{
		Sleep(200);
		id_card(k);
	}
	else
	{
		printf("\n���г�������Ʊ���밴���������ѡ��");
		getch();
		goto look;
	}
	train_ticket_detail(k);    // �𳵶�Ʊ����
}

// ��Ʊ��������
void train_ticket_detail(int i)
{
	int y, h;
	system("cls");
	printf("����ռ���С�����\n\n");
	printf("Ԥ��10����֪ռ�����\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("����	��ϯ");
	printf("\n%s	Ӳ��", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	printf("					ռ����\n\n");
	Sleep(10*1000);
	system("cls");
	printf("������\n\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("����	��ϯ");
	printf("\n%s	Ӳ��", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	y = (rand() % 15) + 1;
	h = (rand() % 105) + 1;
	printf("				%d����%d��\n\n\n", y, h);
	if (yh.type == 1)
	{
		printf("����Ʊ					��%.1f��1��\n\n", p->s[i].price);
		printf("�����ܶ�				    ��%.1f", p->s[i].price);
	}
	else
	{
		printf("ѧ��Ʊ				��%d��1��\n\n",(int) (p->s[i].price));
		printf("�����ܶ�			    ��%d",(int) (p->s[i].price));
	}
	printf("\n\n\n");
	printf("�����������֧��");
	getch();
	pass_word();	// ֧������
	system("cls");
	printf("���ѹ�Ʊ�ɹ�\n\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[i].time1, start1);
	printf("%s	%s", p->s[i].time2, end1);
	printf("\n\n");
	printf("����	��ϯ	��Ʊ��");
	printf("\n%s	Ӳ��	�Գ�վ������ʾΪ׼", p->s[i].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	printf("				%d����%d��\n\n\n", y, h);
	ticket_true = 1;
	buy_ticket = 1;
	printf("��������������˵�");
	getch();
}

// ֧������
void pass_word()
{
	char user[10];								// ��������
	char key[7]={'1','2','3','4','5','6'};		// ԭʼ����
	system("cls");
	printf("Ĭ������Ϊ123456\n\n");
	printf("������֧������\n");
	loop:
	for (int i = 0; i < 10; i++)
	{
		user[i] = getch();
		if (user[i] != 13 && user[i] != 8)			// ASCII�е�13�ǻس���8��ɾ����
		{
			printf("*");
		}
		if (user[i] == 13)			// ���»س����������������
		{
			user[i] = '\0';
			break;
		}
		if (user[i] == 8)			// ����ɾ������ɾ��һ������������
		{
			i -= 2;
			if (i == -2)			// ��ֹһֱɾ������ɳ������
			{
				i = -1;
			}
			printf("\b");  // \b�ĺ����ǣ������ӵ�ǰλ����ǰ�����ƶ�һ���ַ������Ӵ�λ�ÿ�ʼ���������ַ���
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
		printf("�����������������:\n");
		goto loop;
	}
}

// �˿������Ϣ
void id_card(int i)
{
	system("cls");
	printf("	�밴��Ҫ������˿���Ϣ\n");
	printf("�˿�����:	1:����Ʊ	2:ѧ��Ʊ\n");
	scanf("%d", &yh.type);
	printf("\n�˿�����:");
	scanf("%s", yh.name);
	printf("\nĬ��֤��Ϊ���֤\n\n֤������:");
	scanf("%s", yh.id_number);
	printf("\n�Ա�:");
	scanf("%s", yh.sex);
	printf("\n�ֻ�����:(+86)");
	scanf("%s", yh.phone_number);
	printf("\n");
	printf("ȷ������������������һ��");
	getch();
	system("cls");
	if (yh.type == 1)
	{
		printf("�ܶ%.1f", p->s[i].price);
		printf("\n\n��������ύ����\n");
		getch();
	}
	else
	{
		p->s[i].price *= 0.5;
		printf("�ܶ%d", (int) (p->s[i].price));
		printf("\n\n��������ύ����\n");
		getch();
	}
	printf("\n");
	print_progress_bar();	// ����˿���ݼ��ؽ�����
}

// ��ǩ��������
void endorse_print(int Q)
{
	int i, m, Y, H;
	system("cls");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("����	��ϯ");
	printf("\n%s	Ӳ��", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	printf("				��ǩռ����\n\n\n\n");
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
		printf("		��ǩռ����%3d%%\r",i);
        Sleep(100);
	}
	system("cls");
	printf("���ڸ�ǩռ���С�����\n\n");
	printf("Ԥ��10����֪ռ�����\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("����	��ϯ");
	printf("\n%s	Ӳ��", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	printf("					��ǩռ����\n\n");
	Sleep(10*1000);
	system("cls");
	printf("������\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("����	��ϯ");
	printf("\n%s	Ӳ��", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	Y = (rand() % 15) + 1;
	H = (rand() % 105) + 1;
	printf("				%d����%d��\n\n\n", Y, H);
	if (yh.type == 1)
	{
		printf("����Ʊ					��%.1f��1��\n\n", p->s[Q].price);
		printf("�����ܶ�				    ��%.1f", p->s[Q].price);
	}
	else
	{
		printf("ѧ��Ʊ				��%d��1��\n\n",(int) (p->s[Q].price));
		printf("�����ܶ�			    ��%d",(int) (p->s[Q].price));
	}
	printf("\n\n\n");
	printf("�����������֧��");
	getch();
	pass_word();	// ֧������
	system("cls");
	printf("��ǩ�ɹ�\n\n");
	printf("����:%s\n\n", data);
	printf("%s	%s\n", p->s[Q].time1, start1);
	printf("%s	%s", p->s[Q].time2, end1);
	printf("\n\n");
	printf("����	��ϯ	��Ʊ��");
	printf("\n%s	Ӳ��	�Գ�վ������ʾΪ׼", p->s[Q].mode);
	printf("\n\n%s", yh.name);
	if (yh.type == 2)
	{
		printf(" ѧ��");
	}
	else
	{
		printf(" ����");
	}
	printf("				%d����%d��\n\n", Y, H);
	printf("\n\n��������������˵�");
	getch();
	buy_ticket = 2;
}

// ��ӡ������
void print_progress_bar()
{
	int i, m;
	for ( i = 0; i <= 100; i++)
	{
		printf("����Ϊ������˿����		");
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
		printf("%3d%%\r",i);   // '\r'�س����ص���ǰ�е����ף������ỻ����һ�У������������Ļ���������ǰ�����ݻᱻ��һ����
        Sleep(100);
	}
}

// ��ȡ�ļ��ڻ𳵳�����Ϣ
list *read_file(list *L)
{
	L->acount = 0;
	int i = 0;
	FILE *fp;
	if ((fp = fopen("C:\\Users\\admin\\Desktop\\�𳵳�����Ϣ.txt", "r")) == NULL)
	{
		printf("���������洴���𳵳�����Ϣ.txt�ļ���������������\n");
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

// �޸������д����ɫ
void color(int m)
{
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m);
}