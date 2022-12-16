#include <stdio.h>
#include <conio.h> // _getch() ����� ���� ��� ����
#include <windows.h> // ���� ���� �Լ��� �ҷ����� ���� ��� ����        // ���� ���� ���� ����Ʈ ----- > https://coding-factory.tistory.com/663
#include<stdlib.h> //rand(), srand()
#include<time.h> //time()                   // windows.h , stdlib.h , time.h���� ��� ���ϵ� ���� �� ���� ����Ʈ�� ���� ����

enum {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_SKYBLUE, DARK_RED, DARK_VOILET, DARK_YELLOW, GRAY, DARK_GRAY
	, BLUE, GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE
}; // ���� ����                                   // ���� ���� ���� ����Ʈ ----- > https://coding-factory.tistory.com/663

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}   // ���� ������ ���� �Լ�                           // ���� ���� ���� ����Ʈ ----- > https://coding-factory.tistory.com/663

struct locate //������ �� �÷��̾� ��ġ�� ����ü�� ����
{
	int x;  //�÷��̾� x��ǥ�� ���� ����
	int y;  //�÷��̾� y��ǥ�� ���� ����
};

int main(void)
{
	int escape = 0, escape2 = 0, escape3 = 0, stop = 0, c = 0, d = 0, e = 0, X = 0, Y = 0, A = 0, B = 0;
	// �ݺ��� Ż��/���ǹ� ȸ�ǿ� ���� escape/2/3�� stop, 0�� ��ǥ ���� ����� ���� A�� B�� c�� e, �� ��ȣ ���� ���� d, ���� x,y��ǥ�� ���� ���� X�� Y
	char begin = 0, button = 0, answer = 0, sum = 0; // ����Ű�� �Է¹޴� ���� begin, Ű �Է°� ���� ���� button�� answer, �� ���� sum -> (������ Ŭ���� �Ǵܿ� ���� ����)
	char number[] = { '1','2','3','4','5','6','7','8','9' }, move[] = { 'w','a','s','d' }; //�Է� �޴� Ű ���� ����
	int listX[60] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //���� 0�� x��ǥ ����� �迭 (60�� ��������� ����� Ȯ���ϱ� ���� �׳� ū ��)
	int listY[60] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
					 ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //���� 0�� y��ǥ ����� �迭 (60�� ��������� ����� Ȯ���ϱ� ���� �׳� ū ��)
	char listZ[9] = { 0,0,0,0,0,0,0,0,0 }; // ������ ���� ���¸� �Ǵ��ϱ� ���� �迭 (������ Ŭ��� �Ǵ��ϱ� ���� ���� ����)
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
	};                                 // ���� ���࿡ ���� ������ �� ����
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
	};                                  // 1��° ������ �� ����
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
	};                                  // 2��° ������ �� ����
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
	};                                  // 3��° ������ �� ����
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
	};                                  // 4��° ������ �� ����
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
	};                                  // 5��° ������ �� ����

	printf("\n\n\n\n\n");
	setColor(WHITE);     // ���� ���� ���� ����Ʈ ----- > https://coding-factory.tistory.com/663
	printf("                                                   *** ������ ***                \n\n\n\n\n\n");
	setColor(GREEN);
	printf("                                           �̵�Ű�� 'w','a','s','d'Ű�Դϴ�.\n\n\n");
	setColor(DARK_YELLOW);
	printf("                                           ���� ������� '���� 0'�� ��������!\n\n\n");
	setColor(RED);
	printf("                                 �Է��� ���� ��ü �ʱ�ȭ�Ͻ÷��� 'm'Ű�� ������ �˴ϴ�!\n\n\n");
	setColor(VIOLET);
	printf("                                        ���� �ٲٰ� �ʹٸ� 'p'Ű�� ��������!\n\n\n");
	setColor(SKYBLUE);
	printf("                                           �����Ϸ��� �ƹ� Ű�� �����ʽÿ�!");

	begin = _getch(); // ���⿡ �ƹ� Ű�� �Է� ������ ������ ������ �� �ִ�.
	setColor(WHITE);
	system("cls"); // ��µǾ��� ��� ���� ����(�����ؼ� ������ ���� ǥ�õǴ� ���� �����ϱ� ���� �߿��� ��ɾ�)
	// system ("cls") ���� ����Ʈ --> https://blog.naver.com/PostView.naver?blogId=3th_october&logNo=140166613598

	do {
		srand((unsigned int)time(NULL));       // ���� �Լ� ���� ����Ʈ ---> https://coding-factory.tistory.com/666
		A = (rand() % 5) + 1;  // �� ����
		if (A == d)   // ���� �ʰ� �Ȱ��� ���� �ҷ����� ���ϰ� �ϱ� ���� ���ǹ�
			continue;
		d = A;

		switch (A)  // ������ �� 5�� �� �������� �� �̱�
		{
		case 1:     // 1��° ������ ���� ���õ� ���
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map1[i][j];
				}
			}
			break;
		case 2:     // 2��° ������ ���� ���õ� ���
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map2[i][j];
				}
			}
			break;
		case 3:     // 3��° ������ ���� ���õ� ���
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map3[i][j];
				}
			}
			break;
		case 4:     // 4��° ������ ���� ���õ� ���
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map4[i][j];
				}
			}
			break;
		case 5:     // 5��° ������ ���� ���õ� ���
			for (int i = 0; i <= 8;i++)
			{
				for (int j = 0;j <= 8;j++)
				{
					map[i][j] = map5[i][j];
				}
			}
			break;
		}


		for (int i = 0; i <= 8;i++)  //������ �ʿ��� ���� 0�̾��� ��ġ(x,y)�� ���� �����ϱ� ���� ��ø �ݺ���
		{
			for (int j = 0;j <= 8;j++)
			{
				if (map[i][j] == 0)
				{
					listX[c] = i; // �ش� ������ ���� 0�� �κ��� x��ǥ ����
					listY[c] = j; // �ش� ������ ���� 0�� �κ��� y��ǥ ����
					c += 1;       // ���� ������ ���� 0�� ��ǥ ������ ���������� ����
				}
			}
		}
		B = c;  // 0�� ��ǥ ������ B�� ���� (���� �ڵ忡�� ���� ������ ������ ��� ����)
		e = c;  // 0�� ��ǥ ������ e�� ���� (���� �ڵ忡�� ���� ������ ������ ��� ����)
		c = 0;  // ���߿� �ٽ� ���� ���� ������ ���� �ʱⰪ�̾��� 0���� ����

		struct locate player = { 0,0 }; //�÷��̾� ��ġ �ʱⰪ ���� (�ʱⰪ�� �ϴ� �־�� ���� �߻� Ȯ���� �پ��)

		for (int i = 0;i <= 8;i++)  //���� ��ܺ��� 0���� 0��->0���� 1��->0���� 2��...������ 0������ ���θ� �Ǵ��ϰ� ���� ���� ã�� 0��ġ�� �÷��̾� ��ġ ����
		{
			for (int j = 0;j <= 8;j++)
			{
				if (map[i][j] != 0)  // 0�� �ƴϸ� �÷��̾� ��ǥ�� ����
					player.y += 1;
				else                 // 0�� �´ٸ� �ش� ��ǥ�� �÷��̾� ��ǥ�� ����
				{
					escape3 = 1; //escape3 ���� ���� (�� �̻��� �ݺ��� �����ϱ� ����)
					break;
				}
			}
			if (escape3 == 1)             //��ø �ݺ����� �ѹ��� Ż���ϱ� ���� ���ǹ� (Ż��� ���� escape3 ���)
				break;
			if (player.x != 8)            //�ش� ���� ��� ���� 0�� �ƴϾ��ٸ� ���� ������ �Ѿ
				player.x += 1;
		}
		escape3 = 0; // �ݺ��� Ż��/���ǹ� ȸ�ǿ� ������ ���� �ٽ� ������ �𸣴� ���� ������ �ٽ� �����ؾ� �Ѵ�.

		do
		{
			system("cls");
			switch (button) // ��ư Ű�� �̵�Ű w,a,s,d �� �ϳ��� ���
			{
			case 'w': // w Ű�� �Է¹޾Ҵٸ� ���� �̵��ϴ� ���� ���� (��, �� ���� �ִٸ� �� ���� ������ ������ �̵� | * �ִ� ���� (0,0)�̾��� ��쿡�� ����ġ�� ���� X)
				X = player.x;  //������ x��ǥ ����
				Y = player.y;  //������ y��ǥ ����
				if (player.y != 0) //������ y��ǥ�� 0�� �ƴ� ��� - (���� 1)
				{
					if (player.x != 0) //������ x��ǥ�� 0�� �ƴ� ��� - (���� 2)
					{
						for (int i = 1;i <= X;i++) // (���� 1) && (���� 2) ��ο� �ش��ϴ� ���
						{
							if (map[player.x - i][player.y] == 0)  // ������ ���� ��ǥ�� ���� 0�̶�� �ش� (x,y)�� �÷��̾� ��ǥ�� ����
							{
								player.x -= i;
								stop = 1;       // �� ���, �ٸ� ���ǹ��̳� �ݺ����� �� ��ġ�� �� �Ǵ� �ݺ��� ȸ�ǿ� ���� stop�� ���� 
								break;
							}
							else if (map[player.x - i][player.y] != 0)
							{
								for (int g = 0;g < e;g++)
								{
									if (player.x - i == listX[g] && player.y == listY[g]) // ������ ��ǥ�� 0�� �ƴ����� ���� 0�̾��� ��ǥ�� �� ��ǥ�� �̵�
									{
										player.x -= i;
										stop = 1;
										break;
									}
								}
								if (stop == 1)
									break;
							}
							if (i == X)  // �ش� ���� �� ������ �� �˻��ߴµ��� 0�� ���� ��� (= ������ �ݺ��� ���)
								player.x = 0;   // (���� 1) && (���� 2)�� ��� �� �� ��쿡 ���ؼ��� 10�� ���� ���ǹ� ���� (Ư�� ���̽�) 
							if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0) // (0,0)���� ���� 0�� �ƴ� ��� -> wŰ�� �̵��� �Ұ�
							{
								player.x = X;  // ������ x��ǥ�� �ٽ� ����
								player.y = Y;  // ������ y��ǥ�� �ٽ� ����
								stop = 2;     // stop���� 2�� ���� -> ���� wŰ�� ���� ���ǹ��� ������ ����
								break;        // �� ���ǹ��� ���: wŰ�� ������ �̵����� �ʰ� ������ ��ǥ�� ������ ���� (���� wŰ�� ���� ����/�ݺ��� ���� X
							}
						}
					}
					if (player.x == 0 && stop == 0) // ���� x��ǥ�� 0�̾��ų� (���� 2)�� (Ư�� ���̽�)�� ���ؼ��� ����
					{
						for (int w = 1;w <= Y;w++)
						{
							player.x = 8;
							player.y -= 1;
							for (int j = 0;j <= 8;j++)
							{
								if (map[player.x][player.y] == 0)  // ������ ��ǥ�� 0�� ���, �ش� ��ǥ�� ����, w�� ���� ����ġ���� ������ Ż�� - (A)
								{
									stop = 3;
									break;
								}
								else if (j <= 7)
								{
									for (int g = 0;g < e;g++)
									{
										if (player.x == listX[g] && player.y == listY[g]) // 0�� �ƴ����� �ش� ��ǥ�� ���� 0�̾��� ��ǥ�� �װ����� �̵�
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
								if (player.x == 0 && player.y == 0 && map[player.x][player.y] != 0) //(0,0)���� 0�� ��ǥ�� �ϳ��� ���� ���
								{
									player.x = X;  //������ x��ǥ �� �ٽ� ����
									player.y = Y;  //������ y��ǥ �� �ٽ� ����
								}
							}
							if (stop == 3)    // ���� ��� �� (A)�� ��쿡 ���ؼ��� �ݺ��� Ż��
								break;
						}
					}
				}
				if (player.y == 0 && stop == 0) // �÷��̾� y��ǥ�� 0�� ��� (= (���� 1)�� �ƴ� ���)
				{
					for (int i = 1;i <= X;i++)
					{
						if (map[player.x - i][player.y] == 0) // ������ ��ǥ�� 0�� ���, ������ �ش� ��ǥ�� �̵�
						{
							player.x -= i;
							break;
						}
						else
						{
							for (int g = 0;g < e;g++)
							{
								if (player.x - i == listX[g] && player.y == listY[g]) //0�� �ƴ����� �ش� ��ǥ�� ���� 0�̾��� ��� (�� ��ǥ�� �̵�)
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
				stop = 0; // �ݺ��� Ż��/���ǹ� ȸ�ǿ� ������ ���� �ٽ� ������ �𸣴� ������ ������ �ٽ� �����ؾ� �Ѵ�.
				break;
			case 'a':  // a Ű�� �Է¹����� �������� �̵��ϴ� ���� ���� (��, �� ���ʿ� �ִٸ� �� ���� ������ ���� �̵� | * �ִ� ���� (0,0)�̾��� ��쿡�� ����ġ�� ���� X)
				X = player.x;
				Y = player.y;
				if (player.x != 0) // ����� ���� w�� ������ �����ϴ� ���� ���� (w�� �ٸ� ���� ��κ��� �ڵ忡�� x,y�� ���� �ٲ�)
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
			case 's': // s Ű�� �Է¹����� �Ʒ��� �̵��ϴ� ���� ���� (��, �� �Ʒ��� �ִٸ� �� ���� ù ������ �̵� | * �ִ� ���� (8,8)�̾��� ��쿡�� ����ġ�� ���� X)
				X = player.x;
				Y = player.y;
				if (player.y != 8)  // ����� ���� w,a�� ������ �����ϴ� ���� ���� (w�� �ٸ� ���� ��κ��� �ڵ忡�� 0�� 8�� ���� �ٲ�)
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
			case 'd': // d Ű�� �Է¹����� ���������� �̵��ϴ� ���� ���� (��, �� �����ʿ� �ִٸ� �� ���� ù ���� �̵� | * �ִ� ���� (8,8)�̾��� ��쿡�� ����ġ�� ���� X)
				X = player.x;
				Y = player.y;
				if (player.x != 8)  // ����� ���� w,a,s�� ������ �����ϴ� ���� ���� (w�� �ٸ� ���� ��κ��� �ڵ忡�� x,y�� ���� �ٲ�� 0�� 8�� ���� �ٲ�)
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

			}  // *����� ������ �÷��̾� ��ǥ�� (0,0)�� ���� w, a ���� �̵��� �Ұ�, (8,8)�� ���� s, d ���� �̵��� �Ұ�

			printf("                            ����������������������������������������������������������������������������������������������������������������������������������\n");
			printf("                            ��                    ��                    ��                     ��\n");
			for (int i = 0; i <= 8; i++)
			{
				printf("                            "); // ������ ���� ����� ǥ���ϱ� ���� �뷮�� ���� (���� �۴�� ��� �κп��� �����ϰ� ����)
				printf("��");       // ������ ���� �׵θ��� ���� �۴��
				for (int j = 0;j <= 8;j++)     // ***** ������ �� ����� ���� �ݺ��� (�� �ݺ����� ���� �츮�� ������ ���� �� �� ����) *****
				{
					if (map[i][j] == 0)  // �ʿ��� ���� 0�� ���� ���� ��ǥ ��� - (��)
					{
						if (i == player.x && j == player.y) // (��) �����̸鼭 �÷��̾� ��ǥ�� �� ���
						{
							if (j == 2 || j == 5)
							{
								setColor(GRAY);
								printf("  ___ ");
								setColor(WHITE);
								printf("��");
							}
							else
							{
								setColor(GRAY);
								printf("  ___  ");
								setColor(WHITE);
							}
						}
						else // �׳� (��) ������ �� ���
						{
							if (j == 2 || j == 5)
								printf("      ��");
							else
								printf("       ");
						}
					}
					else if (map[i][j] != 0) // �ʿ��� �̹� ��(1~9)�� ä���� �ִ� ��ǥ ��� - (��)
					{
						if (i == player.x && j == player.y) // (��) �����̸鼭 �÷��̾� ��ǥ�� �� ���
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
								printf("��");
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
						else  // �׳� (��) ������ �� ���
						{
							for (int k = 0;k < e;k++)  // �׳� (��) �����ε� ���� 0�̾��� ��ǥ�� �� ��� - (��)
							{
								if (i == listX[k] && j == listY[k])
								{
									setColor(GREEN);
									printf("   %d  ", map[i][j]);
									setColor(WHITE);
									if (j == 2 || j == 5)
										printf("��");
									else
										printf(" ");
									escape3 = 1;
									break;
								}
							}
							if ((j == 2 || j == 5) && escape3 == 0) // (��) �����̸鼭 (��) ������ �ƴ� �� ���-1 (�׵θ� ��� ������ 1,2�� ����)
								printf("   %d  ��", map[i][j]);
							else if (j != 2 && j != 5 && escape3 == 0) // (��) �����̸鼭 (��) ������ �ƴ� �� ���-2 (�׵θ� ��� ������ 1,2�� ����)
								printf("   %d   ", map[i][j]);
							escape3 = 0;
						}
					}

				}
				printf("��");
				if (i == 8)     // �׵θ� ����� ���� ���ǹ���
				{
					printf("\n");
					printf("                            ��                    ��                    ��                     ��\n");
				}
				else if (i == 2 || i == 5)
				{
					printf("\n");
					printf("                            ��                    ��                    ��                     ��\n");
					printf("                            ����������������������������������������������������������������������������������������������������������������������������������\n");
					printf("                            ��                    ��                    ��                     ��\n");
				}
				else
				{
					printf("\n");
					printf("                            ��                    ��                    ��                     ��\n");
					printf("                            ��                    ��                    ��                     ��\n");
				}
			}
			printf("                            ���������������������������������������������������������������������������������������������������������������������������������� ");

			if (escape2 == 9)    // ���� �ùٸ��� �ϼ����� ��, �� �� ���� ����� �ڿ� Ŭ������ �ϱ� ���� ���� �ݺ���
			{
				escape2 = 10;
				break;
			}

			while (1)
			{
				button = _getch();                         //�÷��̾�� ���� �̵�Ű �Ǵ� �ʱ�ȭ Ű, �� �ٲٴ� Ű�� �Է¹��� (�� ���� Ű�� ���� ����)

				if (button == 'm')                         // m�� ������ �ش� ���� ó�� ���·� �ʱ�ȭ
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
				else if (button == 'p')                      // p�� ������ ���� �ٲ� ��ȸ ����
				{
					system("cls");
					printf("\n\n\n\n\n                                              ���� ���� �ٲٽðڽ��ϱ�?");
					setColor(RED);
					printf("\n\n\n\n\n                                                     �� : p Ű");
					setColor(BLUE);
					printf("\n\n\n\n\n                                              �ƴϿ� : p�� ������ �ƹ� Ű");
					setColor(WHITE);
					answer = _getch();
					if (answer == 'p')                       // �� ���� �׳� �ٲ�� �� �����ϴ� p�� �������� 2�� ������ �ٲ�� ��
					{
						escape = 2;
						for (int i = 0;i <= 59;i++)
							map[listX[i]][listY[i]] = 0;
						break;
					}
					else                                     // �߰��� ������ �������� p�� �ƴ� �ٸ� Ű�� ���� �ִ� ������ �̾ ����
						break;

				}
				else if (button == '0')            // 0�� ������ ä���� �ִ� ���� ����� ����
				{
					map[player.x][player.y] = 0;
					break;
				}
				for (int n = 0;n < 9;n++)
				{
					if ((n <= 3 && button == move[n]) || button == number[n])       // �̵�Ű w,a,s,d �� 1~9�� ���ڸ� ���� ���
					{
						for (int i = 0; i <= 8; i++)
						{
							for (int j = 0;j <= 8;j++)
							{
								for (int m = 0;m <= 8;m++)
								{
									if (button == number[m]) // 1���� 9������ ���ڸ� �����ٸ� �ش� �÷��̾� ��ǥ�� ���� �� �Էµ� ������ ����
									{
										if (map[i][j] == 0 && i == player.x && j == player.y) //����ִ� �ش� ��ǥ�� �� �Է�
										{
											map[i][j] = m + 1;
											break;
										}
										else
										{
											for (int g = 0;g < e;g++)
											{
												if (player.x == listX[g] && player.y == listY[g]) // �ش� ��ǥ���� ����
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
							map[i][j] != listZ[6] && map[i][j] != listZ[7] && map[i][j] != listZ[8])   //0������ ���ʷ� 1~9�� ���ڰ� �ϳ��� �����ϴ� ���� ���θ� �Ǵ��ϱ� ���� �ݺ���
						{
							listZ[c] = map[i][j];    // listZ�� �̿��� ���� ���� ���¸� �ľ�
							c = c + 1;
						}
					}
					c = 0;
					for (int l = 0;l <= 8;l++)
					{
						sum = sum + listZ[l];
						listZ[l] = 0;                // ������ ����� ��� �˻��ؾ� �ϱ� ������ �ʱⰪ ��ȯ
					}
					if (sum == 45)                         //1~9�� ���ڰ� ��� ��� ���� �ϳ��� �ִ��� �� ������ ���� ���� �Ǵ�
						escape2 += 1;
					sum = 0;
				}
				if (escape2 != 9)
					escape2 = 0;
				if (escape == 1 || escape2 == 9)    // p Ű�� ������ ���� ��� ��� ���� 1~9 ���ڰ� �ϳ��� ������ �� �ݺ��� Ż��
					break;
			}
			if (escape == 2)
			{
				escape = 0;
				break;
			}
		} while (1);
		if (escape2 == 10)          // Ŭ��� �ƴϸ� ���� �� ���� escape2 ��(= 10)�� ���� ���� �ݺ��� Ż�� (�̰ɷ� Ŭ���� �Ǵ�)
			break;                  // 9�� �ϸ� ������ ĭ���� �Է¹��� ���� ���� �ƴ� �Է¹ޱ� ���� ���� ����ϰ� Ŭ�����ϱ� �����̴�. (�� ĭ�� �̿ϼ��� ���� ��µǴ� ���� ����)
	} while (1);

	setColor(YELLOW);
	printf("\n\n\n                                --------------- ������ Ŭ�����ϼ̽��ϴ�! --------------\n\n"); //���� Ŭ���� �� ����
	setColor(WHITE);
}
