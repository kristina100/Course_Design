#include"define.h" 
void color(int x)    //����            ��ɫ 
{
	if(x>=0&&x<=15)/*SetConsoleTextAttribute����
	                 ��һ���ֽڵĵ���������ǰ��ɫ������λ�����Ʊ���ɫ��*/ 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}/*GetStdHandle�������ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��    
	   �˴�Ϊ��׼������
	   	SetConsoleTextAttribute()�����Ĳ�����������̨��Ļ�������ľ��������������GENERIC_READ����Ȩ�ޣ��ַ����ԣ�*/ 
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
} 

void HideCursor()     //����           ���
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; /*CONSOLE_CURSOR_INFO�����йؿ���̨������Ϣ*/
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	/*BOOL WINAPI SetConsoleCursorInfo(_In_  HANDLE hConsoleOutput, _In_const CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
	 ָ��CONSOLE_CURSOR_INFO�ṹ��ָ�룬�ýṹΪ����̨��Ļ�������Ĺ���ṩ�µĹ淶*/
}
 
void toxy(int x, int y)      //������ƶ���     X  , Y���괦
{
	COORD pos = { x , y };   /*�����ʾһ���ַ��ڿ���̨��Ļ�ϵ�����Ķ���*/ 
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);/*SetConsoleCursorPosition��API�ж�λ���λ�õĺ���*/ 
}

Link creat()
{
	Link head;            /*��������*/
	FILE* fp;             /*�ļ�ָ��*/
	int select,count=0;   /*ch����ѡ��������,count�����ļ��ļ�¼���������߽�������*/
	char ch;              /*�����û����ַ����룬������沿�ֵġ�y,n,Y,N��*/                      
	Node* p, * r;         /*�����¼ָ�����*/
	head = (Node*)malloc(sizeof(Node));
	if (!head)
	{
		printf("\n allocate memory failure \n");/*���û�����뵽����ӡ��ʾ��Ϣ*/
		return 0; /*����������*/
	}
	head->next = NULL;
	r = head;
	fp = fopen("student.txt", "a+");
	/*��׷�ӵķ�ʽ��һ���ı��ļ����ɶ���д�������ļ������ڣ��ᴴ�����ļ�*/
	if (fp == NULL)
	{
		printf("\n\t\t\t\topen file error!\n");
		exit(0);
	}
	while(!feof(fp))
			/*һ�δ��ļ��ж�ȡһ����¼*/
	{
		p = (Node*)malloc(sizeof(Node));/*������һ���µĿռ�1*/
		if (!p)
		{
			printf("memory malloc failure!\n");/*û�������ڴ�ɹ�*/
			exit(0);/*�˳�*/
		}	
		if(fread(p,sizeof(Node),1,fp)==1)
		{
			p -> next = NULL;/*һ��ֻ��ȡһ��������ͽ���*/
			r -> next = p;   /*����һ�����*/
			r = p;	         /*r�����ƶ�һ��λ��*/
			count++;	     /*��¼������һ*/ 
		}
	}
	fclose(fp);              /*�ر��ļ�*/
	return head;
}

/*��ʽ�������ͷ*/
void printheader1()
{
	color(11);
	toxy(20,8);
	printf(END);
	toxy(28,9);
	printf("ѧ��        ����        �༶        ����    ��Ӣ    ����    �ܷ�");
	toxy(20,10);
	printf("END");
}

void printheader2()
{
	color(11);
	toxy(20,8);
	printf(END);
	toxy(28,9);
	printf("ѧ��         ����        �༶         ����    ��Ӣ    ����    �ܷ�    ����");
	toxy(20,10);
	printf(END);
}

/*<><><><><>���˵�<><><><><>*/
void menu()
{
	system("cls");     /*����*/
	HideCursor();
	color(14);
	toxy(35,6);		printf("|               ѧ����ѧ�����ϵͳ               |");
	toxy(35,7);		printf("|                                                |");
	toxy(35,8);		printf("|       1. ��Ϣ¼��           2. ��Ϣ����        |");
	toxy(35,9);		printf("|                                                |");
	toxy(35,10);	printf("|       3. ��ѯ��¼           4. ͳ����Ϣ        |");
	toxy(35,11);	printf("|                                                |");
	toxy(35,12);	printf("|       5. ɾ����Ϣ           6. �޸���Ϣ        |");
	toxy(35,13); 	printf("|                                                |");
	toxy(35,14);	printf("|       7. ����               8. ������Ϣ        |");
	toxy(35,15); 	printf("|                                                |"); 
	toxy(35,16);	printf("|       9. �����ļ�           0. �˳�ϵͳ        |");
	toxy(35,17);	printf("|                                                |");
	toxy(35,18);	printf("|                                                |");
	toxy(35,19);	printf("|                                                |");
	
}

