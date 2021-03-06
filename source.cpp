#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<Windows.h>

#define MAX 100

int Psize = 0;		//掘褻羹曖 檣策蝶蒂 ル⑷й 滲熱
int Pnum = 0;		//僭ヶ 廓�ㄧ� 盪濰й 滲熱

struct Product{
	char name[30];	//僭ヶ 檜葷
	char sort[10];  //僭ヶ 碟盟
	int p_num;		//僭ヶ 廓��
	int num;		//僭ヶ 偎熱
	int price;		//僭ヶ 陛問
};

typedef struct Product PRODUCT;

PRODUCT prdt[MAX];
/*婦葬 Щ煎斜極 晦棟*/
void showmenu();		//衙景 轎溘
//====================僭ヶ 蛔煙 л熱=============================
void p_add(PRODUCT * prdt); //僭ヶ 蛔煙
//====================僭ヶ 匐儀 л熱=============================
void p_search_title();	//僭ヶ 匐儀 詭景
void p_alist(PRODUCT*prdt);			//僭ヶ 瞪羹 跡煙 爾晦
void p_name_search(PRODUCT*prdt);	//僭ヶ 檜葷滌 瓊晦
void p_num_search(PRODUCT*prdt);	//僭ヶ 廓�ㄩ� 瓊晦
void p_sort_search(PRODUCT*prdt);	//僭ヶ 碟盟滌 瓊晦
void p_dual_search(PRODUCT*prdt);	//僭ヶ 掖離煎 瓊晦


//====================僭ヶ 餉薯 л熱==============================
void p_del_title();		//僭ヶ 餉薯 詭景

void p_name_del(PRODUCT*prdt);		//僭ヶ 檜葷滌 餉薯
void p_num_del(PRODUCT*prdt);		//僭ヶ 廓�ㄩ� 餉薯
void p_sort_del(PRODUCT*prdt);		//僭ヶ 碟盟滌 餉薯

//====================僭ヶ 熱薑 л熱============================
void p_fix(PRODUCT*prdt);			//僭ヶ 熱薑

//=====================僭ヶ っ衙===========================
void seller(PRODUCT*prdt);

//====================だ橾 殮轎溘 л熱=============================
void p_load(PRODUCT*prdt);			//僭ヶ 薑爾 煎萄
void p_save(PRODUCT*prdt);			//僭ヶ 薑爾 盪濰


//====================儀梃 л熱==================================
enum {
	BLOCK,		    /*  0 : 匐薑 */
	DARK_BLUE,		/*  1 : 橫舒遴 だ嫌 */
	DARK_GREEN,     /*  2 : 橫舒遴 蟾煙 */
	DARK_SKY_BLUE,  /*  3 : 橫舒遴 ж棺 */
	DARK_RED,		/*  4 : 橫舒遴 說鬼 */
	DARK_VOILET,	/*  5 : 橫舒遴 爾塭 */
	DARK_YELLOW,	/*  6 : 橫舒遴 喻嫌 */
	GRAY,			/*  7 : �蜓� */
	DARK_GRAY,		/*  8 : 橫舒遴 �蜓� */
	BLUE,			/*  9 : だ嫌 */
	GREEN,			/* 10 : 蟾煙 */
	SKY_BLUE,		/* 11 : ж棺 */
	RED,			/* 12 : 說鬼 */
	VOILET,			/* 13 : 爾塭 */
	YELLOW,			/* 14 : 喻嫌 */
	WHITE,			/* 15 : �羃� */
};

/* 儀擊 夥紱朝 つ溯お л熱 */
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
		case 1:			//蛔煙
			p_add(prdt);
			break;
		case 2:			//褻��
			p_search_title();
			break;
		case 3:			//餉薯
			p_del_title();
			break;
		case 4:			//熱薑
			p_fix(prdt);
			break;
		case 5:			//っ衙 賅萄 蝶鷗
			seller(prdt);
			break;
		case 0:			//謙猿
			p_save(prdt);
			return 0;
		}
	}
}


void showmenu()			//衙景 轎溘
{
	SetColor(YELLOW);
	printf("\t\t      忙式式式式式式式式式式式式式式式式式式式式式式忖  \n");
	printf("\t\t忙式式式式式扣 ");

	printf(" 僭ヶ 婦葬 Щ煎斜極 ");

	printf(" 戍式式式式式忖 \n");
	printf("\t\t弛     戌式式式式式式式式式式式式式式式式式式式式式式戎     弛 \n");
	printf("\t\t弛                                  弛 \n"); 
	printf("\t\t弛          1. 僭勒 蛔煙            弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          2. 僭勒 褻��            弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          3. 僭勒 餉薯            弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          4. 僭勒 熱薑            弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          5. 僭ヶ っ衙賅萄        弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          0. 謙   猿              弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n\n\n");
}


