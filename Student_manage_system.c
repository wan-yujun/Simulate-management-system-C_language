#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct node{															//����ṹ������
	int ID;																		//����ѧ��
	char name[20];																//��������
	char sex[10];																//�����Ա�
	int math,Eng,com;															//�ֱ�����ѧ�ɼ���Ӣ��ɼ���������ɼ�
}student;																		//���¶���ṹ��������															

int input(student stu[],int n){										     		//ѧ����Ϣ��Ӻ���

	int i,k,j;												//flagΪ�ж�ѧ���Ƿ��ظ���־
		printf("��������ӵ�ѧ��������:");
		scanf("%d",&k);																//���k��ѧ������
		for(i=n+1;i<=k+n;i++)
		{
			printf("�����������%d��ѧ������Ϣ",i);
			printf("ѧ��:");
			scanf("%d",&stu[i].ID);
			for(j=1;i-j>=0;j++)
			{
				if(stu[i-j].ID==stu[i].ID)
				{
					do
					{
						printf("ѧ���ظ�������������:\n");
						scanf("%d",&stu[i].ID);
							for(j=1;i-j>=0;j++)
								if(stu[i-j].ID==stu[i].ID)
									break;
					}while(stu[i-j].ID==stu[i].ID);
				}
			}
			printf("����:");
			scanf("%s",stu[i].name);
			printf("�Ա�:");
			scanf("%s",stu[i].sex);
			printf("��ѧ�ɼ�:");
			scanf("%d",&stu[i].math);
			printf("Ӣ��ɼ�:");
			scanf("%d",&stu[i].Eng);
			printf("������ɼ�:");
			scanf("%d",&stu[i].com);
			printf("ѧ����Ϣ¼��ɹ�\n");
		}

		return --i;																	//����ϵͳ����ѧ������
}

void output(student stu[],int n){												//ѧ����Ϣ�������
	
	int i;
	if(n==0)
		printf("����ϵͳ������ѧ����Ϣ���뷵�����˵�����ӳ�Ա\n");
	else
	{
		printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");				
		for(i=1;i<=n;i++)
			printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
	}
}
																														
void menu()																		//���˵�����
{
	system("color 7c");
	Sleep(20);	printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	Sleep(20);	printf("|                                         ��ӭʹ�ù¶�֮��ѧ����Ϣ����ϵͳ                                                       |\n");
	Sleep(20);	printf("+--------------------------------------------------------------------------------------------------------------------------------+\n");
	Sleep(20);  printf("��ѡ�����:\n\n\n");
	Sleep(20);	printf("\t\t\t\t\t|=========================|=============================|\n");
	Sleep(20);  printf("\t\t\t\t\t|1:���ѧ����Ϣ. 	  |"); printf(" 2:��ѯѧ����Ϣ.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|3:�޸�ѧ����Ϣ.	  |"); printf(" 4:ɾ��ѧ����Ϣ.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|5:���ѧ����Ϣ.	  |"); printf(" 6:����ѧ����Ϣ.		|\n");
	Sleep(20);  printf("\t\t\t\t\t|7:�����ļ�����.	  |"); printf(" 8:��ȡ�ļ�����.		|\n");
	Sleep(20);	printf("\t\t\t\t\t|0:�˳�ϵͳ.		  |"); printf("				|\n");
	Sleep(20);	printf("\t\t\t\t\t|=========================|=============================|\n");
}

void back()																		//�˳�ϵͳ
{
	exit(0);
}

void chaxun(student stu[],int n)												//��ѯ����
{
	int i,t,k;
	char name[20];
	if(n==0)
		printf("����ϵͳ������ѧ����Ϣ���뷵�����˵�����ӳ�Ա\n");
	else
	{
		printf("��ѡ�����ַ�ʽ���в�ѯ����ѧ����Ϣ:\n");
		printf("1:��ѧ�Ž��в�ѯ\t2:���������в�ѯ\n");
		scanf("%d",&t);															//ѡ���ѯ��ʽ
		while(t!=1&&t!=2)
		{	printf("û�д�ѡ��,����������ѡ��:\n");
			scanf("%d",&t);
		}
		if(t==1)																//��ѧ�Ž��в�ѯ
		{	
			{
				printf("�������ѯѧ����ѧ��:\n");
				scanf("%d",&k);
				for(i=1;i<=n;i++)
				{
					if(k==stu[i].ID)												//�ж�ϵͳ���Ƿ���������ѧ��
					{
						printf("���ҵ���ѧ����Ϣ,ѧ����Ϣ����:\n");
						printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
						printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
						break;
					}
				}
			}
			if(i>n)
				printf("δ�ҵ���ѧ��ѧ����Ϣ\n");
		}
		if(t==2)																//���������в�ѯ
		{
			printf("�������ѯѧ��������:\n");
			scanf("%s",name);
			for(i=1;i<=n;i++)
			{
				if(strcmp(name,stu[i].name)==0)									//�ж�ϵͳ���Ƿ�������������
				{	
					printf("���ҵ���ѧ����Ϣ,ѧ����Ϣ����:\n");
					printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
					printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				//	break;
				}
			}
			if(i>n)
				printf("δ�ҵ���ѧ��ѧ����Ϣ\n");
		}
	}
}