int Tixing(Link head)
{
	if (head->next==NULL)
	{
		system("cls");
		toxy(45,8);		printf("û��ѧ����¼Ŷ,�����һЩ��Ϣ�ɣ�");
		toxy(45,9);		system("pause");
		return 1;
	}
	else 
		return 0;
}

void menu2(Link head)
{
	system("cls");
	char temp[10];	/*���������ѧ��*/
	Node*p;		    /*��ʱָ�����*/ 
	p=head->next;
	color(14);
	toxy(35,6);		printf("|               ѧ����ѧ�����ϵͳ               |");
	toxy(35,7);		printf("|                                                |");
	toxy(35,8);		printf("|               ��Ϣ��ѯ                         |");
	toxy(40,12);	printf("����������ѧ��:");
	scanf("%s",temp);
	while(p)
	{
		if(strcmp(p->data.num,temp)==0)
		{
			break;
		}
		else
			p=p->next;
	}
	if(p)
	{
		system("cls");
		printheader2();
		toxy(28,11);
		printf(NUM2,DATA2);
		toxy(20,16);
		printf("��PS:���๦���ڿ�����,�����ڴ�O(��_��)O��");
	}
	else
	{
		system("cls");
		toxy(30,11);
		printf("û�д�ѧ��,���˳�ϵͳ,������Ϣȷ�Ϻ�������^-^!");
		toxy(30,14);
		system("pause");
	}
}


/*<><><><><>��ʾ��¼<><><><><>*/
void Disp(Link head)
/*  ��ʾ����head��ͷ����ָ�룬ͷ��㲻�������Ϣ
	ָ����ָ����Ǻ��㣨����Ԫ��㣩����ѧ������Ϣ*/
{
	system("cls");
	Node* p;	/*��ʱָ�����*/ 
	int i=10;	/*���yֵ*/ 
	p = head->next;
	if(Tixing(head))
	{
		return;
	}
	printheader1();/*������ͷ��*/
	while (p)/*������������д������Ϣ*/
	{
		i+=2;
		toxy(28,i);
		printf(NUM1,DATA1);
		p = p->next;/*ֱ��������һ����㣬���*/
		toxy(20,i-1);
		printf(END);
	}
	system("pause");
}
void Disp2(Link head)
{
	system("cls");
	Node* p;
	p = head->next;
	int i=10;
	Tixing(head);
	printf("\n\n");
	printheader2();/*������ͷ��*/

	while (p)/*������������д������Ϣ*/
	{
		i+=2;
		toxy(28,i);
		printf(NUM2,DATA2);
		p = p->next;/*ֱ��������һ����㣬���*/
		toxy(20,i-1);
		printf(END);
	}
	system("pause");
}
/*��ʾ�������������Ϣ*/
void Wrong()
{
	toxy(35,24);	printf("�����������������Ŷ��");
	return;
}
/*<><><><><>�޸�<><><><><>*/
/*ϵͳ���������ѧ�Ų��ҵ��ü�¼��Ȼ����ʾ�û��޸�ѧ��֮���ֵ����Ų����޸�*/
void Modify(Link head)
{
	system("cls");
 	Node* p;	/*��ʱָ�����*/ 
	char num[20];	/*��������ѧ��*/ 
	color(11);
	if(Tixing(head))
	{
		return;
	}
	toxy(45,6);		printf("�޸�ѧ����¼");
	toxy(45,6);		printf("-----------------------------");
	toxy(45,8);		printf("ע��ѧ�Ų����޸�!");
	toxy(45,10);	printf("-----------------------------");
	toxy(45,11);	printf("������ѧ��:");
	scanf("%s",num);
	while(strlen(num)>10)
	{
		printf("�������ݴ������������룡\n");
		scanf("%s",num); 
	}
	p=head->next;
	while(p)//p��=NULL 
	{
		if(strcmp(p->data.num,num)==0)
			break;
		else
			p=p->next;
	}
	if (p)//p!=NULL 
	{
		toxy(45,12);	printf("ѧ��:%s", p->data.num);
		toxy(45,13);	printf("ԭ���֣�:%s", p->data.name);
        toxy(45,14);	
		getchar();	
		printf("������ѧ��������");gets(p->data.name);
	    toxy(45,15);	
		printf("������ѧ���༶��");gets(p->data.classes); 
		toxy(45,16);
		printf("��������ѧ�ɼ���");
		scanf("%f",&p->data.math);getchar();
		toxy(45,17);
		printf("������Ӣ��ɼ���");
		scanf("%f",&p->data.English);getchar();
		toxy(45,18);
		printf("����������ɼ���");
		scanf("%f",&p->data.physic);getchar();
		p->data.score=(p->data.physic)+(p->data.English)+(p->data.math);
		saveflag = 1;/*�޸ļ�¼  saveflag���� 1 ��δ����*/
		system("cls");
		toxy(45,12);
		printf("�޸ĳɹ���");
		Disp(head);
	}
	else
		printf(Nofind);
	system("pause");
}
/*<><><><><>��Ϣ¼��<><><><><>*/
/*����ѧ����ѧ�����ϵͳ��������Ϊ�գ����ӵ������ͷ����ʼ������ѧ����¼��㣬
  ���򽫸�ѧ���ļ�¼������������β��*/
