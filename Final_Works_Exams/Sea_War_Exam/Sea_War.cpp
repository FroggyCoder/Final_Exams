#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

/// <summary>
/// Координаты кораблей
/// </summary>
struct boat
{
	int xn;
	char yn;
	int xk;
	char yk;
};

/// <summary>
/// вывод ошибки
/// </summary>
void showerror()
{
	cout << "Ошибка!\n";
	system("pause");
}

char** create(int n)
{
	char** temp = new char* [n];

	for (int i = 0; i < n; i++)
	{
		temp[i] = new char[n];
	}
	return temp;
}

/// <summary>
/// инициализация поля нулями
/// </summary>
/// <param name="komp"></param>
/// <param name="n"></param>
void input_pole(char** komp, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			komp[i][j] = '0';
		}
	}
}

void copypole(char** dest, char** source, int n)
{
	//копирует массив source в массив dest
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dest[i][j] = source[i][j];
		}
	}
}

/// <summary>
/// вывод поля
/// </summary>
/// <param name="komp"></param>
/// <param name="n"></param>
void print_pole(char** komp, int n)
{
	cout << '\t';

	for (int i = 1; i < n; i++)
	{
		cout << (char)(-65 + i) << "\t";
	}

	cout << '\n';

	for (int i = 1; i < n; i++)
	{
		cout << i << "\t";

		for (int j = 1; j < n; j++)
		{
			cout << komp[i][j] << "\t";
		}

		cout << "\n";
	}

	cout << "\n";
	system("pause");
}

int c_to_n(char s)
{
	int code;
	code = (int)s;

	if ((code >= -32) && (code <= -21)) code -= 32;
	{
		return (code + 65);
	}
}

char n_to_c(int n)
{
	return (char)(n - 65);
}

int myatoi(char s)
{
	int x;

	switch (s)
	{
	case '1': x = 1;

		break;

	case '2': x = 2;

		break;

	case '3': x = 3;

		break;

	case '4': x = 4;

		break;

	case '5': x = 5;

		break;

	case '6': x = 6;

		break;

	case '7': x = 7;

		break;

	case '8': x = 8;

		break;

	case '9': x = 9;

		break;
	}

	return x;
}

/// <summary>
/// установка корабля размером size
/// </summary>
/// <param name="chel"></param>
/// <param name="n"></param>
/// <param name="size"></param>
void setboat(char** chel, int n, int size)
{

	int i, j, sti, stj, sts;

	sts = size;

	char** buffer = create(n + 1);

	copypole(buffer, chel, n + 1);

	do
	{
		i = rand() % 10 + 1;
		j = rand() % 10 + 1;
		sti = i;
		stj = j;
	} while (!((chel[i][j] == '0') && (chel[i][j - 1] == '0')
		&& (chel[i][j + 1] == '0') && (chel[i - 1][j - 1] == '0')
		&& (chel[i - 1][j] == '0') && (chel[i - 1][j + 1] == '0')
		&& (chel[i + 1][j - 1] == '0') && (chel[i + 1][j] == '0')
		&& (chel[i + 1][j + 1] == '0')));

	chel[i][j] = '*';

	size--;

	int napr;

	napr = rand() % 4;

	while (size > 0)
	{
		switch (napr)
		{
		case 0:

			i--;

			if ((i >= 1) && (chel[i][j] == '0') && (chel[i][j - 1] == '0')
				&& (chel[i][j + 1] == '0') && (chel[i - 1][j - 1] == '0')
				&& (chel[i - 1][j] == '0') && (chel[i - 1][j + 1] == '0'))
			{
				chel[i][j] = '*'; size--; if (size == 0) break;
			}

			else
			{
				napr = 1; i = sti; j = stj; size = sts; copypole(chel, buffer, n + 1);
			}

			break;

		case 1:

			j++;

			if ((j <= 10) && (chel[i][j] == '0') && (chel[i - 1][j] == '0')
				&& (chel[i - 1][j + 1] == '0') && (chel[i][j + 1] == '0')
				&& (chel[i + 1][j + 1] == '0') && (chel[i + 1][j] == '0'))
			{
				chel[i][j] = '*'; size--; if (size == 0) break;
			}

			else
			{
				napr = 2; i = sti; j = stj; size = sts; copypole(chel, buffer, n + 1);
			}

			break;

		case 2:

			i++;

			if ((i <= 10) && (chel[i][j] == '0') && (chel[i][j + 1] == '0')
				&& (chel[i + 1][j + 1] == '0') && (chel[i + 1][j] == '0')
				&& (chel[i + 1][j - 1] == '0') && (chel[i][j - 1] == '0'))
			{
				chel[i][j] = '*'; size--; if (size == 0) break;
			}

			else
			{
				napr = 3; i = sti; j = stj; size = sts; copypole(chel, buffer, n + 1);
			}

			break;

		case 3:

			j--;

			if ((j >= 1) && (chel[i][j] == '0') && (chel[i + 1][j] == '0')
				&& (chel[i + 1][j - 1] == '0') && (chel[i][j - 1] == '0')
				&& (chel[i - 1][j - 1] == '0') && (chel[i - 1][j] == '0'))
			{
				chel[i][j] = '*'; size--; if (size == 0) break;
			}

			else
			{
				napr = 0; i = sti; j = stj; size = sts; copypole(chel, buffer, n + 1);
			}

			break;
		}
	}
}

