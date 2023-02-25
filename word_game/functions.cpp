#include<iostream>
#include "mylibrary.h"
#include <string>
#include <fstream>
#include<iomanip>
#include<locale>
#include<Windows.h>

using namespace std;

void animals() {
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	int flag = 0, flag2 = 0, flag3 = 1, count = 0, k = 1, random = rand() % 214 + 1;
	string word_User, word_bot, word_file[100];
	char last_symbol, last_symbol_bot;
	ifstream f;
	f.open("animals.txt");
	cout << "\t\t====================\n\t\t||  ИГРА В СЛОВА  ||\n\t\t|| Тема: Животные ||\n\t\t====================\n";
	cout << " _________________________________________________ \n|Введите 'правила', чтобы посмотреть правила игры.|\n|Введите 'выход', чтобы выйти в меню.             |\n|{Win + Space} - поменять раскладку               |\n|_________________________________________________|\n";
	do {
		word_User = "";
		if (flag2 == 0) {
			int random = rand() % 214 + 1;
			for (int i = 0; i < random; i++) {
				f >> word_bot;
			}
			cout << "| " << word_bot << " |";
			flag2 = 1;
			word_file[0] = word_bot;
			f.seekg(0);
		}

		if (word_bot[word_bot.size() - 1] == 'ь' || word_bot[word_bot.size() - 1] == 'й') {
			last_symbol_bot = word_bot[word_bot.size() - 2];
		}
		else { last_symbol_bot = word_bot[word_bot.size() - 1]; }
		flag3 = 1;
		do {
			cout << " ('" << last_symbol_bot << "') -> ";
			cin >> word_User;
			word_User[0] = tolower(word_User[0]);
			flag3 = 1;
			for (int i = 0; i < 100; i++) {
				if (word_file[i] == word_User) {
					flag3 = 0;
					cout << " ___________________________________________________________\n|Введенное вами слово уже было использовано. Введите другое.|\n|___________________________________________________________|" << endl;
				}
			}
			if (word_User == "правила") {
				rules();
			}
		} while (word_User[0] != last_symbol_bot && word_User != "выход" || flag3 == 0);
		if (word_User != "выход") {
			word_file[k] = word_User;
			k++;
			count += 5;
			word_User[word_User.size() - 1] = tolower(word_User[word_User.size() - 1]);

			if (word_User[word_User.size() - 1] == 'ь' || word_User[word_User.size() - 1] == 'й') {
				last_symbol = word_User[word_User.size() - 2];
			}
			else { last_symbol = word_User[word_User.size() - 1]; }

			word_bot = "";
			while (!f.eof() && last_symbol != word_bot[0]) {
				f >> word_bot;
				for (int i = 0; i < 100; i++) {
					if (word_file[i] == word_bot) {
						word_bot = "";
						f >> word_bot;
					}
				}
				if (last_symbol == word_bot[0] && flag3 == 1) {
					flag = 1;
					word_file[k] = word_bot;
					k++;
					cout << "| " << word_bot << " |";
					f.seekg(0);
				}
			}
		}
		else {
			cout << "Выход из игры. " << endl << "Вы набрали " << count << " очков." << endl; break;
		}
		if (flag == 0) { cout << "Я не знаю больше слов. Ты победил..." << endl; break; }
		flag = 0;
	} while (word_User != "выход");

	f.seekg(0);
	ofstream f1;
	f1.open("animals.txt", ios::app);
	while (!f.eof()) {
		f >> word_bot;
		for (int i = 1; i < k; i += 2) {
			if (word_file[i] == word_bot)word_file[i] = "";
		}
		word_bot = "";
	}
	for (int i = 1; i < k; i +=2 ) {
		f1 << "\n" << word_file[i] << " ";
	}
	f1.close();
	f.close();
}