void Input(Link head)
{
	color(11);
	Node* p, * r, * s;/*ʵ����Ӳ�������ʱ�Ľṹ�����,
					    p��������ʱ���濪�ٿռ䣬
					    s������סͷ����һλ��ַ�������Ǵ�ͷ���ĺ�һλ�����棩
					    r�������ƶ������һλ*/
	char ch, num[20];
	int flag = 0; 		/*����ظ����*/
	r = head;
	s = head->next;    /*s��סͷ����һλָ��*/ 	
	system("cls");
	//Disp(head);        /*�ȴ�ӡ�����е�ѧ����Ϣ*/
	
	while (r->next)    /*����  ����*/
		r = r->next;   /*��ָ��������������ĩβ��׼����Ӽ�¼*/
	while (1)          /*һ�ο����������¼��ֱ��������Ϊ0�ļ�¼�����Ӳ���*/
	{
		while (1)
			/*�����ţ���֤�ñ��û�б�ʹ�ã�������ı��Ϊ0�����˳���Ӳ���*/
		{
			while(1)/*��������*/
			{
				system("cls");
				toxy(45,6);
				printf("��ӭ����ѧ����ѧ�����ϵͳ\n");
				toxy(50,8);
				printf("��Ϣ¼�룺\n");
				toxy(45,10);
				printf("������ѧ�ţ��жϣ�(0 to quit):");
				scanf("%s",num);
				
				if(strlen(num)>20)
				{
					toxy(45,12);
					printf("�����������������������룺\n");
					scanf("%s",num);
				}
				else
					break;
			}
			flag = 0;
			if (strcmp(num, "0") == 0)/*��������Ϊ0�����˳���Ӳ���������������*/
			{
				return;
			}
			s = head->next;
			while (s)/*��s���ǿ�ָ��ʱ*/
				/*��ѯ�ñ���Ƿ��Ѿ����ڣ������ڣ���Ҫ����������һ��δ��ռ�õı��*/
			{
				if (strcmp(s->data.num, num) == 0)
				{
					flag = 1;
					break;
				}
				s = s->next;//û�ҵ������ƶ�����һλ
			}
			if (flag == 1)/*��ʾ�û��Ƿ���������*/
			{
				getchar();
				toxy(45,10);
				printf("��� %s �Ѿ����ڣ��Ƿ��������룿��Y/N����", num);
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')	
				{
					system("cls");
					continue;
				}
				else
					return;/*����������*/
			}
			else
			{
				break;//˵�����û�б�ʹ��
			}
		}
		p = (Node*)malloc(sizeof(Node));/*�����ڴ�ռ�*/
		if (!p)
		{
			system("cls");
			toxy(45,8);		printf("�����ڴ�ʧ�ܣ�");/*���û�����뵽����ӡ��ʾ��Ϣ*/
			toxy(45,9);		system("pause");
			return;/*����������*/
		}
		strcpy(p->data.num,num);
		toxy(45,12);	printf("������ѧ��������");
	    scanf("%s",p->data.name);
	    toxy(45,13);	printf("������ѧ���༶��");
		scanf("%s",p->data.classes); 
		toxy(45,14);	printf("��������ѧ�ɼ���");
		scanf("%f",&p->data.math);getchar();
		toxy(45,15);	printf("������Ӣ��ɼ���");
		scanf("%f",&p->data.English);getchar();
		toxy(45,16);	printf("����������ɼ���");
		scanf("%f",&p->data.physic);getchar();
		p->data.position=0;
		p->data.score=(p->data.physic)+(p->data.English)+(p->data.math);		
		p->next = NULL;/*������������β�����*/
		r->next = p;   /*r��ָ��ԭ��������һ�������ӽ��*/
		r=p;
		saveflag = 1;
	}
	return;
}
/*<><><><><>ɾ��ѧ����¼<><><><><>*/
/*ɾ��ѧ����¼�����ҵ������ѧ����¼�Ľ��
  Ȼ��ɾ���ý��*/
