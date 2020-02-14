#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<Windows.h>

#define MAX 100

int Psize = 0;		//����ü�� �ε����� ǥ���� ����
int Pnum = 0;		//��ǰ ��ȣ�� ������ ����

struct Product{
	char name[30];	//��ǰ �̸�
	char sort[10];  //��ǰ �з�
	int p_num;		//��ǰ ��ȣ
	int num;		//��ǰ ����
	int price;		//��ǰ ����
};

typedef struct Product PRODUCT;

PRODUCT prdt[MAX];
/*���� ���α׷� ���*/
void showmenu();		//�Ŵ� ���
//====================��ǰ ��� �Լ�=============================
void p_add(PRODUCT * prdt); //��ǰ ���
//====================��ǰ �˻� �Լ�=============================
void p_search_title();	//��ǰ �˻� �޴�
void p_alist(PRODUCT*prdt);			//��ǰ ��ü ��� ����
void p_name_search(PRODUCT*prdt);	//��ǰ �̸��� ã��
void p_num_search(PRODUCT*prdt);	//��ǰ ��ȣ�� ã��
void p_sort_search(PRODUCT*prdt);	//��ǰ �з��� ã��
void p_dual_search(PRODUCT*prdt);	//��ǰ ������ ã��


//====================��ǰ ���� �Լ�==============================
void p_del_title();		//��ǰ ���� �޴�

void p_name_del(PRODUCT*prdt);		//��ǰ �̸��� ����
void p_num_del(PRODUCT*prdt);		//��ǰ ��ȣ�� ����
void p_sort_del(PRODUCT*prdt);		//��ǰ �з��� ����

//====================��ǰ ���� �Լ�============================
void p_fix(PRODUCT*prdt);			//��ǰ ����

//=====================��ǰ �Ǹ�===========================
void seller(PRODUCT*prdt);

//====================���� ����� �Լ�=============================
void p_load(PRODUCT*prdt);			//��ǰ ���� �ε�
void p_save(PRODUCT*prdt);			//��ǰ ���� ����


//====================���� �Լ�==================================
enum {
	BLOCK,		    /*  0 : ���� */
	DARK_BLUE,		/*  1 : ��ο� �Ķ� */
	DARK_GREEN,     /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,		/*  4 : ��ο� ���� */
	DARK_VOILET,	/*  5 : ��ο� ���� */
	DARK_YELLOW,	/*  6 : ��ο� ��� */
	GRAY,			/*  7 : ȸ�� */
	DARK_GRAY,		/*  8 : ��ο� ȸ�� */
	BLUE,			/*  9 : �Ķ� */
	GREEN,			/* 10 : �ʷ� */
	SKY_BLUE,		/* 11 : �ϴ� */
	RED,			/* 12 : ���� */
	VOILET,			/* 13 : ���� */
	YELLOW,			/* 14 : ��� */
	WHITE,			/* 15 : ��� */
};

