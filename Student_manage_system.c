#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct node{															//定义结构体类型
	int ID;																		//定义学号
	char name[20];																//定义姓名
	char sex[10];																//定义性别
	int math,Eng,com;															//分别定义数学成绩、英语成绩、计算机成绩
}student;																		//重新定义结构体类型名															

int input(student stu[],int n){										     		//学生信息添加函数

	int i,k,j;												//flag为判断学号是否重复标志
		printf("请输入添加的学生的人数:");
		scanf("%d",&k);																//添加k个学生人数
		for(i=n+1;i<=k+n;i++)
		{
			printf("请依次输入第%d个学生的信息",i);
			printf("学号:");
			scanf("%d",&stu[i].ID);
			for(j=1;i-j>=0;j++)
			{
				if(stu[i-j].ID==stu[i].ID)
				{
					do
					{
						printf("学号重复，请重新输入:\n");
						scanf("%d",&stu[i].ID);
							for(j=1;i-j>=0;j++)
								if(stu[i-j].ID==stu[i].ID)
									break;
					}while(stu[i-j].ID==stu[i].ID);
				}
			}
			printf("姓名:");
			scanf("%s",stu[i].name);
			printf("性别:");
			scanf("%s",stu[i].sex);
			printf("数学成绩:");
			scanf("%d",&stu[i].math);
			printf("英语成绩:");
			scanf("%d",&stu[i].Eng);
			printf("计算机成绩:");
			scanf("%d",&stu[i].com);
			printf("学生信息录入成功\n");
		}

		return --i;																	//返回系统现有学生人数
}

void output(student stu[],int n){												//学生信息输出函数
	
	int i;
	if(n==0)
		printf("管理系统中暂无学生信息，请返回主菜单中添加成员\n");
	else
	{
		printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");				
		for(i=1;i<=n;i++)
			printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
	}
}
																														
void menu()																		//主菜单函数
{
	system("color 7c");
	Sleep(20);	printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	Sleep(20);	printf("|                                         欢迎使用孤儿之家学生信息管理系统                                                       |\n");
	Sleep(20);	printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	Sleep(20);  printf("请选择操作:\n\n\n");
	Sleep(20);	printf("\t\t\t\t\t|=========================|=============================|\n");
	Sleep(20);  printf("\t\t\t\t\t|1:添加学生信息. 	  |"); printf(" 2:查询学生信息.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|3:修改学生信息.	  |"); printf(" 4:删除学生信息.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|5:输出学生信息.	  |"); printf(" 6:排序学生信息.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|7:读入文件数据.	  |"); printf(" 8:读取文件数据.		|\n");
	Sleep(20);	printf("\t\t\t\t\t|0:退出系统.		  |"); printf("				|\n");
	Sleep(20);	printf("\t\t\t\t\t|=========================|=============================|\n");
}

void back()																		//退出系统
{
	exit(0);
}

void chaxun(student stu[],int n)												//查询函数
{
	int i,t,k;
	char name[20];
	if(n==0)
		printf("管理系统中暂无学生信息，请返回主菜单中添加成员\n");
	else
	{
		printf("请选择哪种方式进行查询单个学生信息:\n");
		printf("1:按学号进行查询\t2:按姓名进行查询\n");
		scanf("%d",&t);															//选择查询方式
		while(t!=1&&t!=2)
		{	printf("没有此选项,请重新输入选项:\n");
			scanf("%d",&t);
		}
		if(t==1)																//按学号进行查询
		{	
			{
				printf("请输入查询学生的学号:\n");
				scanf("%d",&k);
				for(i=1;i<=n;i++)
				{
					if(k==stu[i].ID)												//判断系统中是否存在输入的学号
					{
						printf("已找到该学生信息,学生信息如下:\n");
						printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
						printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
						break;
					}
				}
			}
			if(i>n)
				printf("未找到该学号学生信息\n");
		}
		if(t==2)																//按姓名进行查询
		{
			printf("请输入查询学生的姓名:\n");
			scanf("%s",name);
			for(i=1;i<=n;i++)
			{
				if(strcmp(name,stu[i].name)==0)									//判断系统中是否存在输入的姓名
				{	
					printf("已找到该学生信息,学生信息如下:\n");
					printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
					printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				//	break;
				}
			}
			if(i>n)
				printf("未找到该学号学生信息\n");
		}
	}
}

void revise(student stu[],int n)												//单个学生信息修改函数
{
	int i,m;
	if(n==0)
		printf("管理系统中暂无学生信息，请返回主菜单中添加成员\n");
	else
	{
		printf("请输入要修改的学生的学号:");
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			if(m==stu[i].ID)													//判断系统中是否存在输入的学号	
			{
				printf("已找到该学生，该学生的原信息:\n");
				printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
				printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				printf("请输入修改后的信息:\n");
				printf("数学成绩:");
				scanf("%d",&stu[i].math);
				printf("英语成绩:");
				scanf("%d",&stu[i].Eng);
				printf("计算机成绩:");
				scanf("%d",&stu[i].com);
				printf("修改成功\n");
				printf("修改后该学生的信息为:\n");
				printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
				printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				break;
			}
		}
		if(i>n)
			printf("未找到该学号学生信息\n");
	}
}