void Delete(Link head)
{  
	system("cls");
	Node* p, * r;	/*r���ڼ�סĿ����ǰһλ��p����Ŀ����*/ 
	char num[10],name[10],m,n;/*num����ѧ�ţ�name����������m��n��סѡ��*/ 
	int t;	//��סѡ�� 
	p=head->next;
	if(Tixing(head))
	{
		return;
	}
	system("cls");
	color(12);
	toxy(45,6);		printf("-----ѧ����ѧ�����ϵͳ-----");
	toxy(50,8);		printf("��Ϣɾ��");
	toxy(47,10);	printf("1)  ��ѧ��ɾ��");
	toxy(47,12);	printf("2)  ������ɾ��");
	toxy(47,14);	printf("�� 0 �������˵�");
	scanf("%d",&t);
	if(Tixing(head)==0)//�ж��ļ���ʼ�Ƿ������ݣ�����ִ�� ���򷵻����˵���Ϣ¼�� 
	{ 
		if (t == 1)
		{
			system("cls");
			toxy(47,10);
			printf("������ѧ��:");
			scanf("%s",num);
			while(p)//p��Ϊ�� 
			{
				if(strcmp(p->data.num,num)==0)
					break;//�ҵ������ 
				else
					p=p->next;
			}
			if (p)//�ж��Ƿ��ҵ� �ҵ���ִ�� 
			{
				system("cls");
				toxy(45,11);	printf("--------------------------");
				toxy(45,12);	printf("|    ��ȷ��Ҫɾ����    |");
				toxy(45,14);	printf("|  1.ȷ��      2.ȡ��    |");
				toxy(45,15);	printf("--------------------------");
				m=getch();
				if(m='1')
				{
					system("cls");
					r = head;
					while (r->next != p)
						r = r->next;/*û�ҵ���������*/
					r->next = p->next;/*����p*/
					free(p);/*�ͷ��ڴ�*/
					toxy(47,12);
					printf("�ɹ�ɾ����\n");
					saveflag = 1;
					Disp(head);
				}
				else if(m='2')
				{
					return;
				}
			}//end of ȷ��if 
			else
			{
				toxy(47,10);
				printf("�Բ���û���ҵ��˱�ŵ�ѧ��Ŷ\n");
			}
			system("pause");
		}//end of ѡ��if 
		else if (t == 2)
		{
			system("cls");
			toxy(47,10);
			printf("������ѧ������:");
			scanf("%s",name);
			while(p)
			{
				if(strcmp(p->data.name,name)==0)
					break;
				else
					p=p->next;
			}
			if (p)/*p!=NULL*/
			{
				system("cls");
				toxy(45,11);	printf("--------------------------");
				toxy(45,12);	printf("|    ��ȷ��Ҫɾ����    |");
				toxy(45,14);	printf("|  1.ȷ��      2.ȡ��    |");
				toxy(45,15);	printf("--------------------------");
				n=getch();
				if(n='1')
				{
					system("cls");
					r = head;
					while (r->next != p)
						r = r->next;/*û�ҵ���������*/
					r->next = p->next;/*����p*/
					free(p);/*�ͷ��ڴ�*/
					toxy(47,12);
					printf("�ɹ�ɾ����\n");
					saveflag = 1;
					Disp(head);
				}
				else if(n='2')
				{
					return;
				}
			}//end ofȷ��if 
			else
			{
				toxy(47,12);
				printf("�Բ���û���ҵ���ѧ��Ŷ\n");
			}
		}//end of ѡ�� elseif 
		else if(t == 0)
			return;
	}//end of �ⲿif
	else 
		system("pause");
	return; 
}
/*��ѯѧ����¼
���û�ִ�д˲�ѯ����ʱ��ϵͳ�������û����в�ѯ�ֶε�ѡ��
 ���ս��в�ѯ������ѧ���ļ�¼����
 ����ӡ�����ѧ����¼*/
