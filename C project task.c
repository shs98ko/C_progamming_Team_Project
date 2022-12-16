#include <stdio.h>
#include <conio.h> // _getch() 사용을 위한 헤더 파일
#include <windows.h> // 색깔 변경 함수를 불러오기 위한 헤더 파일        // 색깔 변경 참고 사이트 ----- > https://coding-factory.tistory.com/663
#include<stdlib.h> //rand(), srand()
#include<time.h> //time()                   // windows.h , stdlib.h , time.h등의 헤더 파일도 밑의 각 참고 사이트에 나와 있음

enum {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VOILET, DARK_YELLOW, GRAY, DARK_GRAY
	, BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE
}; // 색깔 정의                                   // 색깔 변경 참고 사이트 ----- > https://coding-factory.tistory.com/663

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}   // 색깔 변경을 위한 함수                           // 색깔 변경 참고 사이트 ----- > https://coding-factory.tistory.com/663

struct locate //스도쿠 내 플레이어 위치를 구조체로 선언
{
	int x;  //플레이어 x좌표용 변수 선언
	int y;  //플레이어 y좌표용 변수 선언
};

int main(void)
{
	int escape = 0, escape2 = 0, escape3 = 0, stop = 0, c = 0, d = 0, e = 0, X = 0, Y = 0, A = 0, B = 0;
	// 반복문 탈출/조건문 회피용 변수 escape/2/3와 stop, 0인 좌표 개수 저장용 변수 A와 B와 c와 e, 맵 번호 저장 변수 d, 원래 x,y좌표값 저장 변수 X와 Y
	char begin = 0, button = 0, answer = 0, sum = 0; // 시작키를 입력받는 변수 begin, 키 입력값 저장 변수 button과 answer, 합 변수 sum -> (스도쿠 클리어 판단에 쓰일 예정)
	char number[] = { '1','2','3','4','5','6','7','8','9' }, move[] = { 'w','a','s','d' }; //입력 받는 키 종류 저장
	int listX[60] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //원래 0인 x좌표 저장용 배열 (60은 저장공간을 충분히 확보하기 위한 그냥 큰 수)
	int listY[60] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //원래 0인 y좌표 저장용 배열 (60은 저장공간을 충분히 확보하기 위한 그냥 큰 수)
	char listZ[9] = { 0,0,0,0,0,0,0,0,0 }; // 스도쿠 맵의 상태를 판단하기 위한 배열 (스도쿠 클리어를 판단하기 위해 쓰일 예정)
	char map[9][9] = {
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0}
	};                                 // 실제 실행에 쓰일 스도쿠 맵 정의
	char map1[9][9] = {
	{0,0,1,0,0,8,0,2,0},
	{7,6,0,3,1,4,8,9,5},
	{0,5,9,6,0,0,4,0,3},
	{0,1,0,0,7,6,0,4,0},
	{3,2,4,0,8,5,6,0,0},
	{0,9,0,2,0,3,0,8,1},
	{2,0,3,4,5,1,9,0,8},
	{0,8,0,7,0,2,1,0,0},
	{0,4,5,0,6,9,0,3,7}
	};                                  // 1번째 스도쿠 맵 정의
	char map2[9][9] = {
	{5,0,0,0,6,0,2,0,7},
	{9,8,6,1,2,7,0,3,0},
	{7,0,0,0,4,0,6,0,9},
	{0,0,5,4,0,8,7,0,1},
	{0,6,7,0,5,0,0,4,8},
	{8,0,9,6,0,1,0,0,3},
	{0,5,0,0,1,6,3,0,2},
	{6,0,1,7,0,0,0,5,4},
	{0,7,3,0,8,4,0,9,0}
	};                                  // 2번째 스도쿠 맵 정의
	char map3[9][9] = {
	{0,2,0,0,4,7,0,9,1},
	{0,8,0,0,9,0,6,3,0},
	{0,0,5,2,0,0,7,0,8},
	{6,9,0,0,7,8,0,5,0},
	{0,4,0,9,0,0,8,0,3},
	{7,0,8,0,5,1,2,0,0},
	{1,7,0,0,2,0,0,8,6},
	{0,0,9,6,0,0,4,0,0},
	{0,6,3,0,0,4,9,0,0}
	};                                  // 3번째 스도쿠 맵 정의
	char map4[9][9] = {
	{1,0,0,8,3,0,0,0,4},
	{8,0,7,0,0,6,9,0,2},
	{0,0,6,1,2,9,7,0,0},
	{0,6,5,0,0,1,8,2,7},
	{4,0,0,2,0,8,5,0,0},
	{2,7,8,3,0,0,1,0,9},
	{7,0,3,0,1,0,2,9,0},
	{6,0,4,0,0,2,3,0,5},
	{0,8,2,7,0,3,0,0,1}
	};                                  // 4번째 스도쿠 맵 정의
	char map5[9][9] = {
	{0,0,3,0,4,0,5,1,0},
	{9,0,0,6,0,0,0,4,7},
	{0,2,0,5,0,9,0,0,8},
	{0,0,7,0,0,0,1,8,0},
	{6,0,0,3,7,2,0,9,0},
	{5,4,0,1,0,0,3,0,0},
	{0,8,0,7,5,0,0,6,0},
	{1,0,6,0,2,3,0,0,4},
	{0,7,0,9,0,0,8,2,0}
	};                                  // 5번째 스도쿠 맵 정의

	printf("\n\n\n\n\n");
	setColor(WHITE);     // 색깔 변경 참고 사이트 ----- > https://coding-factory.tistory.com/663
	printf("                                                   *** 스도쿠 ***                \n\n\n\n\n\n");
	setColor(GREEN);
	printf("                                           이동키는 'w','a','s','d'키입니다.\n\n\n");
	setColor(DARK_YELLOW);
	printf("                                           수를 지우려면 '숫자 0'을 누르세요!\n\n\n");
	setColor(RED);
	printf("                                 입력한 수를 전체 초기화하시려면 'm'키를 누르면 됩니다!\n\n\n");
	setColor(VIOLET);
	printf("                                        맵을 바꾸고 싶다면 'p'키를 누르세요!\n\n\n");
	setColor(SKYBLUE);
	printf("                                           시작하려면 아무 키나 누르십시오!");

	begin = _getch(); // 여기에 아무 키를 입력 받으면 스도쿠를 시작할 수 있다.
	setColor(WHITE);
	system("cls"); // 출력되었던 모든 것을 지움(누적해서 스도쿠 맵이 표시되는 것을 방지하기 위한 중요한 명령어)
	// system ("cls") 참고 사이트 --> https://blog.naver.com/PostView.naver?blogId=3th_october&logNo=140166613598

	do {
		srand((unsigned int)time(NULL));       // 랜덤 함수 참고 사이트 ---> https://coding-factory.tistory.com/666
		A = (rand() % 5) + 1;  // 맵 고르기
		if (A == d)   // 이전 맵과 똑같은 맵을 불러오지 못하게 하기 위한 조건문
			continue;
		d = A;

		switch (A)  // 스도쿠 맵 5개 중 랜덤으로 맵 뽑기
		{
		case 1:     // 1번째 스도쿠 맵이 선택된 경우
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map1[i][j];
				}
			}
			break;
		case 2:     // 2번째 스도쿠 맵이 선택된 경우
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map2[i][j];
				}
			}
			break;
		case 3:     // 3번째 스도쿠 맵이 선택된 경우
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map3[i][j];
				}
			}
			break;
		case 4:     // 4번째 스도쿠 맵이 선택된 경우
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map4[i][j];
				}
			}
			break;
		case 5:     // 5번째 스도쿠 맵이 선택된 경우
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map5[i][j];
				}
			}
			break;
		}


		for (int i = 0; i <= 8;i++)  //스도쿠 맵에서 원래 0이었던 위치(x,y)를 각각 저장하기 위한 중첩 반복문
		{
			for (int j = 0;j <= 8;j++)
			{
				if (map[i][j] == 0)
				{
					listX[c] = i; // 해당 스도쿠 맵의 0인 부분의 x좌표 저장
					listY[c] = j; // 해당 스도쿠 맵의 0인 부분의 y좌표 저장
					c += 1;       // 현재 스도쿠 맵의 0인 좌표 개수를 지속적으로 저장
				}
			}
		}
		B = c;  // 0인 좌표 개수를 B에 저장 (밑의 코드에서 개수 측정용 변수로 사용 예정)
		e = c;  // 0인 좌표 개수를 e에 저장 (밑의 코드에서 개수 측정용 변수로 사용 예정)
		c = 0;  // 나중에 다시 쓰일 수도 있으니 원래 초기값이었던 0으로 변경

		struct locate player = { 0,0 }; //플레이어 위치 초기값 선언 (초기값이 일단 있어야 오류 발생 확률이 줄어듬)

		for (int i = 0;i <= 8;i++)  //좌측 상단부터 0행의 0열->0행의 1열->0행의 2열...순으로 0인지의 여부를 판단하고 가장 먼저 찾은 0위치에 플레이어 위치 선언
		{
			for (int j = 0;j <= 8;j++)
			{
				if (map[i][j] != 0)  // 0이 아니면 플레이어 좌표를 변경
					player.y += 1;
				else                 // 0이 맞다면 해당 좌표를 플레이어 좌표로 설정
				{
					escape3 = 1; //escape3 값을 변경 (더 이상의 반복을 차단하기 위함)
					break;
				}
			}
			if (escape3 == 1)             //중첩 반복문을 한번에 탈출하기 위한 조건문 (탈출용 변수 escape3 사용)
				break;
			if (player.x != 8)            //해당 행의 모든 열이 0이 아니었다면 다음 행으로 넘어감
				player.x += 1;
		}
		escape3 = 0; // 반복문 탈출/조건문 회피용 변수는 언제 다시 쓰일지 모르니 원래 값으로 다시 변경해야 한다.

		do
		{
			system("cls");
			switch (button) // 버튼 키가 이동키 w,a,s,d 중 하나일 경우
			{
			case 'w': // w 키를 입력받았다면 위로 이동하는 것을 구현 (단, 맨 위에 있다면 앞 열의 마지막 행으로 이동 | * 있던 곳이 (0,0)이었을 경우에는 스위치문 실행 X)
				X = player.x;  //기존의 x좌표 저장
				Y = player.y;  //기존의 y좌표 저장
				if (player.y != 0) //기존의 y좌표가 0이 아닐 경우 - (조건 1)
				{
					if (player.x != 0) //기존의 x좌표가 0이 아닐 경우 - (조건 2)
					{
						for (int i = 1;i <= X;i++) // (조건 1) && (조건 2) 모두에 해당하는 경우
						{
							if (map[player.x - i][player.y] == 0)  // 조사한 위의 좌표의 값이 0이라면 해당 (x,y)를 플레이어 좌표로 설정
							{
								player.x -= i;
								stop = 1;       // 이 경우, 다른 조건문이나 반복문을 또 거치면 안 되니 반복문 회피용 변수 stop값 변경 
								break;
							}
							else if (map[player.x - i][player.y] != 0)
							{
								for (int g = 0;g < e;g++)
								{
									if (player.x - i == listX[g] && player.y == listY[g]) // 조사한 좌표가 0이 아니지만 원래 0이었던 좌표면 그 좌표로 이동
									{
										player.x -= i;
										stop = 1;
										break;
									}
								}
								if (stop == 1)
									break;
							}
							if (i == X)  // 해당 열의 맨 위까지 다 검사했는데도 0이 없는 경우 (= 마지막 반복일 경우)
								player.x = 0;   // (조건 1) && (조건 2)의 경우 중 이 경우에 한해서만 10줄 밑의 조건문 실행 (특수 케이스) 
							if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0) // (0,0)까지 전부 0이 아닌 경우 -> w키로 이동이 불가
							{
								player.x = X;  // 기존의 x좌표로 다시 저장
								player.y = Y;  // 기존의 y좌표로 다시 저장
								stop = 2;     // stop값을 2로 변경 -> 밑의 w키에 대한 조건문의 실행을 차단
								break;        // 이 조건문의 결론: w키를 눌러도 이동하지 않고 기존의 좌표에 가만히 정지 (밑의 w키에 대한 조건/반복문 실행 X
							}
						}
					}
					if (player.x == 0 && stop == 0) // 원래 x좌표가 0이었거나 (조건 2)의 (특수 케이스)에 한해서만 실행
					{
						for (int w = 1;w <= Y;w++)
						{
							player.x = 8;
							player.y -= 1;
							for (int j = 0;j <= 8;j++)
							{
								if (map[player.x][player.y] == 0)  // 조사한 좌표가 0일 경우, 해당 좌표로 설정, w에 대한 스위치문을 완전히 탈출 - (A)
								{
									stop = 3;
									break;
								}
								else if (j <= 7)
								{
									for (int g = 0;g < e;g++)
									{
										if (player.x == listX[g] && player.y == listY[g]) // 0은 아니지만 해당 좌표가 원래 0이었던 좌표면 그곳으로 이동
										{
											stop = 3;
											break;
										}
									}
									if (stop == 3)
										break;
									player.x -= 1;
									stop = 4;
								}
								if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0) //(0,0)까지 0인 좌표가 하나도 없는 경우
								{
									player.x = X;  //기존의 x좌표 값 다시 저장
									player.y = Y;  //기존의 y좌표 값 다시 저장
								}
							}
							if (stop == 3)    // 위의 경우 중 (A)의 경우에 한해서만 반복문 탈출
								break;
						}
					}
				}
				if (player.y == 0 && stop == 0) // 플레이어 y좌표가 0인 경우 (= (조건 1)이 아닌 경우)
				{
					for (int i = 1;i <= X;i++)
					{
						if (map[player.x - i][player.y] == 0) // 조사한 좌표가 0인 경우, 조사한 해당 좌표로 이동
						{
							player.x -= i;
							break;
						}
						else
						{
							for (int g = 0;g < e;g++)
							{
								if (player.x - i == listX[g] && player.y == listY[g]) //0이 아니지만 해당 좌표가 원래 0이었던 경우 (그 좌표로 이동)
								{
									player.x -= i;
									stop = 5;
									break;
								}
							}
							if (stop == 5)
								break;
						}
					}
				}
				stop = 0; // 반복문 탈출/조건문 회피용 변수는 언제 다시 쓰일지 모르니 원래의 값으로 다시 변경해야 한다.
				break;
			case 'a':  // a 키를 입력받으면 왼쪽으로 이동하는 것을 구현 (단, 맨 왼쪽에 있다면 앞 행의 마지막 열로 이동 | * 있던 곳이 (0,0)이었을 경우에는 스위치문 실행 X)
				X = player.x;
				Y = player.y;
				if (player.x != 0) // 여기는 위의 w와 원리는 동일하니 설명 생략 (w와 다른 점은 대부분의 코드에서 x,y만 서로 바뀜)
				{
					if (player.y != 0)
					{
						for (int i = 1;i <= Y;i++)
						{
							if (map[player.x][player.y - i] == 0)
							{
								player.y -= i;
								stop = 1;
								break;
							}
							else if (map[player.x][player.y - i] != 0)
							{
								for (int g = 0;g < e;g++)
								{
									if (player.x == listX[g] && player.y - i == listY[g])
									{
										player.y -= i;
										stop = 1;
										break;
									}
								}
								if (stop == 1)
									break;
							}
							if (i == Y)
								player.y = 0;
							if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0)
							{
								player.x = X;
								player.y = Y;
								stop = 2;
								break;
							}
						}
					}
					if (player.y == 0 && stop == 0)
					{
						for (int w = 1;w <= X;w++)
						{
							player.y = 8;
							player.x -= 1;
							for (int j = 0;j <= 8;j++)
							{
								if (map[player.x][player.y] == 0)
								{
									stop = 3;
									break;
								}
								else if (j <= 7)
								{
									for (int g = 0;g < e;g++)
									{
										if (player.x == listX[g] && player.y == listY[g])
										{
											stop = 3;
											break;
										}
									}
									if (stop == 3)
										break;
									player.y -= 1;
									stop = 4;
								}
								if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0)
								{
									player.x = X;
									player.y = Y;
								}
							}
							if (stop == 3)
								break;
						}
					}
				}
				if (player.x == 0 && stop == 0)
				{
					for (int i = 1;i <= Y;i++)
					{
						if (map[player.x][player.y - i] == 0)
						{
							player.y -= i;
							break;
						}
						else
						{
							for (int g = 0;g < e;g++)
							{
								if (player.x == listX[g] && player.y - i == listY[g])
								{
									player.y -= i;
									stop = 5;
									break;
								}
							}
							if (stop == 5)
								break;
						}
					}
				}
				stop = 0;
				break;
			case 's': // s 키를 입력받으면 아래로 이동하는 것을 구현 (단, 맨 아래에 있다면 뒷 열의 첫 행으로 이동 | * 있던 곳이 (8,8)이었을 경우에는 스위치문 실행 X)
				X = player.x;
				Y = player.y;
				if (player.y != 8)  // 여기는 위의 w,a와 원리는 동일하니 설명 생략 (w와 다른 점은 대부분의 코드에서 0과 8이 서로 바뀜)
				{
					if (player.x != 8)
					{
						for (int i = 1;i <= 8 - X;i++)
						{
							if (map[player.x + i][player.y] == 0)
							{
								player.x += i;
								stop = 1;
								break;
							}
							else if (map[player.x + i][player.y] != 0)
							{
								for (int g = 0;g < e;g++)
								{
									if (player.x + i == listX[g] && player.y == listY[g])
									{
										player.x += i;
										stop = 1;
										break;
									}
								}
								if (stop == 1)
									break;
							}
							if (i == 8 - X)
								player.x = 8;
							if (player.x == 8 && player.y == 8 && map[player.x][player.y] != 0)
							{
								player.x = X;
								player.y = Y;
								stop = 2;
								break;
							}
						}
					}
					if (player.x == 8 && stop == 0)
					{
						for (int w = 1;w <= 8 - Y;w++)
						{
							player.x = 0;
							player.y += 1;
							for (int j = 0;j <= 8;j++)
							{
								if (map[player.x][player.y] == 0)
								{
									stop = 3;
									break;
								}
								else if (j <= 7)
								{
									for (int g = 0;g < e;g++)
									{
										if (player.x == listX[g] && player.y == listY[g])
										{
											stop = 3;
											break;
										}
									}
									if (stop == 3)
										break;
									player.x += 1;
									stop = 4;
								}
								if (player.x == 8 && player.y == 8 && map[player.x][player.y] != 0)
								{
									player.x = X;
									player.y = Y;
								}
							}
							if (stop == 3)
								break;
						}
					}
				}
				if (player.y == 8 && stop == 0)
				{
					for (int i = 1;i <= 8 - X;i++)
					{
						if (map[player.x + i][player.y] == 0)
						{
							player.x += i;
							break;
						}
						else
						{
							for (int g = 0;g < e;g++)
							{
								if (player.x + i == listX[g] && player.y == listY[g])
								{
									player.x += i;
									stop = 5;
									break;
								}
							}
							if (stop == 5)
								break;
						}
					}
				}
				stop = 0;
				break;
			case 'd': // d 키를 입력받으면 오른쪽으로 이동하는 것을 구현 (단, 맨 오른쪽에 있다면 뒷 행의 첫 열로 이동 | * 있던 곳이 (8,8)이었을 경우에는 스위치문 실행 X)
				X = player.x;
				Y = player.y;
				if (player.x != 8)  // 여기는 위의 w,a,s와 원리는 동일하니 설명 생략 (w와 다른 점은 대부분의 코드에서 x,y가 서로 바뀌고 0과 8이 서로 바뀜)
				{
					if (player.y != 8)
					{
						for (int i = 1;i <= 8 - Y;i++)
						{
							if (map[player.x][player.y + i] == 0)
							{
								player.y += i;
								stop = 1;
								break;
							}
							else if (map[player.x][player.y + i] != 0)
							{
								for (int g = 0;g < e;g++)
								{
									if (player.x == listX[g] && player.y + i == listY[g])
									{
										player.y += i;
										stop = 1;
										break;
									}
								}
								if (stop == 1)
									break;
							}
							if (i == 8 - Y)
								player.y = 8;
							if (player.x == 8 && player.y == 8 && map[player.x][player.y] != 0)
							{
								player.x = X;
								player.y = Y;
								stop = 2;
								break;
							}
						}
					}
					if (player.y == 8 && stop == 0)
					{
						for (int w = 1;w <= 8 - X;w++)
						{
							player.y = 0;
							player.x += 1;
							for (int j = 0;j <= 8;j++)
							{
								if (map[player.x][player.y] == 0)
								{
									stop = 3;
									break;
								}
								else if (j <= 7)
								{
									for (int g = 0;g < e;g++)
									{
										if (player.x == listX[g] && player.y == listY[g])
										{
											stop = 3;
											break;
										}
									}
									if (stop == 3)
										break;
									player.y += 1;
									stop = 4;
								}
								if (player.x == 8 && player.y == 8 && map[player.x][player.y] != 0)
								{
									player.x = X;
									player.y = Y;
								}
							}
							if (stop == 3)
								break;
						}
					}
				}
				if (player.x == 8 && stop == 0)
				{
					for (int i = 1;i <= 8 - Y;i++)
					{
						if (map[player.x][player.y + i] == 0)
						{
							player.y += i;
							break;
						}
						else
						{
							for (int g = 0;g < e;g++)
							{
								if (player.x == listX[g] && player.y + i == listY[g])
								{
									player.y += i;
									stop = 5;
									break;
								}
							}
							if (stop == 5)
								break;
						}
					}
				}
				stop = 0;
				break;

			}  // *참고로 기존에 플레이어 좌표가 (0,0)일 때는 w, a 로의 이동은 불가, (8,8)일 때는 s, d 로의 이동은 불가

			printf("                            ┌────────────────────┰────────────────────┰─────────────────────┐\n");
			printf("                            │                    │                    │                     │\n");
			for (int i = 0; i <= 8; i++)
			{
				printf("                            "); // 스도쿠 맵을 가운데에 표시하기 위한 대량의 공백 (밑의 작대기 출력 부분에도 동일하게 적용)
				printf("│");       // 스도쿠 맵의 테두리를 위한 작대기
				for (int j = 0;j <= 8;j++)     // ***** 스도쿠 맵 출력을 위한 반복문 (이 반복문을 통해 우리가 스도쿠 맵을 볼 수 있음) *****
				{
					if (map[i][j] == 0)  // 맵에서 현재 0의 값을 갖는 좌표 출력 - (가)
					{
						if (i == player.x && j == player.y) // (가) 조건이면서 플레이어 좌표일 때 출력
						{
							if (j == 2 || j == 5)
							{
								setColor(GRAY);
								printf("  ___ ");
								setColor(WHITE);
								printf("│");
							}
							else
							{
								setColor(GRAY);
								printf("  ___  ");
								setColor(WHITE);
							}
						}
						else // 그냥 (가) 조건일 때 출력
						{
							if (j == 2 || j == 5)
								printf("      │");
							else
								printf("       ");
						}
					}
					else if (map[i][j] != 0) // 맵에서 이미 수(1~9)로 채워져 있는 좌표 출력 - (나)
					{
						if (i == player.x && j == player.y) // (나) 조건이면서 플레이어 좌표일 때 출력
						{
							if (j == 2 || j == 5)
							{
								setColor(GRAY);
								printf("  _");
								setColor(GREEN);
								printf("%d", map[i][j]);
								setColor(GRAY);
								printf("_ ");
								setColor(WHITE);
								printf("│");
							}
							else
							{
								setColor(GRAY);
								printf("  _");
								setColor(GREEN);
								printf("%d", map[i][j]);
								setColor(GRAY);
								printf("_  ");
								setColor(WHITE);
							}
						}
						else  // 그냥 (나) 조건일 때 출력
						{
							for (int k = 0;k < e;k++)  // 그냥 (나) 조건인데 원래 0이었던 좌표일 때 출력 - (다)
							{
								if (i == listX[k] && j == listY[k])
								{
									setColor(GREEN);
									printf("   %d  ", map[i][j]);
									setColor(WHITE);
									if (j == 2 || j == 5)
										printf("│");
									else
										printf(" ");
									escape3 = 1;
									break;
								}
							}
							if ((j == 2 || j == 5) && escape3 == 0) // (나) 조건이면서 (다) 조건이 아닐 때 출력-1 (테두리 출력 때문에 1,2로 나뉨)
								printf("   %d  │", map[i][j]);
							else if (j != 2 && j != 5 && escape3 == 0) // (나) 조건이면서 (다) 조건이 아닐 때 출력-2 (테두리 출력 때문에 1,2로 나뉨)
								printf("   %d   ", map[i][j]);
							escape3 = 0;
						}
					}

				}
				printf("│");
				if (i == 8)     // 테두리 출력을 위한 조건문들
				{
					printf("\n");
					printf("                            │                    │                    │                     │\n");
				}
				else if (i == 2 || i == 5)
				{
					printf("\n");
					printf("                            │                    │                    │                     │\n");
					printf("                            │────────────────────│────────────────────│─────────────────────│\n");
					printf("                            │                    │                    │                     │\n");
				}
				else
				{
					printf("\n");
					printf("                            │                    │                    │                     │\n");
					printf("                            │                    │                    │                     │\n");
				}
			}
			printf("                            └────────────────────┸────────────────────┸─────────────────────┘ ");

			if (escape2 == 9)    // 맵을 올바르게 완성했을 때, 딱 그 맵을 출력한 뒤에 클리어라고 하기 위해 만든 반복문
			{
				escape2 = 10;
				break;
			}

			while (1)
			{
				button = _getch();                         //플레이어에게 수나 이동키 또는 초기화 키, 맵 바꾸는 키를 입력받음 (그 외의 키는 변함 없음)

				if (button == 'm')                         // m을 누르면 해당 맵을 처음 상태로 초기화
				{
					A = B;
					for (int i = 0;i <= 59;i++)
					{
						if (B > 0)
						{
							map[listX[i]][listY[i]] = 0;
							B -= 1;
						}
					}
					B = A;
					A = 0;
					player.x = 0;
					player.y = 0;
					for (int i = 0;i <= 8;i++)
					{
						for (int j = 0;j <= 8;j++)
						{
							if (map[i][j] != 0)
								player.y += 1;
							else
							{
								escape3 = 1;
								break;
							}
						}
						if (escape3 == 1)
							break;
						player.x += 1;
					}
					escape3 = 0;
					break;
				}
				else if (button == 'p')                      // p를 누르면 맵을 바꿀 기회 제공
				{
					system("cls");
					printf("\n\n\n\n\n                                              정말 맵을 바꾸시겠습니까?");
					setColor(RED);
					printf("\n\n\n\n\n                                                     예 : p 키");
					setColor(BLUE);
					printf("\n\n\n\n\n                                              아니요 : p를 제외한 아무 키");
					setColor(WHITE);
					answer = _getch();
					if (answer == 'p')                       // 한 번에 그냥 바뀌면 좀 딱딱하니 p를 연속으로 2번 누르면 바뀌도록 함
					{
						escape = 2;
						for (int i = 0;i <= 59;i++)
							map[listX[i]][listY[i]] = 0;
						break;
					}
					else                                     // 중간에 마음이 변했으면 p가 아닌 다른 키를 눌러 있던 맵으로 이어서 진행
						break;

				}
				else if (button == '0')            // 0을 누르면 채워져 있던 수를 지우기 가능
				{
					map[player.x][player.y] = 0;
					break;
				}
				for (int n = 0;n < 9;n++)
				{
					if ((n <= 3 && button == move[n]) || button == number[n])       // 이동키 w,a,s,d 나 1~9의 숫자를 누른 경우
					{
						for (int i = 0; i <= 8; i++)
						{
							for (int j = 0;j <= 8;j++)
							{
								for (int m = 0;m <= 8;m++)
								{
									if (button == number[m]) // 1부터 9까지의 숫자를 눌렀다면 해당 플레이어 좌표의 값을 그 입력된 값으로 수정
									{
										if (map[i][j] == 0 && i == player.x && j == player.y) //비어있던 해당 좌표에 수 입력
										{
											map[i][j] = m + 1;
											break;
										}
										else
										{
											for (int g = 0;g < e;g++)
											{
												if (player.x == listX[g] && player.y == listY[g]) // 해당 좌표값을 수정
												{
													map[player.x][player.y] = m + 1;
													break;
												}
											}
										}
									}
								}
							}
						}
						escape = 1;
						break;
					}
					else
						escape = 0;
				}
				for (int i = 0;i <= 8;i++)
				{
					for (int j = 0;j <= 8;j++)
					{
						if (map[i][j] != listZ[0] && map[i][j] != listZ[1] && map[i][j] != listZ[2] &&
							map[i][j] != listZ[3] && map[i][j] != listZ[4] && map[i][j] != listZ[5] &&
							map[i][j] != listZ[6] && map[i][j] != listZ[7] && map[i][j] != listZ[8])   //0열부터 차례로 1~9의 숫자가 하나씩 존재하는 지의 여부를 판단하기 위한 반복문
						{
							listZ[c] = map[i][j];    // listZ를 이용해 현재 맵의 상태를 파악
							c = c + 1;
						}
					}
					c = 0;
					for (int l = 0;l <= 8;l++)
					{
						sum = sum + listZ[l];
						listZ[l] = 0;                // 마지막 행까지 계속 검사해야 하기 때문에 초기값 반환
					}
					if (sum == 45)                         //1~9의 숫자가 모든 행과 열에 하나씩 있는지 합 변수를 통해 최종 판단
						escape2 += 1;
					sum = 0;
				}
				if (escape2 != 9)
					escape2 = 0;
				if (escape == 1 || escape2 == 9)    // p 키를 눌렀을 때와 모든 행과 열에 1~9 숫자가 하나씩 존재할 때 반복문 탈출
					break;
			}
			if (escape == 2)
			{
				escape = 0;
				break;
			}
		} while (1);
		if (escape2 == 10)          // 클리어가 아니면 나올 수 없는 escape2 값(= 10)을 통해 최종 반복문 탈출 (이걸로 클리어 판단)
			break;                  // 9로 하면 마지막 칸까지 입력받은 후의 맵이 아닌 입력받기 전의 맵을 출력하고 클리어하기 때문이다. (한 칸이 미완성인 맵이 출력되는 것을 방지)
	} while (1);

	setColor(YELLOW);
	printf("\n\n\n                                --------------- 스도쿠를 클리어하셨습니다! --------------\n\n"); //최종 클리어 및 종료
	setColor(WHITE);
}
