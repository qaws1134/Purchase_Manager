#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<Windows.h>

#define MAX 100

int Psize = 0;		//구조체의 인덱스를 표현할 변수
int Pnum = 0;		//물품 번호를 저장할 변수

struct Product{
	char name[30];	//물품 이름
	char sort[10];  //물품 분류
	int p_num;		//물품 번호
	int num;		//물품 갯수
	int price;		//물품 가격
};

typedef struct Product PRODUCT;

PRODUCT prdt[MAX];
/*관리 프로그램 기능*/
void showmenu();		//매뉴 출력
//====================물품 등록 함수=============================
void p_add(PRODUCT * prdt); //물품 등록
//====================물품 검색 함수=============================
void p_search_title();	//물품 검색 메뉴
void p_alist(PRODUCT*prdt);			//물품 전체 목록 보기
void p_name_search(PRODUCT*prdt);	//물품 이름별 찾기
void p_num_search(PRODUCT*prdt);	//물품 번호별 찾기
void p_sort_search(PRODUCT*prdt);	//물품 분류별 찾기
void p_dual_search(PRODUCT*prdt);	//물품 교차로 찾기


//====================물품 삭제 함수==============================
void p_del_title();		//물품 삭제 메뉴

void p_name_del(PRODUCT*prdt);		//물품 이름별 삭제
void p_num_del(PRODUCT*prdt);		//물품 번호별 삭제
void p_sort_del(PRODUCT*prdt);		//물품 분류별 삭제

//====================물품 수정 함수============================
void p_fix(PRODUCT*prdt);			//물품 수정

//=====================물품 판매===========================
void seller(PRODUCT*prdt);

//====================파일 입출력 함수=============================
void p_load(PRODUCT*prdt);			//물품 정보 로드
void p_save(PRODUCT*prdt);			//물품 정보 저장


//====================색깔 함수==================================
enum {
	BLOCK,		    /*  0 : 검정 */
	DARK_BLUE,		/*  1 : 어두운 파랑 */
	DARK_GREEN,     /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,		/*  4 : 어두운 빨강 */
	DARK_VOILET,	/*  5 : 어두운 보라 */
	DARK_YELLOW,	/*  6 : 어두운 노랑 */
	GRAY,			/*  7 : 회색 */
	DARK_GRAY,		/*  8 : 어두운 회색 */
	BLUE,			/*  9 : 파랑 */
	GREEN,			/* 10 : 초록 */
	SKY_BLUE,		/* 11 : 하늘 */
	RED,			/* 12 : 빨강 */
	VOILET,			/* 13 : 보라 */
	YELLOW,			/* 14 : 노랑 */
	WHITE,			/* 15 : 흰색 */
};

/* 색을 바꾸는 팔레트 함수 */
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
		case 1:			//등록
			p_add(prdt);
			break;
		case 2:			//조회
			p_search_title();
			break;
		case 3:			//삭제
			p_del_title();
			break;
		case 4:			//수정
			p_fix(prdt);
			break;
		case 5:			//판매 모드 스택
			seller(prdt);
			break;
		case 0:			//종료
			p_save(prdt);
			return 0;
		}
	}
}


void showmenu()			//매뉴 출력
{
	SetColor(YELLOW);
	printf("\t\t      ┌──────────────────────┐  \n");
	printf("\t\t┌─────┤ ");

	printf(" 물품 관리 프로그램 ");

	printf(" ├─────┐ \n");
	printf("\t\t│     └──────────────────────┘     │ \n");
	printf("\t\t│                                  │ \n"); 
	printf("\t\t│          1. 물건 등록            │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          2. 물건 조회            │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          3. 물건 삭제            │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          4. 물건 수정            │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          5. 물품 판매모드        │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          0. 종   료              │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t└──────────────────────────────────┘ \n\n\n");
}