/* ���� �ٲٴ� �ȷ�Ʈ �Լ� */
void SetColor(short color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main()	
{
	int sel = 0;
	p_load(prdt);

	while (1)	
	{
		system("cls");
		showmenu();
		printf("\t\t");
		scanf("%d", &sel);
		switch (sel){
		case 1:			//���
			p_add(prdt);
			break;
		case 2:			//��ȸ
			p_search_title();
			break;
		case 3:			//����
			p_del_title();
			break;
		case 4:			//����
			p_fix(prdt);
			break;
		case 5:			//�Ǹ� ��� ����
			seller(prdt);
			break;
		case 0:			//����
			p_save(prdt);
			return 0;
		}
	}
}


void showmenu()			//�Ŵ� ���
{
	SetColor(YELLOW);
	printf("\t\t      ������������������������������������������������  \n");
	printf("\t\t�������������� ");

	printf(" ��ǰ ���� ���α׷� ");

	printf(" �������������� \n");
	printf("\t\t��     ������������������������������������������������     �� \n");
	printf("\t\t��                                  �� \n"); 
	printf("\t\t��          1. ���� ���            �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          2. ���� ��ȸ            �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          3. ���� ����            �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          4. ���� ����            �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          5. ��ǰ �ǸŸ��        �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          0. ��   ��              �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t������������������������������������������������������������������������ \n\n\n");
}


//====================��ǰ ��� �Լ�=============================
void p_add(PRODUCT * prdt)			//��ǰ ���
{
	char sel;
	while (1)
	{
		int sort_sel = 0;	//�з� ����
		int price_sel = 0;	//���� ����
		int price_sum = 0;	//���� ��
		int out = 0;
		system("cls");
		SetColor(WHITE);
		fflush(stdin);
		printf("\n   ��ǰ �̸� : ");
		gets(prdt[Psize].name);
		printf("\n   ��ǰ �з�  \n\n   1.��ǰ   2.����   3.����   4.����   5.��ä   6.�����Է�\n\n   ���� : ");
		scanf("%d", &sort_sel);
		switch (sort_sel)
		{
		case 1:
			strcpy(prdt[Psize].sort, "��ǰ");
			break;
		case 2:
			strcpy(prdt[Psize].sort, "����");
			break;
		case 3:
			strcpy(prdt[Psize].sort, "����");
			break;
		case 4:
			strcpy(prdt[Psize].sort, "����");
			break;
		case 5:
			strcpy(prdt[Psize].sort, "��ä");
			break;
		case 6:
			gets(prdt[Psize].sort);
			break;
		}

		printf("\n   ��ǰ ���� \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.�����Է�   0.Ȯ��\n\n");
		while (1)
		{
			printf("   ���� : ");
			scanf("%d", &price_sel);
			switch (price_sel)
			{
			case 1:
				price_sum += 100;
				break;
			case 2:
				price_sum += 500;
				break;
			case 3:
				price_sum += 1000;
				break;
			case 4:
				price_sum += 5000;
				break;
			case 5:
				price_sum += 10000;
				break;
			case 6:
				price_sum += 50000;
				break;
			case 7:
				scanf("%d", &price_sum);
				out = 1;
				break;
			case 0:
				out = 1;
				break;
			}
			if (out == 1)
				break;
			printf("   ���� ���� : %d\n", price_sum);
		}
		prdt[Psize].price = price_sum;

		printf("\n   ��ǰ ���� : ");
		scanf("%d", &prdt[Psize].num);
		prdt[Psize].p_num = ++Pnum;
		Psize++;

		fflush(stdin);
		SetColor(RED);
		printf("\n>>�� �Է��Ͻðڽ��ϱ�? Y/N\n");
		scanf("%c", &sel);
		if (sel =='n' || sel =='N')
			break;
		
		system("cls");
	}
}

//====================��ǰ �˻� �Լ�=============================
void p_search_title()	//��ǰ �˻� �޴�
{
	char sel = 0;
	int out = 0;
	while (1)
	{
		system("cls");
		SetColor(SKY_BLUE);
		printf("\t\t      ������������������������������������������������ \n");
		printf("\t\t������������  ");

		printf(" ��ǰ ���� ���α׷� ");

		printf(" ������������ \n");
		printf("\t\t��    ������������������������������������������������    �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          1. �̸��� �˻�          �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          2. ��ȣ�� �˻�          �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          3. �з��� �˻�          �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          4. ���� �˻�            �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          5. ��ü ��� ����       �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t��          0. ���� ���            �� \n");
		printf("\t\t��                                  �� \n");
		printf("\t\t������������������������������������������������������������������������  \n\n\n\n\n\n");

		fflush(stdin);
		printf("\t\t\t");
		scanf("%c", &sel);
		switch (sel)
		{
		case '1':
			p_name_search(prdt);
			break;
		case '2':
			p_num_search(prdt);
			break;
		case '3':
			p_sort_search(prdt);
			break;
		case '4':
			p_dual_search(prdt);
			break;
		case '5':
			p_alist(prdt);
			break;
		case '0':
			out = 1;
			break;
		}
		if (out == 1)
			break;
		system("cls");

	}
}
void p_alist(PRODUCT*prdt)			//��ǰ ��ü ��� ����
{
	SetColor(WHITE);
	int i = 0;
	for (i = 0; i < Psize; i++)	
	{
		printf("������������������������������������������������������������������������ \n");
		printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
		printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
		printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
		printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
		printf("   ��ǰ ���� : %d\n", prdt[i].num);			//����
		printf("������������������������������������������������������������������������ \n");
		printf("\n");
	}
	_getch();

}
void p_name_search(PRODUCT*prdt)	//��ǰ �̸��� ã��
{

	int i = 0;
	char name[20];
	SetColor(GREEN);
	printf("   �˻��� �̸� :");
	fflush(stdin);	
	gets(name);	//�˻��� ���� �Է�
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].name, name) == 0)	//�˻�
		{
			printf("������������������������������������������������������������������������ \n");
			printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
			printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
			printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
			printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
			printf("   ��ǰ ���� : %d\n", prdt[i].num);			//����
			printf("������������������������������������������������������������������������ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_num_search(PRODUCT*prdt)	//��ǰ ��ȣ�� ã��
{
	int i = 0;
	int num = 0;

	SetColor(GREEN);
	printf("   ã�� ��ǰ ��ȣ :");
	fflush(stdin);
	scanf("%d",&num);	//�˻��� ���� �Է�
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (prdt[i].p_num == num)				//�˻�
		{
			printf("������������������������������������������������������������������������ \n");
			printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
			printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
			printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
			printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
			printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
			printf("������������������������������������������������������������������������ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_sort_search(PRODUCT*prdt)	//��ǰ �з��� ã��
{
	int i = 0;
	char sort[20];
	SetColor(GREEN);
	printf("   �˻��� �з� :");
	fflush(stdin);
	gets(sort);									//�˻��� ���� �Է�

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].sort, sort) == 0)	//�˻�
		{
			printf("������������������������������������������������������������������������ \n");
			printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
			printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
			printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
			printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
			printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
			printf("������������������������������������������������������������������������ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_dual_search(PRODUCT*prdt)
{
	int count = 0;	
	int out = 0;	//���ѷ��� Ż��

	int name = 0;		//���� �Ǻ� �̸�
	int price = 0;		//��ȣ
	int sort = 0;		//�з�

	int i = 0; //�ݺ���

	//�Է¹��� ������
	char s_name[20];
	char s_sort[20];
	int s_price = 0;

	int sel = 0;
	system("cls");
	printf("\t\t      ������������������������������������������������ \n");
	printf("\t\t�������� ");

	printf("      �˻� ����     ");

	printf(" ��������\n");
	printf("\t\t��    ������������������������������������������������    �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          1. �̸�                 �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          2. ����                 �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          3. �з�                 �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          4. ����                 �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t��          0. ���� ���            �� \n");
	printf("\t\t��                                  �� \n");
	printf("\t\t������������������������������������������������������������������������ \n\n\n"); 

	while (1)
	{
		fflush(stdin);
		scanf("%d",&sel);
		switch (sel)
		{
		case 1:
			name = 1;
			count++;
			break;
		case 2:
			price = 1;
			count++;
			break;
		case 3:
			sort = 1;
			count++;
			break;
		case 4:
			out = 1;
			break;
		case 0:
			count = 4;
			break;
		}
		if (out == 1 || count == 4 ||count ==3)
			break;
	}

    if (count == 2)
	{
		if (name == 1 && price == 1)	
		{
			fflush(stdin);
			printf("\n   ��ǰ �̸� : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   ��ǰ ���� : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && s_price == prdt[i].price)
				{
					printf("������������������������������������������������������������������������ \n");
					printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
					printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
					printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
					printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
					printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
					printf("������������������������������������������������������������������������ \n");
					printf("\n");
				}
			}
			_getch();
		}
		else if (name == 1 && sort == 1)
		{
			fflush(stdin);
			printf("\n   ��ǰ �̸� : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   ��ǰ �з� : ");
			gets(s_sort);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && (strcmp(prdt[i].sort, s_sort) == 0))
				{
					printf("������������������������������������������������������������������������ \n");
					printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
					printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
					printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
					printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
					printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
					printf("������������������������������������������������������������������������ \n");
					printf("\n");
				}
			}
			_getch();
		}
		else //number ==1 && sort ==1
		{
			fflush(stdin);
			printf("\n   ��ǰ �з� : ");
			gets(s_sort);
			fflush(stdin);
			printf("\n   ��ǰ ���� : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].sort, s_sort) == 0) && s_price == prdt[i].price)
				{
					printf("������������������������������������������������������������������������ \n");
					printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
					printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
					printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
					printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
					printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
					printf("������������������������������������������������������������������������ \n");
					printf("\n");
				}
			}
			_getch();
		}
	}
	else if (count == 3)
	{
		fflush(stdin);
		printf("\n   ��ǰ �̸� : ");
		gets(s_name);
		fflush(stdin);
		printf("\n   ��ǰ �з� : ");
		gets(s_sort);
		fflush(stdin);
		printf("\n   ��ǰ ��ȣ : ");
		scanf("%d",&s_price);


		for (i = 0; i < Psize; i++)
		{
			if ((strcmp(s_sort, prdt[i].sort) == 0) && s_price == prdt[i].price && (strcmp(s_name, prdt[i].name) == 0))
			{
				printf("������������������������������������������������������������������������ \n");
				printf("   ��ǰ �̸� : %s\n", prdt[i].name);		//�̸�
				printf("   ��ǰ �з� : %s\n", prdt[i].sort);		//�з�
				printf("   ��ǰ ��ȣ : %d\n", prdt[i].p_num);		//��ȣ
				printf("   ��ǰ ���� : %d\n", prdt[i].price);		//����
				printf("   ��ǰ ���� : %d\n", prdt[i].num);		//����
				printf("������������������������������������������������������������������������ \n");
				printf("\n");
			}
		}
		_getch();
	}
}
////====================��ǰ ���� �Լ�==============================
void p_del_title()		//��ǰ ���� �޴�
{
		char sel;
		int out = 0;
		system("cls");
		while (1)
		{
			SetColor(SKY_BLUE);
			printf("\t\t      ����������������������������������������������\n");
			printf("\t\t�������� ");

			printf(" ��ǰ ���� ���α׷� ");

			printf(" ��������\n");
			printf("\t\t��    ����������������������������������������������    �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t��          1. �̸��� ����          �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t��          2. ��ȣ�� ����          �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t��          3. �з��� ����          �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t��          4. ��ü ��� ����       �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t��          0. ���� ȭ��            �� \n");
			printf("\t\t��                                  �� \n");
			printf("\t\t������������������������������������������������������������������������ \n\n\n\n\n\n");
 
			fflush(stdin);
			scanf("%c", &sel);
			switch (sel)
			{
			fflush(stdin);
			case '1':
				p_name_del(prdt);
				break;
			case '2':
				p_num_del(prdt);
				break;
			case '3':
				p_sort_del(prdt);
				break;
			case '4':
				p_alist(prdt);
				break;
			case '0':
				out = 1;
				break;
			default:
				printf("�߸� �Է��ϼ̽��ϴ�");
			}
			if (out == 1)
				break;
			system("cls");
		}
	
}
void p_name_del(PRODUCT*prdt)	//��ǰ �̸��� ����
{
	int i = 0;
	int j = 0;
	int D_count = 0;//������ ������ ����
	
	char D_name[30];
	fflush(stdin);
	SetColor(GREEN);
	printf("������ ��ǰ�� : ");
	gets(D_name);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_name,prdt[i].name)==0)
		{
			D_count++;
			
			if (i + 1 < Psize)	//�����ϰ� ���� �̸��� �迭�� �ִ��ε������� ������
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//��ȣ�� �ϳ��� �ٿ���
				}
				Psize--; // ǰ�� �ִ� ���� ����
			}
			else				//ũ�ų� ������
			{
				Psize--;	//������ �迭�̱⶧���� �ε����� �����ش� -> ���� �Է½� �ʱ�ȭ��
			}
		}
	}

}
void p_num_del(PRODUCT*prdt)		//��ǰ ��ȣ�� ����
{
	int i = 0;
	int j = 0;
	int D_count = 0;

	int num = 0;
	fflush(stdin);
	SetColor(GREEN);
	printf("\t\t������ ��ȣ : ");
	scanf("%d", &num);

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (num == prdt[i].p_num)
		{
			D_count++;
			if (i + 1 < Psize)	//�����ϰ� ���� �̸��� �迭�� �ִ��ε������� ������
			{
				for (j = i; j < Psize - 1; j++) //i���� ��ĭ���� ��ĭ�� ������
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//��ȣ�� �ϳ��� �ٿ���
				}
				Psize--; // ǰ�� �ִ� ���� ����
			}
			else				//ũ�ų� ������
			{
				Psize--;	//������ �迭�̱⶧���� �ε����� �����ش� -> ���� �Է½� �ʱ�ȭ��
			}

		}
	}
	printf("������ ��ǰ ���� : %d��", D_count);
	_getch();

}
void p_sort_del(PRODUCT*prdt)		//��ǰ �з��� ����
{
	int i = 0;
	int j = 0;
	int D_count =0;

	char D_sort[10];
	fflush(stdin);
	SetColor(GREEN);
	printf("������ �з� : ");
	gets(D_sort);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_sort, prdt[i].sort) == 0)
		{
			D_count++;
			if (i + 1 < Psize)	//�����ϰ� ���� �̸��� �迭�� �ִ��ε������� ������
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//��ȣ�� �ϳ��� �ٿ���
				}
				Psize--; // ǰ�� �ִ� ���� ����
			}
			else				//ũ�ų� ������
			{
				Psize--;	//������ �迭�̱⶧���� �ε����� �����ش� -> ���� �Է½� �ʱ�ȭ��
			}

		}
	}
	printf("������ ��ǰ ���� : %d��", D_count);
	_getch();

}
//
////====================��ǰ ���� �Լ�============================
void p_fix(PRODUCT*prdt)			//��ǰ ����
{
	int i = 0;
	int num;
	char sel;

	int sort_sel  = 0;
	int price_sel =0;
	int price_sum = 0;
	int out = 0;
	system("cls");
	SetColor(SKY_BLUE);
	printf("\t\t���������������������������� \n");
	printf("\t\t��   ��ǰ��   �� \n");
	printf("\t\t���������������������������� \n\n");
	p_alist(prdt);
	SetColor(YELLOW);
	printf("��ǰ ��ȣ �Է�  :");
	scanf("%d", &num);

	SetColor(SKY_BLUE);
	while (1)
	{
		for (i = 0; i < Psize; i++)
		{
			if (num == prdt[i].p_num)
			{
				fflush(stdin);
				printf("\n   ��ǰ �̸� : ");
				gets(prdt[i].name);
				printf("\n   ��ǰ �з�  \n\n   1.��ǰ   2.����   3.����   4.����   5.��ä   6.�����Է�\n\n   ���� : ");
				scanf("%d", &sort_sel);
				switch (sort_sel)
				{
				case 1:
					strcpy(prdt[Psize].sort, "��ǰ");
					break;
				case 2:
					strcpy(prdt[Psize].sort, "����");
					break;
				case 3:
					strcpy(prdt[Psize].sort, "����");
					break;
				case 4:
					strcpy(prdt[Psize].sort, "����");
					break;
				case 5:
					strcpy(prdt[Psize].sort, "��ä");
					break;
				case 6:
					gets(prdt[Psize].sort);
					break;
				}

				printf("\n   ��ǰ ���� \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.�����Է�   0.Ȯ��\n\n");
				while (1)
				{
					printf("   ���� : ");
					scanf("%d", &price_sel);
					switch (price_sel)
					{
					case 1:
						price_sum += 100;
						break;
					case 2:
						price_sum += 500;
						break;
					case 3:
						price_sum += 1000;
						break;
					case 4:
						price_sum += 5000;
						break;
					case 5:
						price_sum += 10000;
						break;
					case 6:
						price_sum += 50000;
						break;
					case 7:
						scanf("%d", &price_sum);
						out = 1;
						break;
					case 0:
						out = 1;
						break;
					}
					if (out == 1)
						break;
					printf("   ���� ���� : %d\n", price_sum);
				}
				printf("\n   ��ǰ ���� : ");
				scanf("%d", &prdt[i].num);
				break;
			}
		}
		fflush(stdin);
		SetColor(RED);
		printf("\n>>�� �����Ͻðڽ��ϱ�? Y/N\n");
		scanf("%c", &sel);
		if (sel == 'n' || sel == 'N')
			break;

	}
}	
//======================��ǰ �Ǹ� ���===============================
void seller(PRODUCT*prdt)
{
	int i = 0;
	int j = 0;

	char yn;
	int color_sel;	//����
	int money = 0;  //���� ��
	int p_stay[20]; //���� ���
	int sel = 0;

	for (i = 0; i < Psize; i++)
		p_stay[i] = prdt[i].num;
	while (1)
	{
		system("cls");

		for (i = 0; i < Psize; i++)
		{
			color_sel = i % 4;
			switch (color_sel)
			{
			case 0:
				SetColor(YELLOW);
				break;
			case 1:
				SetColor(SKY_BLUE);
				break;
			case 2:
				SetColor(GREEN);
				break;
			case 3:
				SetColor(WHITE);
				break;
			case 4:
				SetColor(GRAY);
				break;
			}
			if (prdt[i].num == 0)
			{
				continue;
			}
			printf("\t\t����������������������������������������������������������\n");
			printf("\t\t  %d.\t%s\t����\t:  ",i+1 ,prdt[i].name);
			for (j = 0; j < prdt[i].num; j++)
			{
				printf("�� ");
			}
			for (j = prdt[i].num; j < p_stay[i]; j++)
			{
				printf("�� ");
			}
			printf("\t\t\n  ���� : %d\n", prdt[i].price);
			printf("\t\t����������������������������������������������������������\n\n");
		}

		SetColor(WHITE);
		printf("��ȣ �Է� : ");
		//���ڸ� ����  �� ������ pnum�� ����p_stay�� �����ְ� ������ ������
		scanf("%d", &sel);
		money += prdt[sel - 1].price;
		printf("\t\t���������������������������������������������������������������� \n");
		printf("\t\t��\t���� ���� �� : %d\t �� \n", money); 
		printf("\t\t���������������������������������������������������������������� \n");

		printf("\n>>�� �����Ͻðڽ��ϱ�? Y/N\n");
		fflush(stdin);
		scanf("%c", &yn);
		prdt[sel - 1].num -= 1;
		if (yn == 'n' || yn == 'N')
			break;
		

	}
}
//====================���� ����� �Լ�=============================
void p_load(PRODUCT*prdt)			//��ǰ ���� �ε�
{
	int i = 0;
	FILE *fp1;
	fp1 = fopen("Product.txt", "rt");
	
	if (fp1 == NULL){	
		printf("���� ���� ����");
		//fp1 = fopen("Product.txt", "wt");
	}

	while (fscanf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, &prdt[i].price, &prdt[i].num, &prdt[i].p_num) != EOF) {
		i++;
	}	
	Psize = i;
	Pnum = Psize;

	fclose(fp1);
}
void p_save(PRODUCT*prdt)		//��ǰ ���� ����
{
	FILE *fp1;
	int i = 0;
	fp1 = fopen("Product.txt", "wt");

	for (i; i < Psize; i++) {
		fprintf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, prdt[i].price, prdt[i].num, prdt[i].p_num);
	}
	
	fclose(fp1);
}
