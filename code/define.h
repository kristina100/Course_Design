/*<><><>����Ԥ����<><><><><>����ͷ�ļ�������ṹ�壬�궨��*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>      
#include<conio.h>      
#define NUM1 "%-12s%-12s%-16s%-8.1f%-8.1f%-8.1f%-8.1f"
#define NUM2 "%-12s%-12s%-16s%-9.1f%-9.1f%-9.1f%-9.1f%3d"
#define DATA1 p->data.num,p->data.name,p->data.classes,p->data.math,p->data.English,p->data.physic,p->data.math+p->data.English+p->data.physic        
#define DATA2 p->data.num,p->data.name,p->data.classes,p->data.math,p->data.English,p->data.physic,p->data.math+p->data.English+p->data.physic,p->data.position 
#define END "-----------------------------------------------------------------------------------------"  
#define Nofind/*��ʾû���ҵ���ѧ������Ϣ*/ "����~   �뿴��ܰС��ʾŶ��"                    
int saveflag = 0;/*saveflag�Ƿ���Ҫ���̵�ȫ�ֱ���,temp�ļ��Ƿ������ݵı���*/           

/*������ѧ����Ϣ�йص����ݽṹ*/
struct student 
{
	char num[20]; /*ѧ��*/
	char name[20];/*ѧ������*/
	char classes[10];  /*�༶*/
	float math;     /*��ѧ*/
	float English;  /*Ӣ��*/
	float physic;  /*����*/
	float score;    /*�ܷ�*/  
	int position; /*����*/
};

/*����ÿ����¼���߽������ݽṹ�����Ϊ node*/
typedef struct node
{
	struct student data;/*������*/
	struct node* next;  /*ָ����*/
}Node, * Link;/*NodeΪnode���͵Ľṹ������*LinkΪnode���͵�ָ�����*/

/*�Զ��庯������*/

void color(int x);
void HideCursor(); 
void toxy(int x,int y);
Link creat();
void printheader1();
void printheader2();
void menu();
void menu2(Link head);
void Disp(Link head);
void Disp2(Link head);
void Wrong();
void Copy();
void Modify(Link head);
void Input(Link head);
void Delete(Link head);
void Inquire(Link head);
void Tongji(Link head);
void Sort(Link head);
void Save(Link head);
void quit(Link head);
int Tixing();
int sign();
