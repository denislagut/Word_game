#include <iostream>
#include <stdlib.h>
#include "mylibrary.h"
#include <locale>
#include <string>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "Ru");
	int choise;
	do {
		cout << " =========================================================== \n";
		cout << "||                       ИГРА В СЛОВА                      ||\n";
		cout << "||=========================================================||\n";
		cout << "||                        Темы игры                        ||\n";
		cout << "||               ___________________________               ||\n";
		cout << "||              |       [1] Животные        |              ||\n";
		cout << "||              |       [2]  Города         |              ||\n";
		cout << "||              |       [3] Растения        |              ||\n";
		cout << "||              |___________________________|              ||\n";
		cout << "||                                                         ||\n";
		cout << "||                      [4]{Правила}                       ||\n";
		cout << "||                      [0]  Выход                         ||\n";
		cout << "||                                                         ||\n";
		cout << " =========================================================== \n";
		cout << " >> ";
		cin >> choise;
		switch (choise)
		{
		case 1:animals(); break;
		case 2:cities(); break;
		case 3:count(); break;
		case 4:rules(); break;
		case 0:cout << "Выход из игры." << endl; break;
		default: cout << "Введено неверное значение. Попробуйте еще раз." << endl; break;
		}

	} while (choise != 0);
	system("pause");
	return 0;
}