void cities() {
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	int flag = 0, flag2 = 0, flag3 = 1, count = 0, k = 1, random = rand() % 344 + 1;
	string word_User, word_bot, word_file[100];
	char last_symbol, last_symbol_bot;
	ifstream f;
	f.open("cities.txt");
	cout << "\t\t====================\n\t\t||  ИГРА В СЛОВА  ||\n\t\t||  Тема: Города  ||\n\t\t====================\n";
	cout << " _________________________________________________ \n|Введите 'правила', чтобы посмотреть правила игры.|\n|Введите 'выход', чтобы выйти в меню.             |\n|{Win + Space} - поменять раскладку               |\n|_________________________________________________|\n";
	do {
		word_User = "";
		if (flag2 == 0) {
			int random = rand() % 214 + 1;
			for (int i = 0; i < random; i++) {
				f >> word_bot;
			}
			cout << "| " << word_bot <<" |";
			flag2 = 1;
			word_file[0] = word_bot;
			f.seekg(0);
		}

		if (word_bot[word_bot.size() - 1] == 'ь' || word_bot[word_bot.size() - 1] == 'ъ') {
			last_symbol_bot = word_bot[word_bot.size() - 2];
		}
		else { last_symbol_bot = word_bot[word_bot.size() - 1]; }
		flag3 = 1;
		do {
			cout <<" ('" << last_symbol_bot << "') -> ";
			cin >> word_User;
			word_User[0] = tolower(word_User[0]);
			flag3 = 1;
			for (int i = 0; i < 100; i++) {
				if (word_file[i] == word_User) {
					flag3 = 0;
					cout << " ___________________________________________________________\n|Введенное вами слово уже было использовано. Введите другое.|\n|___________________________________________________________|" << endl;
				}
			}
			if (word_User == "правила") {
				rules();
			}
		} while (word_User[0] != last_symbol_bot && word_User != "выход" || flag3 == 0);
		if (word_User != "выход") {
			word_file[k] = word_User;
			k++;
			count += 5;
			word_User[word_User.size() - 1] = tolower(word_User[word_User.size() - 1]);

			if (word_User[word_User.size() - 1] == 'ь' || word_User[word_User.size() - 1] == 'ъ') {
				last_symbol = word_User[word_User.size() - 2];
			}
			else { last_symbol = word_User[word_User.size() - 1]; }

			word_bot = "";
			while (!f.eof() && last_symbol != word_bot[0]) {
				f >> word_bot;
				for (int i = 0; i < 100; i++) {
					if (word_file[i] == word_bot) {
						word_bot = "";
						f >> word_bot;
					}
				}
				if (last_symbol == word_bot[0] && flag3 == 1) {
					flag = 1;
					word_file[k] = word_bot;
					k++;
					cout << "| " << word_bot << " |";
					f.seekg(0);
				}
			}
		}
		else {
			cout << "Выход из игры. " << endl << "Вы набрали " << count << " очков." << endl; break;
		}
		if (flag == 0) { cout << "Я не знаю больше слов. Ты победил..." << endl; break; }
		flag = 0;
	} while (word_User != "выход");

	f.seekg(0);
	ofstream f1;
	f1.open("animals.txt", ios::app);
	while (!f.eof()) {
		f >> word_bot;
		for (int i = 1; i < k; i += 2) {
			if (word_file[i] == word_bot)word_file[i] = "";
		}
		word_bot = "";
	}
	for (int i = 1; i < k; i +=2 ) {
		f1 << "\n" << word_file[i] << " ";
	}
	f1.close();
	f.close();
}