void revise(student stu[],int n)												//����ѧ����Ϣ�޸ĺ���
{
	int i,m;
	if(n==0)
		printf("����ϵͳ������ѧ����Ϣ���뷵�����˵�����ӳ�Ա\n");
	else
	{
		printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			if(m==stu[i].ID)													//�ж�ϵͳ���Ƿ���������ѧ��	
			{
				printf("���ҵ���ѧ������ѧ����ԭ��Ϣ:\n");
				printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
				printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				printf("�������޸ĺ����Ϣ:\n");
				printf("��ѧ�ɼ�:");
				scanf("%d",&stu[i].math);
				printf("Ӣ��ɼ�:");
				scanf("%d",&stu[i].Eng);
				printf("������ɼ�:");
				scanf("%d",&stu[i].com);
				printf("�޸ĳɹ�\n");
				printf("�޸ĺ��ѧ������ϢΪ:\n");
				printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
				printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
				break;
			}
		}
		if(i>n)
			printf("δ�ҵ���ѧ��ѧ����Ϣ\n");
	}
}

int del(student stu[],int n)													//����ѧ����Ϣɾ������
{
	int i,j;
	char name[20];
	char flag;																	//����ɾ����־
	if(n==0)
	{	
		printf("����ϵͳ������ѧ����Ϣ���뷵�����˵�����ӳ�Ա\n");
		return n;
	}
	else
	{
		printf("������Ҫɾ����ѧ��������:\n");
		scanf("%s",name);
		for(i=1;i<=n;i++)
			{
				if(strcmp(name,stu[i].name)==0)									//�ж�ϵͳ���Ƿ����Ҫɾ��������
				{	
					printf("���ҵ���ѧ����Ϣ,ѧ����Ϣ����:\n");
					printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
					printf("%d\t%s\t%s\t  %d\t	  %d\t	   %d\t		  %d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com,stu[i].com+stu[i].Eng+stu[i].math);
					printf("��ȷ���Ƿ�ɾ����ѧ����Ϣ:(y/n)");					//�ٴ����ѣ�������ɾ
					getchar();													//�Ե��س���
					scanf("%c",&flag);											//����ɾ����־
					if(flag=='y'||flag=='Y')									//ɾ����־Ϊ��
					{	
						for(j=i;j<n;j++)
							stu[j]=stu[j+1];									//ɾ��ѧ����Ϣ���������µ���Ϣ��
						printf("ɾ���ɹ�\n");
					}
					if(flag=='n'||flag=='N')									//ɾ����־Ϊ��
					{
						printf("ɾ�����ɹ����������˵�\n");	
					}
					break;														//����ѭ��
				}
			}
			if(i>n)
			{	
				printf("δ�ҵ�������ѧ����Ϣ\n");
				return n;														//ϵͳ����ѧ����������
			}
			if(flag=='y'||flag=='Y')
				return --n;														//���flagΪ�棬��ϵͳ��������-1
			if(flag=='n'||flag=='N')
				return n;														//���flagΪ�٣���ϵͳ������������
	}
}

void paixu(student stu[],int n)													//������
{
	int i,j,flag;																//flagΪ�ж��Ժ����������
	student t;
	if(n==0)
		printf("����ϵͳ������ѧ����Ϣ���뷵�����˵�����ӳ�Ա\n");
	else
	{
		printf("��ѡ�����ַ�ʽ��������:\n");
		printf("1:ѧ��	2:��ѧ�ɼ�	3:Ӣ��ɼ�	4:������ɼ�	5:�ֳܷɼ�\n");
		scanf("%d",&flag);
		printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ֳܷɼ�\n");
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




void write_file(student stu[],int n){											//����д���ļ�����
	FILE *fp;
	int i;
	fp=fopen("D:\\student1.txt","w");
	if(fp==NULL)
	{
		printf("File cannot be opened.\n���ڴ�·����:(F·��)�����ļ�(student1.txt)");
		exit(0);
	}
	for(i=1;i<=n;i++)
			fprintf(fp,"%d\t%s\t%s\t%d\t\t%d\t\t%d\n",stu[i].ID,stu[i].name,stu[i].sex,stu[i].math,stu[i].Eng,stu[i].com);
	fclose(fp);
	printf("�����ļ��ɹ�\n");
}

int read_file(student stu[],int *n)												//��ȡ�ļ����ݲ����
{	FILE *fp;
	int i=1;
	if((fp=fopen("D:\\student1.txt","r"))==NULL)
	{
		printf("File cannot be opened.\n���ڴ�·����:(F·��)�����ļ�(student1.txt)\n");
		getchar();
		exit(0);
	}
	else
	{
		printf("  ѧ��\t\t����\t�Ա�\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t\t�ֳܷɼ�\n");
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
	printf("\n��ȡ�ļ��ɹ�!\n");
	printf("\n����%d������\n",i-1);
	return i-1;
}

void main()
{	
	student stu[MAX];															//����ṹ�����͵�����
	int n=0,t;																	//�����ϵͳѧ��������ֵΪ0
	while(1)
	{	
		menu();
		scanf("%d",&t);															//ѡ�����˵�����
		switch(t)
		{	case 1:n=input(stu,n);system("pause");system("cls");break;			//����ѧ����Ϣ���뺯����������ϵͳ�е�ѧ��������ֵ��n
			case 2:chaxun(stu,n);system("pause");system("cls");break;
			case 3:revise(stu,n);system("pause");system("cls");break;
			case 4:n=del(stu,n);system("pause");system("cls");break;			//���õ���ѧ����Ϣɾ��������������ϵͳ�е�ѧ��������ֵ��n
			case 5:output(stu,n);system("pause");system("cls");break;			//����ѧ����Ϣ�������							
			case 6:paixu(stu,n);system("pause");system("cls");break;
			case 7:write_file(stu,n);system("pause");system("cls");break;		//��������д���ļ�����
			case 8:n=read_file(stu,&n);system("pause");system("cls");break;		//���ö�ȡ�ļ�������ʾ�����������
			case 0:back();
			default:printf("�����������������:");break;
		}
	}
}