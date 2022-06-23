#include <iostream> // ������� ��� ����, ����� �������� ��� ������� �++
#include <string> // ����� �������� ������

#include <cstdlib>

#include <stdio.h>
#include <Windows.h>
#include <fstream> // ���������� ������ � �������

using namespace std; // ������� ��� ��� ������


string lib; //�������

string MakeLib()
{
	for (int i = 65; i < 91; i++) //������� �����
	{
		lib += (char)i;
	}
	for (int i = 97; i < 123; i++) //��������� �����
	{
		lib += (char)i;
	}
	for (int i = 48; i < 58; i++) //�����
	{
		lib += (char)i;
	}
	for (int i = 192; i < 224; i++) //������� �����
	{
		lib += (char)i;
	}
	for (int i = 224; i < 256; i++) //������� �����
	{
		lib += (char)i;
	}
	for (int i = 32; i < 48; i++) //���� ������� 1
	{
		lib += (char)i;
	}
	for (int i = 58; i < 65; i++) //���� ������� 2
	{
		lib += (char)i;
	}
	for (int i = 91; i < 97; i++) //���� ������� 3
	{
		lib += (char)i;
	}
	for (int i = 123; i < 127; i++) //���� ������� 4
	{
		lib += (char)i;
	}
	return lib;
}

string defaultTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\defaultText.txt";
string encryptedTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\encryptedText.txt";
string decryptedTextWay = "C:\\for_Github_Projects\\Final_Exams\\Final_Works_Exams\\Encr_Decr_of_Gronsweld\\decryptedText.txt";

ifstream fileDefault; //������ ��������� ������ ��� ������ �� �����
fstream fileEncrypted; //������ ��������� ������ ��� ������ � ������ 
ofstream fileDecrypted; //������ ��������� ������ ��� ������ � ����

string defaultStr;
string encryptStr;
string decryptStr;

string encrypt(string str, string key)					//����������
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
			if ((char)str[i] == lib[j]) //������� ����� � ��������
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

string decrypt(string str, string key)					//������������
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
			if ((char)str[i] == lib[j]) //������� ����� � ��������
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

bool CheckNum(string str) //isdigit ����� = 1 ����� = 0
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
	setlocale(LC_ALL, "Russian"); // ���������� ������� ����

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MakeLib();

	string key = "";
	int choice = 0;

	cout << "��� ������������ ���������, ������� ������� ���\n\t�������� � ������ �����������!" << endl;

	while (true)
	{
		cout << endl;
		cout << "� ������� ����������� ���� �������� ��� �������:" << endl;
		cout << "1. ����������� ����� � ����� defaultText � encryptedText" << endl;
		cout << "2. ����������� ����� � ���� decryptedText" << endl;
		cout << "3. �����" << endl;
		cout << "��� �����: ";
		cin >> choice;

		system("CLS");

		if (choice == 1)
		{
			fileDefault.open(defaultTextWay);
			fileEncrypted.open(encryptedTextWay);

			if (fileDefault.fail()) //��� �� ������ ���� ��� ���
			{
				cout << "error opening default file!" << endl;
				return 1;
			}
			if (fileDecrypted.fail()) //��� �� ������ ���� ��� ���
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
			cout << "��� ����� �� ����� defaultText:" << endl;
			cout << defaultStr << endl;

			cout << "�� ������� ������� ���������� ������ ������ � ������� ����� �����������!" << endl;

			cout << "������� ����, � ������� �������� �� ��������� ��� �����: ";
			cin >> key;


			if (CheckNum(key))
			{
				cout << "��� ������������� ����� ��������� � ����� encryptedText!" << endl;
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

			if (fileEncrypted.fail()) //��� �� ������ ���� ��� ���
			{
				cout << "error opening encrypted file!" << endl;
				return 1;
			}
			if (fileDecrypted.fail()) //��� �� ������ ���� ��� ���
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
			cout << "��� ����� �� ����� encryptedText:" << endl;
			cout << encryptStr << endl;

			cout << "�� ������� ������� ������������ ������ ������, ������� ��� ���������� � ������� ����� �����������!" << endl;

			cout << "������� ����, � ������� �������� ��� ���������� �����: ";
			cin >> key;

			if (CheckNum(key))
			{
				cout << "��� ������������� ����� ��������� � ����� decryptedText!" << endl;
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
			cout << "����� ������� �� ����������! �������� ������!" << endl;
			cout << endl;
		}
	}



	system("pause");
	return 0;
}