/// <summary>
/// вывод правил игры
/// </summary>
void print_prav()
{
	system("cls");

	cout << "Правила игры:\n";
	cout << "\tКлассическая игра заключается в том, что два игрока рисуют на листках бумаги (каждый\n\tна своем и так, чтобы противник не подглядел) два игровых поля размера 10 х 10 клеток.\n\tОдно - игровое, второе служит для проведения разведывательных работ.\n";

	cout << "\tСверху, по горизонтали на обоих полях пишут буквы в алфавитном порядке.\n\tПо левой наружной стороне каждого квадрата ставим цифры - от 1 до 10.\n";

	cout << "\n";

	cout << "Корабли на бумаге:\n";

	cout << "\tСтандартная флотилия игроков в «Морской бой» включает в себя десять кораблей.\n\tОни отличаются по количеству занимаемых клеток - от одной до четырех.\n\tНазвание каждого корабля - это обозначение количества «палуб» или клеток: однопалубный, двухпалубный и так далее...\n\tКоличество единиц каждого корабля зависит от того, сколько клеток на игровом поле он занимает.\n\tТак, четырехпалубный только один, а вот однопалубных - четыре. Соответственно, двухклеточных кораблей - три, а трехклеточных - два.\n";

	cout << "\t\t1. * * * * - линкор\n";

	cout << "\t\t2. * * * - крейсеры\n";

	cout << "\t\t3. * * - эсминцы\n";

	cout << "\t\t4. * - шлюбки\n";

	cout << "\tКаждый игрок сам для себя решает, как расставить флот, нарисовав очертания каждого корабля в игровом квадрате.\n\tВажное уточнение - ни один из кораблей не должен касаться другого, и фигура корабля должна напоминать прямоугольник\n\t(или квадрат, в случае с однопалубным), то есть корабли не могут иметь ломаных линий.\n\tНе запрещается кораблям располагаться по границам квадрата или находиться в углах.\n";

	cout << "\n";

	cout << "Процесс игры:\n";

	cout << "\tКак только игроки расставили корабли в своих игровых полях, начинается игра.\n\tЧтобы угадать расположение кораблей противника, игроки совершают «выстрелы», отмечаемые на свободном квадрате.\n\tЧтобы упростить задачу, и нужны буквенные и числовые обозначения клеток. \n\tВыстрелы совершаются по координатам, например, А8 или Г6.\n\tЕсли противник называет координаты, по которой находится часть корабля, то второй игрок обязан сказать: «ранен» и отмечают подбитую часть Х,\n\tесли в итоге корабль полностью обстрелян, то тогда произносят кодовое слово «Убит».\n";

	cout << "\tЕсли противник попадает по кораблю, то он делает следующий ход - пока не промахнется.\n\tИгра идет до того момента, пока кто-то не потопит все корабли противника.\n";

	cout << '\n';

	system("pause");
}

/// <summary>
/// меню
/// </summary>
/// <returns></returns>
char runmenu()
{
	system("cls");

	cout << "1-Правила игры.\n";

	cout << "2-Режим игры(человек задает рассположение кораблей вручную).\n";

	cout << "3-Режим игры(рассположение кораблей человека задает компьютер автоматически).\n";

	cout << "4-Начать игру.\n";

	cout << "Выход (Esc).\n";

	return _getch();
}

void setpole_a(char** chel, int n)
{
	int i, j, count = 1;

	for (i = 4; i >= 1; i--)
	{
		for (j = 1; j <= count; j++)
		{
			setboat(chel, n, i);
		}
		count++;
	}
}

bool setboat_m(char** chel, int n, boat b, int size)
{
	bool f = false;
	int y1, y2;

	y1 = c_to_n(b.yn);

	y2 = c_to_n(b.yk);

	if ((b.xn == b.xk) && ((y2 - y1 + 1) == size))
	{
		for (int jj = y1; jj <= y2; jj++)
		{
			chel[b.xn][jj] = '*';
		}
		f = true;
	}

	if ((y1 == y2) && ((b.xk - b.xn + 1) == size))
	{
		for (int jj = b.xn; jj <= b.xk; jj++)
		{
			chel[jj][y1] = '*';
		}
		f = true;
	}
	return f;
}