void Inquire(Link head)
{
	system("cls");
	Node* p;
	int searchinput1,i=0,j=10,k;//i�������ǰ������j��֤toxy������yֵ��k��֤��ѯ�༶�������� 
	float Shang,Xia;	//�������� 
	char searchinput2[10],m;	//��������
	if(	Tixing(head))
	{
		return;
	}
	color(12);
	toxy(20,5);
	printf("��ܰС��ʾ��");
	color(11);
	toxy(20,6);		printf("�����¼��������δ���������������ȷ������˵�����������������O(��_��)O"); 
	toxy(35,8);		printf("|       ѧ����ѧ�����ϵͳ       |");
	toxy(35,10);	printf("|       1)�������β�ѯ           |");
	toxy(35,12);	printf("|       2)���հ༶��ѯ           |");
	toxy(35,14);	printf("|       3)���շ����β�ѯ         |");
	toxy(35,16);	printf("|       0������                  |"); 
	toxy(35,18);	printf("����������ѡ��:");
	m = getch(); 
    while(m!='1'&&m!='2'&&m!='3'&&m!='0')  
    {  
        toxy(35,18);printf("��������������޸�\n");  
        m = getch(); 
    }  
	p=head->next;
	if (m =='1')//�������β�ѯĳ���˵ĳɼ�
	{ 
		system("cls");
		toxy(35,8);
		printf("�����������ѯ������:");
		scanf("%d",&searchinput1);
		while(p)
		{
			if(p->data.position==searchinput1)
				break;
			else
				p=p->next;
		}
		if (p)
		{
			printheader2();
			toxy(28,12);	printf(NUM2,DATA2);
		}
		else
		{
			toxy(28,16);
			printf(Nofind);
		}
		system("pause");
	}
	else if(m=='2')
	{
		system("cls");
		toxy(35,6);		printf("�����������ѯ�İ༶:");
		scanf("%s",searchinput2);
		toxy(35,7);		printf("���������ѯ���ε�����:");
		scanf("%d",&k);
		printheader1();
		while(p)
		{
			if(strcmp(p->data.classes,searchinput2)==0&&i<k)
			{
				toxy(28,12+i);
				printf(NUM1,DATA1);
				i++;
			}
			p=p->next;
		}
	}
	else if(m=='3')
	{
		system("cls");
		toxy(35,8);		printf("����Ա���ã����γɼ��ܷ�300��  �����������ѯ�ķ�����:");
		toxy(35,9);		printf("����������:");	scanf("%f",&Shang);
		toxy(35,10);	printf("����������:");	scanf("%f",&Xia);
		system("cls");
		printheader1();
		while(p)
		{
			if(p->data.score<=Shang&&p->data.score>=Xia)
			{
				j+=2;
				toxy(30,j);		printf(NUM1,DATA1);
				toxy(20,j-1);	printf(END);	
			}
			p=p->next;
		}
		toxy(35,j+1);
	}
	else if(m=='0')
		return;
	system("pause");
}
/*<><><><><>ͳ��<><><><><>
----ͳ��ѧ����*/
void Tongji(Link head)
{
	system("cls");
	float sum=0, gMIN, gMAX, EMIN, EMAX, pMIN, pMAX, SMAX=0,SMIN=0;
	char cla[10],m;	//��������ֵ 
	Node *p1,*p;	//��ʱָ����� 
	color(11);
	if(Tixing(head)==0)
	{
		system("cls");
		toxy(45,6);
		printf("-----ѧ����ѧ�����ϵͳ-----");
		toxy(50,8);		printf("����ͳ��");
		toxy(45,10);	printf("1) �ܼ�");
		toxy(45,12);	printf("2) �ְ�ͳ��");
		toxy(45,14);	printf("0) ����");
		toxy(45,16);	printf("����������ѡ��:");
		m = getch(); 
  		while(m!='1'&&m!='2'&&m!='0')  
   	 	{  
        	toxy(45,16);	printf("�������,�밴����ʾ����\n");  
        	m = getch(); 
    	}  
		p=p1=head->next;
		if( m == '1')
		{
			system("cls");
			gMIN = gMAX = p1->data.math;
			EMIN = EMAX = p1->data.English;
			pMIN = pMAX = p1->data.physic;
			while(p1->next!=NULL) 
			{
				if(p1->data.math > gMAX)
					gMAX = p1->data.math;
				if(p1->data.math < gMIN) 
					gMIN = p1->data.math;
				if(p1->data.English > EMAX) 
					EMAX = p1->data.English;
				if(p1->data.English < EMIN) 
					EMIN = p1->data.English;
				if(p1->data.physic > pMAX) 
					pMAX = p1->data.physic;
				if(p1->data.physic < pMIN)
					pMIN = p1->data.physic;
				if(p1->data.score > SMAX)
					SMAX = p1->data.score;
				p1 = p1->next;
			}
			toxy(45,8);		printf("|            �ܼ�               |");
			toxy(45,10);	printf("     ��ѧ��߷�Ϊ:%4.1f        ", gMAX);
			toxy(45,11);	printf("     ��ѧ��ͷ�Ϊ:%4.1f        ", gMIN);
			toxy(45,12);	printf("     Ӣ����߷�Ϊ:%4.1f        ", EMAX);
			toxy(45,13);	printf("     Ӣ����ͷ�Ϊ:%4.1f        ", EMIN);
			toxy(45,14);	printf("     ������߷�Ϊ:%4.1f        ",pMAX);
			toxy(45,15);	printf("     ������ͷ�Ϊ:%4.1f        ",pMIN);
			toxy(45,16); 	printf("     �ܳɼ���߷�Ϊ:%4.1f      ", SMAX);
			toxy(45,17);	printf("                               "); 
			system("pause");
		}
		else if(m=='2')
		{
			system("cls");
			toxy(45,6);		printf("�ְ�ͳ��");
			toxy(45,8);		printf("����������ͳ�Ƶİ༶�ܷ�:");
			scanf("%s",cla);
			while(p->next)
			{
				if(strcmp(p->data.classes,cla)==0)
				sum+=p->data.score;
				p=p->next;
			}
			toxy(45,9);		printf("%s:",cla);
			toxy(45,10);	printf("�ܷ�:%.2f",sum);
			toxy(30,12);	printf("��PS:����ͳ�ƹ��ܸ��ڿ�����,�����ڴ�O(��_��)O��");
			system("pause");
		}
		else if(m=='0')
			return;
	}
	else
	system("pause");
	return;
}
/*<><><><><>����<><><><><>*/
void Sort(Link head)
{
	system("cls");
	Node* p, *q, *r, *s, *h1;/*pÿ����ѭ�����׽��
							   r��ѭ��������С�����ؼ��ֽ���ǰ�����
							   sָ����С�����ؼ��ֵĽ�� 
							   h1����������׽��*/ 					 
	int n=1;
	char m;
	if(Tixing(head))
	{
		return;
	}
	Disp(head);    /*��ʾ֮ǰ��¼*/	
	system("cls");
	toxy(40,10);	printf("---------------------------");
	toxy(45,12);	printf("1) ���ܷ�����");
	toxy(45,14);	printf("2) ��ѧ������");
	toxy(45,16);    printf("0) ����");
	toxy(40,18);	printf("---------------------------");
	toxy(45,20);	printf("����������ѡ��:");
 	m = getch(); 
    while(m!='1'&&m!='2'&&m!='0')  
    {  
        toxy(45,22);	printf("��������������޸�");  
        m = getch(); 
    } 

	h1 = p = (Node*)malloc(sizeof(Node));/*���ڴ����µ�ͷ���*/	
	if(!p)
	{
		printf("error!\n");
		exit(0);
	}
	if(m=='1')
	{
 		p->next=head->next;
		//head��ָ��Ľ��Ϊ���������ݵĽ�㣬��һ��������ѧ����¼
		while(p->next != NULL)
		{
			q=p->next;
			r=p;
			while(q->next != NULL)//��ѭ���ҵ���ǰ�ܷ������
			{
				if(q->next->data.score > r->next->data.score)
					r=q;//rΪ��¼��ǰ�ܷ���߽���ǰ������ָ�����
				q = q->next;//������һ�����
			}
			r->next->data.position=n;//����ѭ���󣬴�ʱr���ܷ���ߵĽ���ǰһ�����
			n++;
			if(r != p)//����ȷ��ԭ��������󣬲��Ǵ�ʱ�õ���r���ı�ָ��Ĺ�ϵ 
		  	//���ܷ����ĵĽ���뱾��ѭ�����׽�����λ�ý���
			{
				s = r->next;//sָ����С���
				r->next = s->next;//r��ָ����ָ��ǰpָ����ָ�����һ�����
				s->next = p->next; //s��ָ����ָ��ǰpָ����ָ�����һ����� 
				p->next = s;//p��ָ����ָ�򱾴�ѭ�������Ժ��ܷ����ĵĽ��
			}
			p=p->next;//������һ�����
		}//���while
		p->next=NULL;
		head->next = h1->next;//������õĸ�ԭ�������ͷ���
		Disp2(head);//��ʾ  
	}	 
	else if(m=='2')
	{
     	p->next=head->next;
		//head��ָ��Ľ��Ϊ���������ݵĽ�㣬��һ��������ѧ����¼
		while(p->next != NULL)
		{
			q=p->next;
			r=p;
			while(q->next != NULL)//��ѭ���ҵ���ǰѧ����С���
			{
				if(atoi(q->next->data.num) < atoi(r->next->data.num))
					r=q;//rΪ��¼��ǰ��С����ǰ������ָ�����
				q = q->next;//������һ�����
			}
			if(r != p)
			//��ʾԭ����㲻��ѧ����С�Ľ�㣬�ı�ָ��Ĺ�ϵ����ѧ����С�Ľ���뱾��ѭ�����׽�����λ�ý���
			{
				s = r->next;//sָ����С���
				r->next = s->next;//r��ָ����ָ��ǰpָ����ָ�����һ�����
				s->next = p->next; //s��ָ����ָ��ǰpָ����ָ�����һ����� 
				p->next = s;//p��ָ����ָ�򱾴�ѭ�������Ժ�ѧ����С�Ľ��
			}
			p=p->next;//������һ����㣬p������һ��ѭ�����׽�㡣 
		}//���while
		head->next = h1->next;//������õĸ�ԭ�������ͷ���
		Disp(head);//��ʾ  
	}
	else if(m=='0')
	return;
}
/*<><><><><>�����¼<><><><><>*/
void Save(Link head)
{
	FILE* fp;	//�ļ�ָ�� 
	Node* p;	//��ʱָ����� 
	int count = 0;
	fp = fopen("student.txt", "w");/*��ֻд�ķ�ʽ��*/ 
	if (fp == NULL)/*���ļ�ʧ��*/
	{
		printf("\t\t\t\topen file error!\n");
		exit(0);//�������� 
	}
	p = head->next;
	while(p)//һ��ֻ��һ�� 
	{
		if(fwrite(p,sizeof(Node),1,fp)==1)
		{
			p = p->next;
			count++; 
		}
		else
		{
			break;
		}
	}
	if (count > 0)
	{
		getchar(); 
		printf("\n\t\t\t�ɹ����棬�ɹ�������Ϣ%d����",count);
		system("pause");
		saveflag = 0;
	}
	else
	{
		system("cls");
		printf("û�м�¼");
		system("pause");
	}
	fclose(fp);/*�رմ��ļ�*/
}
/*<><><><><>�˳�ϵͳ<><><><><>*/ 
void quit(Link head)        
{ 
	system("cls");	
	char t, ch;//��ס���� 
	color(11);
	while(1)
	{
		if(saveflag == 1)
		{
			getchar();
			printf("\n\t\t\t\tWhether save the modified record to file?(Y/N):");
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'Y')
				Save(head);
		}
		break;
	}
	toxy(45,11);	printf("--------------------------");
	toxy(45,12);	printf("|    ��ȷ��Ҫ�˳���    |");
	toxy(45,14);	printf("|  1.ȷ��      2.ȡ��    |");
	toxy(45,15);	printf("--------------------------");
	while(1)
	{
		t=getch();         
		if(t=='1')
		{
			system("cls");
		    color(14);
			toxy(48,10);	printf("���ڰ�ȫ�˳�....");
			Sleep(1000);     //��ͣ1�� 
			system("cls");
			color(14);
			toxy(48,10);	printf("�Ѱ�ȫ�˳�ϵͳ");
			toxy(48,12);	printf("ллʹ�ã�");
			exit(0);  break; //��ֹ���� 
		}
		else if(t=='2')
		{
			menu();
			return;
		}
		else
		{
			Wrong();
		}
	}
}
/*<><><><><><>��¼<><><><><><>*/
int sign()
{
	system("cls");
	char m;	//��ס���� 
	Node*p;	//��ʱָ����� 
	color(14);
	toxy(45,10);	printf("|                                |");
	toxy(45,11);    printf("|  ��ӭ����ѧ����ѧ�����ϵͳ��  |");
	toxy(45,12);	printf("|                                |");
	toxy(45,13);	printf("|  ���ȷ��                      |");
	toxy(45,14);	printf("|                                |");
	toxy(45,15);	printf("|  1)����Ա                      |");
	toxy(45,16);	printf("|                                |"); 
	toxy(45,17);	printf("|  2)ѧ��                        |");
	toxy(45,18);    printf("|                                |");
	toxy(90,25);	printf("���ߣ��������12��������");
	m=getch(); 
	while(m!='1'&&m!='2')  
    {  
        toxy(45,19);	printf("|  ���������������������:       |");  
        toxy(45,20);	printf("|                                |");
        m = getch(); 
    }  
	if(m=='1')
	{
		char _password[10];
		do
		{
			system("cls");
			color(11);   
			char str[]="000000"; 
			toxy(45,6);
			printf("-----ѧ����������ϵͳ-----");
			toxy(45,8);
			printf("��������������룺");
			scanf("%s",_password);
			if(strcmp(str,_password)==0)   //�ж������Ƿ�������ȷ 
			{
				system("cls");
				toxy(45,8);
				printf("���ڵ�½....");
				Sleep(500);
				menu();
				return 1;
			}
			else
			{
				toxy(45,10);
				printf("���������������������:");
				Sleep(500);
			}
		}while(1);
	}
		else if(m=='2')
		{
			p=creat();
			menu2(p);
			return 0;
		}
}
/*<><><><><>�����ļ�<><><><><>*/ 
void Copy()
{
	system("cls");
	int n=0;	//��ס������� 
	char s[1000];	//ѭ����ȡԴ�ļ����ݵ�s�У���д��Ŀ���ļ���
	FILE*fp=fopen("student.txt","r");	//Դ�ļ�
	FILE*fp1=fopen("des.txt","w");	//Ŀ���ļ�
	if(!fp)
	{
		system("cls");
		toxy(45,8);		printf("�ļ���ʧ��Ŷ��");
		toxy(45,9);		system("pause");
		exit(0);
	} 
	if(!fp1)
	{
		system("cls");
		toxy(45,8);		printf("�ļ���ʧ��Ŷ��");
		toxy(45,9);		system("pause");
		exit(0);	 
	}
	while((n=fread(s,1,sizeof(s),fp))>0)
	{
		fwrite(s,1,n,fp1);
	}
	toxy(35,12);
	printf("�����ļ��ɹ���");
	fclose(fp);
	fclose(fp1);
	system("pause"); 
	return;
}
int main()
{
	Node*head;/*Link head�������άָ��*/ 
	int select,h;//�����û����룬������������ֵ 
	head=creat();
	h=sign();
	while(h)
	{
		while (1)
		{
			system("cls");
			menu();
			color(11);
			toxy(35,22);
			printf("����������ѡ��");/*��ʾ��ʾ��Ϣ*/
			scanf("%d", &select);
			switch (select)
			{
				case 1:system("cls");Input(head); break;              /*����*/
				case 2:system("cls");Disp(head); break;               /*�鿴*/
				case 3:system("cls");Inquire(head); break;            /*��ѯ*/
				case 4:system("cls");Tongji(head); break;             /*ͳ��*/
				case 5:system("cls");Delete(head); break; 
				case 6:system("cls");Modify(head);break;           
				case 7:system("cls");Sort(head); break;               /*����*/
				case 8:system("cls");Save(head);break;                /*�����¼*/
				case 9:Copy(); break;
				case 0:quit(head);   
				default:Wrong(); system("pause"); break;/*�����������������룬������ֵ����Ϊ0~9*/
			}
		}
	}
	return 0;
}