void count() {
	srand(time(NULL));
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	int flag = 0, flag2 = 0, flag3 = 1, count = 0, k = 1, random = rand() % 550 + 1;
	string word_User, word_bot, word_file[100];
	char last_symbol, last_symbol_bot;
	ifstream f;
	f.open("count.txt");
	cout << "\t\t====================\n\t\t||  ИГРА В СЛОВА  ||\n\t\t|| Тема: Растения ||\n\t\t====================\n";
	cout << " _________________________________________________ \n|Введите 'правила', чтобы посмотреть правила игры.|\n|Введите 'выход', чтобы выйти в меню.             |\n|{Win + Space} - поменять раскладку               |\n|_________________________________________________|\n";
	do {
		word_User = "";
		if (flag2 == 0) {
			int random = rand() % 214 + 1;
			for (int i = 0; i < random; i++) {
				f >> word_bot;
			}
			cout << "| " << word_bot << " |";
			flag2 = 1;
			word_file[0] = word_bot;
			f.seekg(0);
		}

		if (word_bot[word_bot.size() - 1] == 'ь' || word_bot[word_bot.size() - 1] == 'ъ') {
			last_symbol_bot = word_bot[word_bot.size() - 2];
		}
		else { last_symbol_bot = word_bot[word_bot.size() - 1]; }
		flag3 = 1;
		do {
			cout << " ('" << last_symbol_bot << "') -> ";
			cin >> word_User;
			word_User[0] = tolower(word_User[0]);
			flag3 = 1;
			for (int i = 0; i < 100; i++) {
				if (word_file[i] == word_User) {
					flag3 = 0;
					cout << " ___________________________________________________________\n|Введенное вами слово уже было использовано. Введите другое.|\n|___________________________________________________________|" << endl;
				}
			}
			if (word_User == "правила") {
				rules();
			}
		} while (word_User[0] != last_symbol_bot && word_User != "выход" || flag3 == 0);
		if (word_User != "выход") {
			word_file[k] = word_User;
			k++;
			count += 5;
			word_User[word_User.size() - 1] = tolower(word_User[word_User.size() - 1]);

			if (word_User[word_User.size() - 1] == 'ь' || word_User[word_User.size() - 1] == 'ъ') {
				last_symbol = word_User[word_User.size() - 2];
			}
			else { last_symbol = word_User[word_User.size() - 1]; }

			word_bot = "";
			while (!f.eof() && last_symbol != word_bot[0]) {
				f >> word_bot;
				for (int i = 0; i < 100; i++) {
					if (word_file[i] == word_bot) {
						word_bot = "";
						f >> word_bot;
					}
				}
				if (last_symbol == word_bot[0] && flag3 == 1) {
					flag = 1;
					word_file[k] = word_bot;
					k++;
					cout << "| " << word_bot << " |";
					f.seekg(0);
				}
			}
		}
		else {
			cout << "Выход из игры. " << endl << "Вы набрали " << count << " очков." << endl; break;
		}
		if (flag == 0) { cout << "Я не знаю больше слов. Ты победил..." << endl; break; }
		flag = 0;
	} while (word_User != "выход");

	f.seekg(0);
	ofstream f1;
	f1.open("animals.txt", ios::app);
	while (!f.eof()) {
		f >> word_bot;
		for (int i = 1; i < k; i += 2) {
			if (word_file[i] == word_bot)word_file[i] = "";
		}
		word_bot = "";
	}
	for (int i = 1; i < k; i +=2 ) {
		f1 << "\n" << word_file[i] << " ";
	}
	f1.close();
	f.close();
}

void result(int& a, int& b) {

}

void rules() {
	cout << " _____________________________________________________________________________________________________________________ \n";
	cout << "|Игра между пользователем и компьютером.                                                                              |\n";
	cout << "|Игру начинает компьютер, выводя некоторое слово в соответствии с выбраной вами тематикой игры.                       |\n";
	cout << "|Следующее вводимое слово должно начинаться с последней буквы предыдущего слова('ь' не учитывается).                  |\n";
	cout << "|За каждое правильно введенное слово вам добавляется 5 очков.                                                         |\n";
	cout << "|Ввод должен происходить строчными буквами алфавита русского языка.                                                   |\n";
	cout << "|На вход проверяется только первое слово. Если вы хотите написать название из двух слов, то используйте '_'.          |\n";
	cout << "|_____________________________________________________________________________________________________________________|" << endl;
}