//====================僭ヶ 蛔煙 л熱=============================
void p_add(PRODUCT * prdt)			//僭ヶ 蛔煙
{
	char sel;
	while (1)
	{
		int sort_sel = 0;	//碟盟 摹鷗
		int price_sel = 0;	//陛問 摹鷗
		int price_sum = 0;	//陛問 м
		int out = 0;
		system("cls");
		SetColor(WHITE);
		fflush(stdin);
		printf("\n   僭ヶ 檜葷 : ");
		gets(prdt[Psize].name);
		printf("\n   僭ヶ 碟盟  \n\n   1.衝ヶ   2.婁橾   3.擠盟   4.婁濠   5.撿瓣   6.霜蕾殮溘\n\n   摹鷗 : ");
		scanf("%d", &sort_sel);
		switch (sort_sel)
		{
		case 1:
			strcpy(prdt[Psize].sort, "衝ヶ");
			break;
		case 2:
			strcpy(prdt[Psize].sort, "婁橾");
			break;
		case 3:
			strcpy(prdt[Psize].sort, "擠盟");
			break;
		case 4:
			strcpy(prdt[Psize].sort, "婁濠");
			break;
		case 5:
			strcpy(prdt[Psize].sort, "撿瓣");
			break;
		case 6:
			gets(prdt[Psize].sort);
			break;
		}

		printf("\n   僭ヶ 陛問 \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.霜蕾殮溘   0.�挫垥n\n");
		while (1)
		{
			printf("   摹鷗 : ");
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
			printf("   ⑷營 陛問 : %d\n", price_sum);
		}
		prdt[Psize].price = price_sum;

		printf("\n   僭ヶ 熱榆 : ");
		scanf("%d", &prdt[Psize].num);
		prdt[Psize].p_num = ++Pnum;
		Psize++;

		fflush(stdin);
		SetColor(RED);
		printf("\n>>渦 殮溘ж衛啊蝗棲梱? Y/N\n");
		scanf("%c", &sel);
		if (sel =='n' || sel =='N')
			break;
		
		system("cls");
	}
}

