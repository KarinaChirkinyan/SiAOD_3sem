#include "bin.h"

//Подготовить тестовые данные в текстовом файле с кодировкой ASCII,
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	string fileName = "", fileNameBin = "", s = "";
	int menu = 1;
	int n = 0;
	while (menu != -1) {
		cout << "Выберите с каким файлом будете работать: 1 - текстовый, 2 - двоичный\n";
		cout << "Введите число: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "1 - Создание текстового файла." << endl;
			cout << "2 - Вывод содержимого текстового файла." << endl;
			cout << "3 - Добавление новой строки в конец файла." << endl;
			cout << "4 - Прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение." << endl;
			cout << "5 - Определить количество чисел в файле." << endl;
			cout << "6 - Создание квадратной матрицы из значений исходного файла" << endl;
			while (menu != 0) {
				cout << "Введите номер задания: ";
				cin >> menu;
				switch (menu)
				{
				case 1:	 // создание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке
					cout << "Введите название файла с расширением: ";
					cin >> fileName;
					createTextFile(fileName);
					break;


				case 2:  // вывод содержимого текстового файла
					printTextFile(fileName);
					break;


				case 3:  // добавление новой строки в конец файла
					cout << "Введите новую строку:" << endl;
					getline(cin, s);
					getline(cin, s);
					openWriteInEndTextFile(fileName, s);
					break;


				case 4:  // прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение
					cout << "Введите номер цифры:" << endl;
					cin >> n;
					pullNumberInTextFile(fileName, n);
					break;


				case 5:  // определить количество чисел в файле
					cout << "Ваше число: " << countNumbersInTextFile(fileName) << endl;
					break;

				case 6:  // создание квадратной матрицы
					matrix(fileName);
					break;
				}
			}
			break;

		case 2:
			string fileText = "kass.txt";
			string fileBin = "";
			kass k;
			cout << "1 - Преобразование тестовых данных из текстового файла в двоичный файл." << endl;
			cout << "2 - Преобразование данных из двоичного файла в текстовый." << endl;
			cout << "3 - Вывод всех записей двоичного файла." << endl;
			cout << "4 - Удалить записи с заданным значением ключа" << endl;
			cout << "5 - Чтение записи по по заданному номеру в файле" << endl;
			cout << "6 - Увеличить скидку на товар на 2% от цены товара на заданной кассе" << endl;
			while (menu != 0) {
				cout << "Введите номер задания: ";
				cin >> menu;
				switch (menu)
				{
				case 1:  // преобразование тестовых данных из текстового файла в двоичный файл
					cout << "Введите название файла с расширением: ";
					cin >> fileBin;
					readStructFromTextToBin(fileText, fileBin);
					break;


				case 2:  // преобразование данных из двоичного файла в текстовый
					readStructFromBinToText(fileText, fileBin);
					printTextFile(fileText);
					break;


				case 3:  // вывод всех записей двоичного файла
					outputBinFile(fileBin);
					break;


				case 4:  // Удалить сведения о пациенте с заданным ключом, сохраняя порядок следования остальных записей.
					cout << "Введите номер полиса для удаления данных по нему:" << endl;
					cin >> n;
					DeleteLineBinFile(fileBin, n);
					outputBinFile(fileBin);
					break;


				case 5:  // доступ к записи по ее порядковому номеру в файле
					cout << "Введите порядковый номер записи:" << endl;
					cin >> n;
					outputNode(fileBin, n, &k);
					break;


				case 6:  //Увеличить скидку на товар на 2 % от цены товара на заданной кассе
					cout << "Введите номер кассы: " << endl;
					cin >> n;
					newDiscont(fileBin, n);
				}
			}
		}
		break;
	}

}