bool invalidchar(char x)
{
	bool f = true;

	if (((x >= 'а') && (x <= 'й')) || ((x >= 'А') && (x <= 'Й'))) f = false;
	{
		return f;
	}
}

/// <summary>
/// выстрел
/// </summary>
/// <param name="p"></param>
/// <param name="n"></param>
/// <param name="i"></param>
/// <param name="j"></param>
/// <param name="colpopad"></param>
/// <returns></returns>
bool bah(char** p, int n, int i, int j, int& colpopad)
{
	bool f = false;

	if (p[i][j] == '*')
	{
		p[i][j] = 'X'; colpopad++; f = true;
	}

	else
	{
		p[i][j] = '#'; f = false;
	}
	return f;
}

/// <summary>
/// показ полей
/// </summary>
/// <param name="chel"></param>
/// <param name="map"></param>
/// <param name="n"></param>
void showmap(char** chel, char** map, int n)
{
	system("cls");

	cout << "Игровое поле пользователя:\n";
	print_pole(chel, n - 1);

	cout << "Игровое поле противника:\n";
	print_pole(map, n - 1);
}

/// <summary>
/// ввод координат выстрела
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
/// <returns></returns>
bool inputbah(int& i, int& j)
{
	bool flag = true;
	char k[4];

	cout << "Введите координаты выстрела:";
	cin >> k;

	if (invalidchar(k[0]))
	{
		showerror();
		flag = false;
	}

	else
	{
		if (flag) j = c_to_n(k[0]);
	}

	if ((strlen(k) == 2) && flag)
	{
		i = myatoi(k[1]);
	}

	else

		if ((strlen(k) == 3) && (k[1] == '1') && (k[2] == '0') && flag)
		{
			i = 10;
		}

	if ((k[2] != '0') && (strlen(k) == 3))
	{
		showerror();
		flag = false;
	}
	return flag;
}

/// <summary>
/// выстрел человека
/// </summary>
/// <param name="komp"></param>
/// <param name="map"></param>
/// <param name="n"></param>
/// <param name="ibah"></param>
/// <param name="jbah"></param>
/// <param name="cpopadchel"></param>
/// <returns></returns>
bool firechel(char** komp, char** map, int n, int& ibah, int& jbah, int& cpopadchel)
{
	bool f, f2;

	cout << "Выстрел пользователя...\n";

	do
	{
		f = inputbah(ibah, jbah);

		if (f)
		{
			if ((map[ibah][jbah] == 'X') || (map[ibah][jbah] == '#'))
			{
				showerror(); f2 = true; continue;
			}

			else
			{
				if (bah(komp, n, ibah, jbah, cpopadchel))
				{
					map[ibah][jbah] = 'X';
					f2 = true;
				}

				else
				{
					map[ibah][jbah] = '#'; f2 = false;
				}
			}
		}
	} while (!f);

	return f2;
}

/// <summary>
/// выстрел компьютера
/// </summary>
/// <param name="chel"></param>
/// <param name="mapk"></param>
/// <param name="n"></param>
/// <param name="ibahk"></param>
/// <param name="jbahk"></param>
/// <param name="oldibahk"></param>
/// <param name="oldjbahk"></param>
/// <param name="cpoadk"></param>
/// <returns></returns>
bool firecomp(char** chel, char** mapk, int n, int& ibahk, int& jbahk, int& oldibahk, int& oldjbahk, int& cpoadk)
{
	cout << "Выстрел компьютера...\n";

	do
	{
		if ((mapk[oldibahk][oldjbahk] != 'X') || (mapk[oldibahk][oldjbahk] != '#'))
		{
			ibahk = rand() % 10 + 1;
			jbahk = rand() % 10 + 1;
		}

		if (mapk[oldibahk][oldjbahk] == 'X')
		{
			if (((oldibahk + 1) != 11) && (mapk[oldibahk + 1][oldjbahk] == '0'))
			{
				ibahk = oldibahk + 1;
				jbahk = oldjbahk;

				break;
			}

			if (((oldjbahk + 1) != 11) && (mapk[oldibahk][oldjbahk + 1] == '0'))
			{
				ibahk = oldibahk;
				jbahk = oldjbahk + 1;

				break;
			}

			if (((oldibahk - 1) != 0) && (mapk[oldibahk - 1][oldjbahk] == '0'))
			{
				ibahk = oldibahk - 1;
				jbahk = oldjbahk;

				break;
			}

			if (((oldjbahk - 1) != 0) && (mapk[oldibahk][oldjbahk - 1] == '0'))
			{
				ibahk = oldibahk;
				jbahk = oldjbahk - 1;

				break;
			}
		}
	} while ((mapk[ibahk][jbahk] == 'X') || (mapk[ibahk][jbahk] == '#'));

	oldibahk = ibahk;
	oldjbahk = jbahk;

	cout << n_to_c(jbahk) << ibahk << "\n";

	system("pause");

	if (bah(chel, n, ibahk, jbahk, cpoadk))
	{
		mapk[ibahk][jbahk] = 'X';
		return true;
	}

	else
	{
		mapk[ibahk][jbahk] = '#'; return false;
	}
}