//====================물품 등록 함수=============================
void p_add(PRODUCT * prdt)			//물품 등록
{
	char sel;
	while (1)
	{
		int sort_sel = 0;	//분류 선택
		int price_sel = 0;	//가격 선택
		int price_sum = 0;	//가격 합
		int out = 0;
		system("cls");
		SetColor(WHITE);
		fflush(stdin);
		printf("\n   물품 이름 : ");
		gets(prdt[Psize].name);
		printf("\n   물품 분류  \n\n   1.식품   2.과일   3.음류   4.과자   5.야채   6.직접입력\n\n   선택 : ");
		scanf("%d", &sort_sel);
		switch (sort_sel)
		{
		case 1:
			strcpy(prdt[Psize].sort, "식품");
			break;
		case 2:
			strcpy(prdt[Psize].sort, "과일");
			break;
		case 3:
			strcpy(prdt[Psize].sort, "음류");
			break;
		case 4:
			strcpy(prdt[Psize].sort, "과자");
			break;
		case 5:
			strcpy(prdt[Psize].sort, "야채");
			break;
		case 6:
			gets(prdt[Psize].sort);
			break;
		}

		printf("\n   물품 가격 \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.직접입력   0.확인\n\n");
		while (1)
		{
			printf("   선택 : ");
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
			printf("   현재 가격 : %d\n", price_sum);
		}
		prdt[Psize].price = price_sum;

		printf("\n   물품 수량 : ");
		scanf("%d", &prdt[Psize].num);
		prdt[Psize].p_num = ++Pnum;
		Psize++;

		fflush(stdin);
		SetColor(RED);
		printf("\n>>더 입력하시겠습니까? Y/N\n");
		scanf("%c", &sel);
		if (sel =='n' || sel =='N')
			break;
		
		system("cls");
	}
}