int del(student stu[],int n)													//单个学生信息删除函数
{
	int i,j;
	char name[20];
	char flag;																	//定义删除标志
	if(n==0)
	{	
		printf("管理系统中暂无学生信息，请返回主菜单中添加成员\n");
		return n;
	}
	else
	{
		printf("请输入要删除的学生的姓名:\n");
		scanf("%s",name);
		for(i=1;i<=n;i++)
			{
				if(strcmp(name,stu[i].name)==0)									//判断系统中是否存在要删除的姓名
				{	
					printf("已找到该学生信息,学生信息如下:\n");
					printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
					printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
					printf("请确定是否删除该学生信息:(y/n)");					//再次提醒，避免误删
					getchar();													//吃掉回车键
					scanf("%c",&flag);											//输入删除标志
					if(flag=='y'||flag=='Y')									//删除标志为真
					{	
						for(j=i;j<n;j++)
							stu[j]=stu[j+1];									//删除学生信息并且生成新的信息表
						printf("删除成功\n");
					}
					if(flag=='n'||flag=='N')									//删除标志为假
					{
						printf("删除不成功，返回主菜单\n");	
					}
					break;														//跳出循环
				}
			}
			if(i>n)
			{	
				printf("未找到该姓名学生信息\n");
				return n;														//系统现有学生人数不变
			}
			if(flag=='y'||flag=='Y')
				return --n;														//如果flag为真，则系统现有人数-1
			if(flag=='n'||flag=='N')
				return n;														//如果flag为假，则系统现有人数不变
	}
}

void paixu(student stu[],int n)													//排序函数
{
	int i,j,flag;																//flag为判断以何种情况排序
	student t;
	if(n==0)
		printf("管理系统中暂无学生信息，请返回主菜单中添加成员\n");
	else
	{
		printf("请选择按哪种方式进行排序:\n");
		printf("1:学号	2:数学成绩	3:英语成绩	4:计算机成绩	5:总分成绩\n");
		scanf("%d",&flag);
		printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t总分成绩\n");
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				{
					if(stu[i].ID>stu[j].ID&&flag==1)
						{
							t=stu[j];
							stu[j]=stu[i];
							stu[i]=t;
						}
					if(stu[i].math>stu[j].math&&flag==2)
						{
							t=stu[j];
							stu[j]=stu[i];
							stu[i]=t;
						}
					if(stu[i].Eng>stu[j].Eng&&flag==3)
						{
							t=stu[j];
							stu[j]=stu[i];
							stu[i]=t;
						}
					if(stu[i].com>stu[j].com&&flag==4)
						{
							t=stu[j];
							stu[j]=stu[i];
							stu[i]=t;
						}
					if(stu[i].com+stu[i].Eng+stu[i].math>stu[j].com+stu[j].Eng+stu[j].math&&flag==5)
						{
							t=stu[j];
							stu[j]=stu[i];
							stu[i]=t;
						}
					}
		for(i=1;i<=n;i++)
			printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
	}
}




void write_file(student stu[],int n){											//数据写入文件函数
	FILE *fp;
	int i;
	fp=fopen("D:\\student1.txt","w");
	if(fp==NULL)
	{
		printf("File cannot be opened.\n请在此路径下:(F路径)创建文件(student1.txt)");
		exit(0);
	}
	for(i=1;i<=n;i++)
			fprintf(fp,"%d\t%s\t%s\t%d\t\t%d\t\t%d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com);
	fclose(fp);
	printf("保存文件成功\n");
}

int read_file(student stu[],int *n)												//读取文件数据并输出
{	FILE *fp;
	int i=1;
	if((fp=fopen("D:\\student1.txt","r"))==NULL)
	{
		printf("File cannot be opened.\n请在此路径下:(F路径)创建文件(student1.txt)\n");
		getchar();
		exit(0);
	}
	else
	{
		printf("  学号\t\t姓名\t性别\t数学成绩\t英语成绩\t计算机成绩\t\t总分成绩\n");
		while(!feof(fp))
		{	
			fscanf(fp,"%d\t%s\t%s\t%d\t%d\t%d\t",&stu[i].ID,stu[i].name,stu[i].sex,&stu[i].math,&stu[i].Eng,&stu[i].com);
			printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
			{
				if(stu[i].ID>0)
				i++;
			}
		}
	}
	//*n=i-2;
	fclose(fp);
	printf("\n读取文件成功!\n");
	printf("\n现有%d条数据\n",i-1);
	return i-1;
}

void main()
{	
	student stu[MAX];															//定义结构体类型的数组
	int n=0,t;																	//定义该系统学生人数初值为0
	while(1)
	{	
		menu();
		scanf("%d",&t);															//选择主菜单操作
		switch(t)
		{	case 1:n=input(stu,n);system("pause");system("cls");break;			//调用学生信息输入函数并将存入系统中的学生人数赋值给n
			case 2:chaxun(stu,n);system("pause");system("cls");break;
			case 3:revise(stu,n);system("pause");system("cls");break;
			case 4:n=del(stu,n);system("pause");system("cls");break;			//调用单个学生信息删除函数并将存入系统中的学生人数赋值给n
			case 5:output(stu,n);system("pause");system("cls");break;			//调用学生信息输出函数							
			case 6:paixu(stu,n);system("pause");system("cls");break;
			case 7:write_file(stu,n);system("pause");system("cls");break;		//调用数据写入文件函数
			case 8:n=read_file(stu,&n);system("pause");system("cls");break;		//调用读取文件并在显示屏上输出函数
			case 0:back();
			default:printf("输入错误，请重新输入:");break;
		}
	}
}