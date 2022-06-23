#include <iostream> // команда для того, чтобы работали все команды С++
#include <string> // чтобы работали строки

#include <cstdlib>

#include <stdio.h>
#include <Windows.h>
#include <fstream> // библиотека работы с файлами

using namespace std; // команда для доп команд


string lib; //алфавит

string MakeLib()
{
	for (int i = 65; i < 91; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 97; i < 123; i++) //маленькие буквы
	{
		lib += (char)i;
	}
	for (int i = 48; i < 58; i++) //цифры
	{
		lib += (char)i;
	}
	for (int i = 192; i < 224; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 224; i < 256; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 32; i < 48; i++) //спец симловы 1
	{
		lib += (char)i;
	}
	for (int i = 58; i < 65; i++) //спец симловы 2
	{
		lib += (char)i;
	}
	for (int i = 91; i < 97; i++) //спец симловы 3
	{
		lib += (char)i;
	}
	for (int i = 123; i < 127; i++) //спец симловы 4
	{
		lib += (char)i;
	}
	return lib;
}

string defaultTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\defaultText.txt";
string encryptedTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\encryptedText.txt";
string decryptedTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\decryptedText.txt";

ifstream fileDefault; //создаём экземпляр класса для чтения из файла
fstream fileEncrypted; //создаём экземпляр класса для записи и чтения 
ofstream fileDecrypted; //создаём экземпляр класса для записи в файл

string defaultStr;
string encryptStr;
string decryptStr;

string encrypt(string str, string key)					//шифрование
{
	int temp;
	string encryptText;

	string newKey;
	int kp = 0;
	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j]) //находим букву в алфавите
			{
				newKey = key[kp];

				temp = (j + stoi(newKey)) % lib.length();
				encryptText += lib[temp];

				kp++;
				count++;
				if (kp == key.length())
				{
					kp = 0;
				}
				else if (count == str.length())
				{
					break;
				}
			}
		}
	}
	fileEncrypted << encryptText;
	cout << encryptText;
	return encryptText;
}

string decrypt(string str, string key)					//дешифрование
{
	int temp;
	string decryptText;

	string newKey;
	int kp = 0;
	int count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < lib.length(); j++)
		{
			if ((char)str[i] == lib[j]) //находим букву в алфавите
			{
				if ((char)str[i] == lib[j])
				{
					newKey = key[kp];

					temp = j - stoi(newKey);
					if (temp < 0)
					{
						temp += lib.length();
					}
					else
					{
						temp = (j - stoi(newKey)) % lib.length();
					}

					decryptText += lib[temp];
					kp++;
					count++;

					if (kp == key.length())
					{
						kp = 0;
					}
					else if (count == str.length())
					{
						break;
					}
				}
			}
		}
	}
	fileDecrypted << decryptText;
	cout << decryptText;
	return decryptText;
}

bool CheckNum(string str) //isdigit цифра = 1 буква = 0
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			cout << "error" << endl;
			return false;
		}
	}
	return true;
}


int main()
{
	setlocale(LC_ALL, "Russian"); // подключить русский язык

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MakeLib();

	string key = "";
	int choice = 0;

	cout << "Вас приветствует программа, которая поможет вам\n\tработать с шифром Гронсвельда!" << endl;

	while (true)
	{
		cout << endl;
		cout << "С помощью консольного меню выберите что сделать:" << endl;
		cout << "1. Зашифровать текст с файла defaultText в encryptedText" << endl;
		cout << "2. Дешифровать текст в файл decryptedText" << endl;
		cout << "3. Выйти" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;

		system("CLS");

		if (choice == 1)
		{
			fileDefault.open(defaultTextWay);
			fileEncrypted.open(encryptedTextWay);

			if (fileDefault.fail()) //был ли открыт файл или нет
			{
				cout << "error opening default file!" << endl;
				return 1;
			}
			if (fileDecrypted.fail()) //был ли открыт файл или нет
			{
				cout << "error opening decrypted file!" << endl;
				return 1;
			}

			while (!fileDefault.eof())
			{
				string line;
				getline(fileDefault, line);
				defaultStr += line + "\n";
			}
			cout << "Ваш текст из файла defaultText:" << endl;
			cout << defaultStr << endl;

			cout << "Вы выбрали функцию шифрования вашего текста с помощью шифра Гронсвельда!" << endl;

			cout << "Введите ключ, с помощью которого мы зашифруем ваш текст: ";
			cin >> key;


			if (CheckNum(key))
			{
				cout << "Ваш зашифрованный текст находится в файле encryptedText!" << endl;
				encrypt(defaultStr, key);
			}
			else
			{
				cout << "key error" << endl;
			}

			fileDefault.close();
			fileEncrypted.close();
		}
		else if (choice == 2)
		{
			fileEncrypted.open(encryptedTextWay);
			fileDecrypted.open(decryptedTextWay);

			if (fileEncrypted.fail()) //был ли открыт файл или нет
			{
				cout << "error opening encrypted file!" << endl;
				return 1;
			}
			if (fileDecrypted.fail()) //был ли открыт файл или нет
			{
				cout << "error opening decrypted file!" << endl;
				return 1;
			}

			while (!fileEncrypted.eof())
			{
				string line;
				getline(fileEncrypted, line);
				encryptStr += line + "\n";
			}
			cout << "Ваш текст из файла encryptedText:" << endl;
			cout << encryptStr << endl;

			cout << "Вы выбрали функцию дешифрования вашего текста, который был зашифрован с помощью шифра Гронсвельда!" << endl;

			cout << "Введите ключ, с помощью которого был зашифрован текст: ";
			cin >> key;

			if (CheckNum(key))
			{
				cout << "Ваш дешифрованный текст находится в файле decryptedText!" << endl;
				decrypt(encryptStr, key);
			}
			else
			{
				cout << "key error" << endl;
			}

			fileEncrypted.close();
			fileDecrypted.close();
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			cout << "Такой функции не существует! Выберите другую!" << endl;
			cout << endl;
		}
	}



	system("pause");
	return 0;
}