//====================물품 검색 함수=============================
void p_search_title()	//물품 검색 메뉴
{
	char sel = 0;
	int out = 0;
	while (1)
	{
		system("cls");
		SetColor(SKY_BLUE);
		printf("\t\t      ┌──────────────────────┐ \n");
		printf("\t\t┌────┤  ");

		printf(" 물품 관리 프로그램 ");

		printf(" ├────┐ \n");
		printf("\t\t│    └──────────────────────┘    │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          1. 이름별 검색          │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          2. 번호별 검색          │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          3. 분류별 검색          │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          4. 교차 검색            │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          5. 전체 목록 보기       │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t│          0. 이전 목록            │ \n");
		printf("\t\t│                                  │ \n");
		printf("\t\t└──────────────────────────────────┘  \n\n\n\n\n\n");

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
void p_alist(PRODUCT*prdt)			//물품 전체 목록 보기
{
	SetColor(WHITE);
	int i = 0;
	for (i = 0; i < Psize; i++)	
	{
		printf("┌──────────────────────────────────┐ \n");
		printf("   물품 이름 : %s\n", prdt[i].name);		//이름
		printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
		printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
		printf("   물품 가격 : %d\n", prdt[i].price);		//가격
		printf("   물품 갯수 : %d\n", prdt[i].num);			//갯수
		printf("└──────────────────────────────────┘ \n");
		printf("\n");
	}
	_getch();

}
void p_name_search(PRODUCT*prdt)	//물품 이름별 찾기
{

	int i = 0;
	char name[20];
	SetColor(GREEN);
	printf("   검색할 이름 :");
	fflush(stdin);	
	gets(name);	//검색할 내용 입력
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].name, name) == 0)	//검사
		{
			printf("┌──────────────────────────────────┐ \n");
			printf("   물품 이름 : %s\n", prdt[i].name);		//이름
			printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
			printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
			printf("   물품 가격 : %d\n", prdt[i].price);		//가격
			printf("   물품 갯수 : %d\n", prdt[i].num);			//갯수
			printf("└──────────────────────────────────┘ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_num_search(PRODUCT*prdt)	//물품 번호별 찾기
{
	int i = 0;
	int num = 0;

	SetColor(GREEN);
	printf("   찾는 물품 번호 :");
	fflush(stdin);
	scanf("%d",&num);	//검색할 내용 입력
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (prdt[i].p_num == num)				//검사
		{
			printf("┌──────────────────────────────────┐ \n");
			printf("   물품 이름 : %s\n", prdt[i].name);		//이름
			printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
			printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
			printf("   물품 가격 : %d\n", prdt[i].price);		//가격
			printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
			printf("└──────────────────────────────────┘ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_sort_search(PRODUCT*prdt)	//물품 분류별 찾기
{
	int i = 0;
	char sort[20];
	SetColor(GREEN);
	printf("   검색할 분류 :");
	fflush(stdin);
	gets(sort);									//검색할 내용 입력

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(prdt[i].sort, sort) == 0)	//검사
		{
			printf("┌──────────────────────────────────┐ \n");
			printf("   물품 이름 : %s\n", prdt[i].name);		//이름
			printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
			printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
			printf("   물품 가격 : %d\n", prdt[i].price);		//가격
			printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
			printf("└──────────────────────────────────┘ \n");
			printf("\n");
		}
	}
	_getch();
}
void p_dual_search(PRODUCT*prdt)
{
	int count = 0;	
	int out = 0;	//무한루프 탈출

	int name = 0;		//조건 판별 이름
	int price = 0;		//번호
	int sort = 0;		//분류

	int i = 0; //반복문

	//입력받을 변수들
	char s_name[20];
	char s_sort[20];
	int s_price = 0;

	int sel = 0;
	system("cls");
	printf("\t\t      ┌──────────────────────┐ \n");
	printf("\t\t┌──┤ ");

	printf("      검색 선택     ");

	printf(" ├──┐\n");
	printf("\t\t│    └──────────────────────┘    │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          1. 이름                 │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          2. 가격                 │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          3. 분류                 │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          4. 선택                 │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t│          0. 이전 목록            │ \n");
	printf("\t\t│                                  │ \n");
	printf("\t\t└──────────────────────────────────┘ \n\n\n"); 

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
			printf("\n   물품 이름 : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   물품 가격 : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && s_price == prdt[i].price)
				{
					printf("┌──────────────────────────────────┐ \n");
					printf("   물품 이름 : %s\n", prdt[i].name);		//이름
					printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
					printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
					printf("   물품 가격 : %d\n", prdt[i].price);		//가격
					printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
					printf("└──────────────────────────────────┘ \n");
					printf("\n");
				}
			}
			_getch();
		}
		else if (name == 1 && sort == 1)
		{
			fflush(stdin);
			printf("\n   물품 이름 : ");
			gets(s_name);
			fflush(stdin);
			printf("\n   물품 분류 : ");
			gets(s_sort);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].name, s_name) == 0) && (strcmp(prdt[i].sort, s_sort) == 0))
				{
					printf("┌──────────────────────────────────┐ \n");
					printf("   물품 이름 : %s\n", prdt[i].name);		//이름
					printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
					printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
					printf("   물품 가격 : %d\n", prdt[i].price);		//가격
					printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
					printf("└──────────────────────────────────┘ \n");
					printf("\n");
				}
			}
			_getch();
		}
		else //number ==1 && sort ==1
		{
			fflush(stdin);
			printf("\n   물품 분류 : ");
			gets(s_sort);
			fflush(stdin);
			printf("\n   물품 가격 : ");
			scanf("%d", &s_price);

			for (i = 0; i < Psize; i++)
			{
				if ((strcmp(prdt[i].sort, s_sort) == 0) && s_price == prdt[i].price)
				{
					printf("┌──────────────────────────────────┐ \n");
					printf("   물품 이름 : %s\n", prdt[i].name);		//이름
					printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
					printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
					printf("   물품 가격 : %d\n", prdt[i].price);		//가격
					printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
					printf("└──────────────────────────────────┘ \n");
					printf("\n");
				}
			}
			_getch();
		}
	}
	else if (count == 3)
	{
		fflush(stdin);
		printf("\n   물품 이름 : ");
		gets(s_name);
		fflush(stdin);
		printf("\n   물품 분류 : ");
		gets(s_sort);
		fflush(stdin);
		printf("\n   물품 번호 : ");
		scanf("%d",&s_price);


		for (i = 0; i < Psize; i++)
		{
			if ((strcmp(s_sort, prdt[i].sort) == 0) && s_price == prdt[i].price && (strcmp(s_name, prdt[i].name) == 0))
			{
				printf("┌──────────────────────────────────┐ \n");
				printf("   물품 이름 : %s\n", prdt[i].name);		//이름
				printf("   물품 분류 : %s\n", prdt[i].sort);		//분류
				printf("   물품 번호 : %d\n", prdt[i].p_num);		//번호
				printf("   물품 가격 : %d\n", prdt[i].price);		//가격
				printf("   물품 갯수 : %d\n", prdt[i].num);		//갯수
				printf("└──────────────────────────────────┘ \n");
				printf("\n");
			}
		}
		_getch();
	}
}
////====================물품 삭제 함수==============================
void p_del_title()		//물품 삭제 메뉴
{
		char sel;
		int out = 0;
		system("cls");
		while (1)
		{
			SetColor(SKY_BLUE);
			printf("\t\t      ┌─────────────────────┐\n");
			printf("\t\t┌──┤ ");

			printf(" 물품 관리 프로그램 ");

			printf(" ├──┐\n");
			printf("\t\t│    └─────────────────────┘    │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t│          1. 이름별 삭제          │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t│          2. 번호별 삭제          │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t│          3. 분류별 삭제          │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t│          4. 전체 목록 보기       │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t│          0. 이전 화면            │ \n");
			printf("\t\t│                                  │ \n");
			printf("\t\t└──────────────────────────────────┘ \n\n\n\n\n\n");
 
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
				printf("잘못 입력하셨습니다");
			}
			if (out == 1)
				break;
			system("cls");
		}
	
}
void p_name_del(PRODUCT*prdt)	//물품 이름별 삭제
{
	int i = 0;
	int j = 0;
	int D_count = 0;//삭제한 데이터 갯수
	
	char D_name[30];
	fflush(stdin);
	SetColor(GREEN);
	printf("삭제할 물품명 : ");
	gets(D_name);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_name,prdt[i].name)==0)
		{
			D_count++;
			
			if (i + 1 < Psize)	//삭제하고 싶은 이름의 배열이 최대인덱스보다 작을때
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//번호도 하나씩 줄여줌
				}
				Psize--; // 품목 최대 갯수 감소
			}
			else				//크거나 같을때
			{
				Psize--;	//마지막 배열이기때문에 인덱스를 없애준다 -> 다음 입력시 초기화됨
			}
		}
	}

}
void p_num_del(PRODUCT*prdt)		//물품 번호별 삭제
{
	int i = 0;
	int j = 0;
	int D_count = 0;

	int num = 0;
	fflush(stdin);
	SetColor(GREEN);
	printf("\t\t삭제할 번호 : ");
	scanf("%d", &num);

	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (num == prdt[i].p_num)
		{
			D_count++;
			if (i + 1 < Psize)	//삭제하고 싶은 이름의 배열이 최대인덱스보다 작을때
			{
				for (j = i; j < Psize - 1; j++) //i부터 앞칸으로 한칸씩 땡겨줌
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//번호도 하나씩 줄여줌
				}
				Psize--; // 품목 최대 갯수 감소
			}
			else				//크거나 같을때
			{
				Psize--;	//마지막 배열이기때문에 인덱스를 없애준다 -> 다음 입력시 초기화됨
			}

		}
	}
	printf("삭제한 물품 갯수 : %d개", D_count);
	_getch();

}
void p_sort_del(PRODUCT*prdt)		//물품 분류별 삭제
{
	int i = 0;
	int j = 0;
	int D_count =0;

	char D_sort[10];
	fflush(stdin);
	SetColor(GREEN);
	printf("삭제할 분류 : ");
	gets(D_sort);
	SetColor(WHITE);
	for (i = 0; i < Psize; i++)
	{
		if (strcmp(D_sort, prdt[i].sort) == 0)
		{
			D_count++;
			if (i + 1 < Psize)	//삭제하고 싶은 이름의 배열이 최대인덱스보다 작을때
			{
				for (j = 0; j < Psize - 1; j++)
				{
					prdt[i] = prdt[i + 1];
					prdt[i].num--;		//번호도 하나씩 줄여줌
				}
				Psize--; // 품목 최대 갯수 감소
			}
			else				//크거나 같을때
			{
				Psize--;	//마지막 배열이기때문에 인덱스를 없애준다 -> 다음 입력시 초기화됨
			}

		}
	}
	printf("삭제한 물품 갯수 : %d개", D_count);
	_getch();

}
//
////====================물품 수정 함수============================
void p_fix(PRODUCT*prdt)			//물품 수정
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
	printf("\t\t┌────────────┐ \n");
	printf("\t\t│   물품명   │ \n");
	printf("\t\t└────────────┘ \n\n");
	p_alist(prdt);
	SetColor(YELLOW);
	printf("물품 번호 입력  :");
	scanf("%d", &num);

	SetColor(SKY_BLUE);
	while (1)
	{
		for (i = 0; i < Psize; i++)
		{
			if (num == prdt[i].p_num)
			{
				fflush(stdin);
				printf("\n   물품 이름 : ");
				gets(prdt[i].name);
				printf("\n   물품 분류  \n\n   1.식품   2.과일   3.음류   4.과자   5.야채   6.직접입력\n\n   선택 : ");
				scanf("%d", &sort_sel);
				switch (sort_sel)
				{
				case 1:
					strcpy(prdt[Psize].sort, "식품");
					break;
				case 2:
					strcpy(prdt[Psize].sort, "과일");
					break;
				case 3:
					strcpy(prdt[Psize].sort, "음류");
					break;
				case 4:
					strcpy(prdt[Psize].sort, "과자");
					break;
				case 5:
					strcpy(prdt[Psize].sort, "야채");
					break;
				case 6:
					gets(prdt[Psize].sort);
					break;
				}

				printf("\n   물품 가격 \n\n   1. 100   2.500   3.1000   4.5000   5.10000   6.50000   7.직접입력   0.확인\n\n");
				while (1)
				{
					printf("   선택 : ");
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
					printf("   현재 가격 : %d\n", price_sum);
				}
				printf("\n   물품 수량 : ");
				scanf("%d", &prdt[i].num);
				break;
			}
		}
		fflush(stdin);
		SetColor(RED);
		printf("\n>>더 수정하시겠습니까? Y/N\n");
		scanf("%c", &sel);
		if (sel == 'n' || sel == 'N')
			break;

	}
}	
//======================물품 판매 모드===============================
void seller(PRODUCT*prdt)
{
	int i = 0;
	int j = 0;

	char yn;
	int color_sel;	//색깔
	int money = 0;  //벌은 돈
	int p_stay[20]; //남은 재고
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
			printf("\t\t┌───────────────────────────┐\n");
			printf("\t\t  %d.\t%s\t갯수\t:  ",i+1 ,prdt[i].name);
			for (j = 0; j < prdt[i].num; j++)
			{
				printf("■ ");
			}
			for (j = prdt[i].num; j < p_stay[i]; j++)
			{
				printf("□ ");
			}
			printf("\t\t\n  가격 : %d\n", prdt[i].price);
			printf("\t\t└───────────────────────────┘\n\n");
		}

		SetColor(WHITE);
		printf("번호 입력 : ");
		//숫자를 선택  그 숫자의 pnum을 빼고p_stay는 더해주고 가격을 더해줌
		scanf("%d", &sel);
		money += prdt[sel - 1].price;
		printf("\t\t┌──────────────────────────────┐ \n");
		printf("\t\t│\t현재 벌은 돈 : %d\t │ \n", money); 
		printf("\t\t└──────────────────────────────┘ \n");

		printf("\n>>더 구매하시겠습니까? Y/N\n");
		fflush(stdin);
		scanf("%c", &yn);
		prdt[sel - 1].num -= 1;
		if (yn == 'n' || yn == 'N')
			break;
		

	}
}
//====================파일 입출력 함수=============================
void p_load(PRODUCT*prdt)			//물품 정보 로드
{
	int i = 0;
	FILE *fp1;
	fp1 = fopen("Product.txt", "rt");
	
	if (fp1 == NULL){	
		printf("파일 오픈 실패");
		//fp1 = fopen("Product.txt", "wt");
	}

	while (fscanf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, &prdt[i].price, &prdt[i].num, &prdt[i].p_num) != EOF) {
		i++;
	}	
	Psize = i;
	Pnum = Psize;

	fclose(fp1);
}
void p_save(PRODUCT*prdt)		//물품 정보 저장
{
	FILE *fp1;
	int i = 0;
	fp1 = fopen("Product.txt", "wt");

	for (i; i < Psize; i++) {
		fprintf(fp1, "%s %s %d %d %d\n", &prdt[i].name, &prdt[i].sort, prdt[i].price, prdt[i].num, prdt[i].p_num);
	}
	
	fclose(fp1);
}