//====================僭ヶ 匐儀 л熱=============================
void p_search_title()	//僭ヶ 匐儀 詭景
{
	char sel = 0;
	int out = 0;
	while (1)
	{
		system("cls");
		SetColor(SKY_BLUE);
		printf("\t\t      忙式式式式式式式式式式式式式式式式式式式式式式忖 \n");
		printf("\t\t忙式式式式扣  ");

		printf(" 僭ヶ 婦葬 Щ煎斜極 ");

		printf(" 戍式式式式忖 \n");
		printf("\t\t弛    戌式式式式式式式式式式式式式式式式式式式式式式戎    弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          1. 檜葷滌 匐儀          弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          2. 廓�ㄩ� 匐儀          弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          3. 碟盟滌 匐儀          弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          4. 掖離 匐儀            弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          5. 瞪羹 跡煙 爾晦       弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t弛          0. 檜瞪 跡煙            弛 \n");
		printf("\t\t弛                                  弛 \n");
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎  \n\n\n\n\n\n");

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
void p_alist(PRODUCT*prdt)			//僭ヶ 瞪羹 跡煙 爾晦
{
	SetColor(WHITE);
	int i = 0;
	for (i = 0; i < Psize; i++)	
	{
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
		printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
		printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
		printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
		printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
		printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);			//偎熱
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
		printf("\n");
	}
	_getch();

}
void p_name_search(PRODUCT*prdt)	//僭ヶ 檜葷滌 瓊晦
{

	int i = 0;
	char name[20];
	SetColor(GREEN);
	printf("   匐儀й 檜葷 :");
	fflush(stdin);	
	gets(name);	//匐儀й 頂辨 殮溘
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].name, name) == 0)	//匐餌
		{
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
			printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
			printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
			printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
			printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
			printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);			//偎熱
			printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
			printf("\n");
		}
	}
	_getch();
}
void p_num_search(PRODUCT*prdt)	//僭ヶ 廓�ㄩ� 瓊晦
{
	int i = 0;
	int num = 0;

	SetColor(GREEN);
	printf("   瓊朝 僭ヶ 廓�� :");
	fflush(stdin);
	scanf("%d",&num);	//匐儀й 頂辨 殮溘
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (prdt[i].p_num == num)				//匐餌
		{
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
			printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
			printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
			printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
			printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
			printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
			printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
			printf("\n");
		}
	}
	_getch();
}
void p_sort_search(PRODUCT*prdt)	//僭ヶ 碟盟滌 瓊晦
{
	int i = 0;
	char sort[20];
	SetColor(GREEN);
	printf("   匐儀й 碟盟 :");
	fflush(stdin);
	gets(sort);									//匐儀й 頂辨 殮溘

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].sort, sort) == 0)	//匐餌
		{
			printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
			printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
			printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
			printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
			printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
			printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
			printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
			printf("\n");
		}
	}
	_getch();
}
void p_dual_search(PRODUCT*prdt)
{
	int count = 0;	
	int out = 0;	//鼠и瑞Щ 驍轎

	int name = 0;		//褻勒 っ滌 檜葷
	int price = 0;		//廓��
	int sort = 0;		//碟盟

	int i = 0; //奩犒僥

	//殮溘嫡擊 滲熱菟
	char s_name[20];
	char s_sort[20];
	int s_price = 0;

	int sel = 0;
	system("cls");
	printf("\t\t      忙式式式式式式式式式式式式式式式式式式式式式式忖 \n");
	printf("\t\t忙式式扣 ");

	printf("      匐儀 摹鷗     ");

	printf(" 戍式式忖\n");
	printf("\t\t弛    戌式式式式式式式式式式式式式式式式式式式式式式戎    弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          1. 檜葷                 弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          2. 陛問                 弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          3. 碟盟                 弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          4. 摹鷗                 弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t弛          0. 檜瞪 跡煙            弛 \n");
	printf("\t\t弛                                  弛 \n");
	printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n\n\n"); 

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
			printf("\n   僭ヶ 檜葷 : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   僭ヶ 陛問 : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && s_price == prdt[i].price)
				{
					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
					printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
					printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
					printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
					printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
					printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
					printf("\n");
				}
			}
			_getch();
		}
		else if (name == 1 && sort == 1)
		{
			fflush(stdin);
			printf("\n   僭ヶ 檜葷 : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   僭ヶ 碟盟 : ");
			gets(s_sort);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && (strcmp(prdt[i].sort, s_sort) == 0))
				{
					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
					printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
					printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
					printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
					printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
					printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
					printf("\n");
				}
			}
			_getch();
		}
		else //number ==1 && sort ==1
		{
			fflush(stdin);
			printf("\n   僭ヶ 碟盟 : ");
			gets(s_sort);
			fflush(stdin);
			printf("\n   僭ヶ 陛問 : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].sort, s_sort) == 0) && s_price == prdt[i].price)
				{
					printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
					printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
					printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
					printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
					printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
					printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
					printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
					printf("\n");
				}
			}
			_getch();
		}
	}
	else if (count == 3)
	{
		fflush(stdin);
		printf("\n   僭ヶ 檜葷 : ");
		gets(s_name);
		fflush(stdin);
		printf("\n   僭ヶ 碟盟 : ");
		gets(s_sort);
		fflush(stdin);
		printf("\n   僭ヶ 廓�� : ");
		scanf("%d",&s_price);


		for (i = 0; i < Psize; i++)
		{
			if ((strcmp(s_sort, prdt[i].sort) == 0) && s_price == prdt[i].price && (strcmp(s_name, prdt[i].name) == 0))
			{
				printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
				printf("   僭ヶ 檜葷 : %s\n", prdt[i].name);		//檜葷
				printf("   僭ヶ 碟盟 : %s\n", prdt[i].sort);		//碟盟
				printf("   僭ヶ 廓�� : %d\n", prdt[i].p_num);		//廓��
				printf("   僭ヶ 陛問 : %d\n", prdt[i].price);		//陛問
				printf("   僭ヶ 偎熱 : %d\n", prdt[i].num);		//偎熱
				printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");
				printf("\n");
			}
		}
		_getch();
	}
}
////====================僭ヶ 餉薯 л熱==============================
void p_del_title()		//僭ヶ 餉薯 詭景
{
		char sel;
		int out = 0;
		system("cls");
		while (1)
		{
			SetColor(SKY_BLUE);
			printf("\t\t      忙式式式式式式式式式式式式式式式式式式式式式忖\n");
			printf("\t\t忙式式扣 ");

			printf(" 僭ヶ 婦葬 Щ煎斜極 ");

			printf(" 戍式式忖\n");
			printf("\t\t弛    戌式式式式式式式式式式式式式式式式式式式式式戎    弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t弛          1. 檜葷滌 餉薯          弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t弛          2. 廓�ㄩ� 餉薯          弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t弛          3. 碟盟滌 餉薯          弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t弛          4. 瞪羹 跡煙 爾晦       弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t弛          0. 檜瞪 �飛�            弛 \n");
			printf("\t\t弛                                  弛 \n");
			printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n\n\n\n\n\n");
 
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
				printf("澀跤 殮溘ж樟蝗棲棻");
			}
			if (out == 1)
				break;
			system("cls");
		}
	
}
void p_name_del(PRODUCT*prdt)	//僭ヶ 檜葷滌 餉薯
{
	int i = 0;
	int j = 0;
	int D_count = 0;//餉薯и 等檜攪 偎熱
	
	char D_name[30];
	fflush(stdin);
	SetColor(GREEN);
	printf("餉薯й 僭ヶ貲 : ");
	gets(D_name);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_name,prdt[i].name)==0)
		{
			D_count++;
			
			if (i + 1 < Psize)	//餉薯ж堅 談擎 檜葷曖 寡翮檜 譆渠檣策蝶爾棻 濛擊陽
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//廓�ㄤ� ж釭噶 還罹邀
				}
				Psize--; // ヶ跡 譆渠 偎熱 馬模
			}
			else				//觼剪釭 偽擊陽
			{
				Psize--;	//葆雖虞 寡翮檜晦陽僥縑 檣策蝶蒂 橈擁遽棻 -> 棻擠 殮溘衛 蟾晦�音�
			}
		}
	}

}
void p_num_del(PRODUCT*prdt)		//僭ヶ 廓�ㄩ� 餉薯
{
	int i = 0;
	int j = 0;
	int D_count = 0;

	int num = 0;
	fflush(stdin);
	SetColor(GREEN);
	printf("\t\t餉薯й 廓�� : ");
	scanf("%d", &num);

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (num == prdt[i].p_num)
		{
			D_count++;
			if (i + 1 < Psize)	//餉薯ж堅 談擎 檜葷曖 寡翮檜 譆渠檣策蝶爾棻 濛擊陽
			{
				for (j = i; j < Psize - 1; j++) //i睡攪 擅蘊戲煎 и蘊噶 雄啖邀
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//廓�ㄤ� ж釭噶 還罹邀
				}
				Psize--; // ヶ跡 譆渠 偎熱 馬模
			}
			else				//觼剪釭 偽擊陽
			{
				Psize--;	//葆雖虞 寡翮檜晦陽僥縑 檣策蝶蒂 橈擁遽棻 -> 棻擠 殮溘衛 蟾晦�音�
			}

		}
	}
	printf("餉薯и 僭ヶ 偎熱 : %d偃", D_count);
	_getch();

}
void p_sort_del(PRODUCT*prdt)		//僭ヶ 碟盟滌 餉薯
{
	int i = 0;
	int j = 0;
	int D_count =0;

	char D_sort[10];
	fflush(stdin);
	SetColor(GREEN);
	printf("餉薯й 碟盟 : ");
	gets(D_sort);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_sort, prdt[i].sort) == 0)
		{
			D_count++;
			if (i + 1 < Psize)	//餉薯ж堅 談擎 檜葷曖 寡翮檜 譆渠檣策蝶爾棻 濛擊陽
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//廓�ㄤ� ж釭噶 還罹邀
				}
				Psize--; // ヶ跡 譆渠 偎熱 馬模
			}
			else				//觼剪釭 偽擊陽
			{
				Psize--;	//葆雖虞 寡翮檜晦陽僥縑 檣策蝶蒂 橈擁遽棻 -> 棻擠 殮溘衛 蟾晦�音�
			}

		}
	}
	printf("餉薯и 僭ヶ 偎熱 : %d偃", D_count);
	_getch();

}
//
////====================僭ヶ 熱薑 л熱============================
void p_fix(PRODUCT*prdt)			//僭ヶ 熱薑
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
	printf("\t\t忙式式式式式式式式式式式式忖 \n");
	printf("\t\t弛   僭ヶ貲   弛 \n");
	printf("\t\t戌式式式式式式式式式式式式戎 \n\n");
	p_alist(prdt);
	SetColor(YELLOW);
	printf("僭ヶ 廓�� 殮溘  :");
	scanf("%d", &num);

	SetColor(SKY_BLUE);
	while (1)
	{
		for (i = 0; i < Psize; i++)
		{
			if (num == prdt[i].p_num)
			{
				fflush(stdin);
				printf("\n   僭ヶ 檜葷 : ");
				gets(prdt[i].name);
				printf("\n   僭ヶ 碟盟  \n\n   1.衝ヶ   2.婁橾   3.擠盟   4.婁濠   5.撿瓣   6.霜蕾殮溘\n\n   摹鷗 : ");
				scanf("%d", &sort_sel);
				switch (sort_sel)
				{
				case 1:
					strcpy(prdt[Psize].sort, "衝ヶ");
					break;
				case 2:
					strcpy(prdt[Psize].sort, "婁橾");
					break;
				case 3:
					strcpy(prdt[Psize].sort, "擠盟");
					break;
				case 4:
					strcpy(prdt[Psize].sort, "婁濠");
					break;
				case 5:
					strcpy(prdt[Psize].sort, "撿瓣");
					break;
				case 6:
					gets(prdt[Psize].sort);
					break;
				}

				printf("\n   僭ヶ 陛問 \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.霜蕾殮溘   0.�挫垥n\n");
				while (1)
				{
					printf("   摹鷗 : ");
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
					printf("   ⑷營 陛問 : %d\n", price_sum);
				}
				printf("\n   僭ヶ 熱榆 : ");
				scanf("%d", &prdt[i].num);
				break;
			}
		}
		fflush(stdin);
		SetColor(RED);
		printf("\n>>渦 熱薑ж衛啊蝗棲梱? Y/N\n");
		scanf("%c", &sel);
		if (sel == 'n' || sel == 'N')
			break;

	}
}	
//======================僭ヶ っ衙 賅萄===============================
void seller(PRODUCT*prdt)
{
	int i = 0;
	int j = 0;

	char yn;
	int color_sel;	//儀梃
	int money = 0;  //弊擎 絲
	int p_stay[20]; //陴擎 營堅
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
			printf("\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
			printf("\t\t  %d.\t%s\t偎熱\t:  ",i+1 ,prdt[i].name);
			for (j = 0; j < prdt[i].num; j++)
			{
				printf("﹥ ");
			}
			for (j = prdt[i].num; j < p_stay[i]; j++)
			{
				printf("﹤ ");
			}
			printf("\t\t\n  陛問 : %d\n", prdt[i].price);
			printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n\n");
		}

		SetColor(WHITE);
		printf("廓�� 殮溘 : ");
		//璋濠蒂 摹鷗  斜 璋濠曖 pnum擊 貍堅p_stay朝 渦п輿堅 陛問擊 渦п邀
		scanf("%d", &sel);
		money += prdt[sel - 1].price;
		printf("\t\t忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖 \n");
		printf("\t\t弛\t⑷營 弊擎 絲 : %d\t 弛 \n", money); 
		printf("\t\t戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎 \n");

		printf("\n>>渦 掘衙ж衛啊蝗棲梱? Y/N\n");
		fflush(stdin);
		scanf("%c", &yn);
		prdt[sel - 1].num -= 1;
		if (yn == 'n' || yn == 'N')
			break;
		

	}
}
//====================だ橾 殮轎溘 л熱=============================
void p_load(PRODUCT*prdt)			//僭ヶ 薑爾 煎萄
{
	int i = 0;
	FILE *fp1;
	fp1 = fopen("Product.txt", "rt");
	
	if (fp1 == NULL){	
		printf("だ橾 螃Ъ 褒ぬ");
		//fp1 = fopen("Product.txt", "wt");
	}

	while (fscanf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, &prdt[i].price, &prdt[i].num, &prdt[i].p_num) != EOF) {
		i++;
	}	
	Psize = i;
	Pnum = Psize;

	fclose(fp1);
}
void p_save(PRODUCT*prdt)		//僭ヶ 薑爾 盪濰
{
	FILE *fp1;
	int i = 0;
	fp1 = fopen("Product.txt", "wt");

	for (i; i < Psize; i++) {
		fprintf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, prdt[i].price, prdt[i].num, prdt[i].p_num);
	}
	
	fclose(fp1);
}