void main()
{
	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	srand(time(0));

	int n = 12;

	char** komp = create(n);
	char** chel = create(n);
	char** map = create(n);
	char** mapk = create(n);

	char v;
	char koord[4];

	int j, c, ibah, jbah, ibahk, jbahk, oldibahk = 0, oldjbahk = 0;

	boat myboat;

	int count = 1, cpoadk = 0, cpopadchel = 0;

	bool flag = false;
	bool startgame = false;

	do
	{
		v = runmenu();

		switch (v)
		{
		case '1':

			print_prav();

			break;

		case '2':

			input_pole(chel, n);

			cout << "Игровое поле пользователя:\n";

			print_pole(chel, n - 1);

			for (c = 4; c >= 1; c--)
			{
				for (j = 1; j <= count; j++)
				{
					do
					{
						cout << "Задайте координаты " << c << "-палубного корабля\n";

						cout << "Введите начальные координаты корабля\n";
						cin >> koord;

						myboat.yn = koord[0];

						if (invalidchar(myboat.yn))
						{
							showerror();
							continue;
						}

						if (strlen(koord) == 2)
						{

							myboat.xn = myatoi(koord[1]);
						}
						else
						{
							if ((strlen(koord) == 3) && (koord[1] == '1') && (koord[2] == '0'))
							{
								myboat.xn = 10;
							}
						}
						if ((koord[2] != '0') && (strlen(koord) == 3))
						{
							showerror();
							continue;
						}

						if (c != 1)
						{
							cout << "Введите конечные координаты корабля\n";
							cin >> koord;

							myboat.yk = koord[0];

							if (invalidchar(myboat.yk))
							{
								showerror();
								continue;
							}

							if (strlen(koord) == 2)
							{
								myboat.xk = myatoi(koord[1]);
							}
							else
							{
								if ((strlen(koord) == 3) && (koord[1] == '1') && (koord[2] == '0'))
								{
									myboat.xk = 10;
								}
							}

							if ((koord[2] != '0') && (strlen(koord) == 3))
							{
								showerror();
								continue;
							}
						}

						else
						{
							myboat.xk = myboat.xn;
							myboat.yk = myboat.yn;
						}

						system("cls");

						flag = setboat_m(chel, n, myboat, c);

						if (!flag)
						{
							showerror();
						}

						cout << "Игровое поле пользователя:\n";

						print_pole(chel, n - 1);

					} while (!flag);
				}
				count++;
			}

			startgame = true;
			break;

		case '3':

			input_pole(chel, n);

			cout << "Игровое поле пользователя:\n";

			setpole_a(chel, n - 1);

			print_pole(chel, n - 1);

			startgame = true;

			break;

		case '4':

			if (startgame)
			{
				input_pole(map, n);

				input_pole(mapk, n);

				input_pole(komp, n);

				setpole_a(komp, n - 1);

				do
				{
					do
					{
						showmap(chel, map, n);

						if ((cpoadk == 20) || (cpopadchel == 20)) break;

					} while (firechel(komp, map, n, ibah, jbah, cpopadchel));

					if ((cpoadk == 20) || (cpopadchel == 20)) break;

					do
					{
						showmap(chel, map, n);

						if ((cpoadk == 20) || (cpopadchel == 20)) break;

					} while (firecomp(chel, mapk, n, ibahk, jbahk, oldibahk, oldjbahk, cpoadk));

					/*cout << "Поле компьютера:\n";

					print_pole(komp, n - 1);*/

					if ((cpoadk == 20) || (cpopadchel == 20)) break;

				} while ((cpopadchel < 20) || (cpoadk < 20));

				if (cpopadchel > cpoadk) cout << "Конец игры: победил пользователь!\n";

				if (cpoadk > cpopadchel) cout << "Конец игры: победил компьютер!\n";

				if (cpoadk == cpopadchel) cout << "Ничья!";

				system("pause");
			}

			else
			{
				cout << "Для начала игры задайте координаты кораблей.\n";
				system("pause");
			}
			break;

		default: cout << "Сделайте правильный выбор!!!";
		}

	} while (v != 27);

	for (c = 0; c < n; c++)
	{
		delete[] komp[c];

		delete[] chel[c];

		delete[] map[c];

		delete[] mapk[c];
	}
}