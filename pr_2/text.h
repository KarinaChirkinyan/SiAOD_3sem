#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


bool isName(string name) {  // проверка на то,что создан файл
	if (name == "") return 0;
	else return 1;
}


void createTextFile(string fileName) {  // создание текстового файла
	ofstream f;
	// out - открыть файл для создания и записи в начало (указатель на первую запись);
	// trunc – очистить файл, если он существует;
	f.open(fileName, ios::out | ios::trunc);
	if (!f.good() or !f.is_open())	// проверка существования и открытия файла
	{
		cout << "Ошибка при открытии файла";
		return;
	}
	int n = rand() % 5 + 5;
	for (int i = 0; i < n; i++) {
		// заполнение файла цифрами
		int m = rand() % 10 + 10;
		for (int j = 0; j < m; j++) {
			f << rand() % 15 << " ";
		}
		f << endl;
	}
	f.close();
	return;
}


void printTextFile(string fileName) {  // вывести содержимое файла

	if (isName(fileName)) {
		string s;
		ifstream f(fileName);
		if (!f.good()) {  // проверка существования и открытия файла
			cout << "Ошибка при открытии файла";
			return;
		}
		while (!f.eof())
		{
			getline(f, s);
			cout << s << endl;
		}
	}
	else {
		cout << "Файл не создан. Для начала создайте файл." << endl;
		return;
	}
}


void openWriteInEndTextFile(string fileName, string s) {  // открыть существующий файл для записи в конец (указатель в конец)
	if (isName(fileName)) {
		ofstream f;
		f.open(fileName, ios::app);
		if (!f.good()) {  // проверка существования и открытия файла
			cout << "Ошибка при открытии файла";
			return;
		}
		else {
			f << s << endl;
		}
	}
	else {
		cout << "Файл не создан. Для начала создайте файл." << endl;
		return;
	}
}


int countNumbersInTextFile(string fileName) {  // определить количество чисел в файле
	if (isName(fileName)) {
		int n = 0;
		ifstream f(fileName);
		if (!f.good()) {  // проверка существования и открытия файла
			cout << "Ошибка при открытии файла";
			return -1;
		}
		int buf;
		while (!f.eof())
		{
			f >> buf;
			n++;
		}
		return n - 1;
	}
	else {
		cout << "Файл не создан. Для начала создайте файл." << endl;
		return -1;
	}
}


void pullNumberInTextFile(string fileName, int n) {  // прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение
	if (isName(fileName)) {
		ifstream f(fileName);
		if (!f.good()) {  // проверка существования и открытия файла
			cout << "Ошибка при открытии файла";
			return;
		}
		int buf = 0;

		if (n <= countNumbersInTextFile(fileName)) {
			for (int i = 1; i <= n; i++) {
				f >> buf;
			}
			cout << "Ваше число: " << buf << endl;
		}
		else { cout << "Нет такого числа." << endl; }
	}
	else {
		cout << "Файл не создан. Для начала создайте файл." << endl;
		return;
	}
}


void matrix(string fileName) {  // создание квадратной матрицы
	int i, n, num, matrixSize;
	n = countNumbersInTextFile(fileName);
	if (isName(fileName)) {
		ifstream f(fileName);
		if (!f.good()) {  // проверка существования и открытия файла
			cout << "Ошибка при открытии файла" << endl;
			return;
		}
		int* numbers = new int[n];
		i = 0;  // счетчик
		while (f >> num) {  // заполняем массив
			numbers[i++] = num;
		}

		matrixSize = floor(sqrt(n));  // считаем размер квадратной матрицы
		ofstream newFile;  // создание нового файла
		// out - открыть файл для создания и записи в начало (указатель на первую запись);
		// trunc – очистить файл, если он существует;
		newFile.open("matrix.txt", ios::out | ios::trunc);

		int k = 0;
		for (int i = 0; i < matrixSize*matrixSize; i++) {
			if (k % matrixSize == 0 && k != 0) {
				newFile << "\n";
				newFile << numbers[k] << " ";
				k++;
			}
			else {
				newFile << numbers[k] << " ";
				k++;
			}
		}
	}
	else {
		cout << "Файл не создан. Для начала создайте файл." << endl;
		return;
	}
}