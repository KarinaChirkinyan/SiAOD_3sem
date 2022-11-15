#include "text.h"


// Структура записи "Касса магазина"
struct kass {
	unsigned int numKass = 0, kodProduct = 0, kolProduct = 0, priceProduct = 0, discont = 0;  // номер кассы, код товара, количество товара, цена товара, скидка на товар
	unsigned int summ = 0;  // сумма с учетом скидки
	//unsigned int day = 0, month = 0, year = 0;  // дата
};


bool isName2(string name) {
	if (name == "") {
		cout << "Не задано имя файла!" << endl;
		return 0;
	}
	else return 1;
}


void readStructFromTextToBin(string fileNameText, string fileNameBin) // преобразование тестовых данных из текстового файла в двоичный файл
{
	//При открытии файла обеспечить контроль существования и открытия файла.
	ifstream ft; 
	ft.open(fileNameText);
	ofstream fb; 
	fb.open(fileNameBin, ios::binary | ios::out | ios::trunc);
	kass k; 
	int n = 0; 
	k.numKass = -1;
	if (ft.is_open()) {
		while (!ft.eof()) {
			ft >> n;
			if (k.numKass != n) k.numKass = n;
			else return;
			ft >> k.kodProduct;
			ft >> k.kolProduct;
			ft >> k.priceProduct;
			ft >> k.discont;
			ft >> k.summ;
			ft.get();

			//Запись в двоичный файл
			fb.write((char*)&k, sizeof(kass));
		}
	}
	else {
		isName2(fileNameText);
		isName2(fileNameBin);
	}
	ft.close();
	fb.close();
}


void readStructFromBinToText(string fileNameText, string fileNameBin) {  // преобразование данных из двоичного файла в текстовый
	//При открытии файла обеспечить контроль существования и открытия файла.
	ifstream fb;
	ofstream ft;
	fb.open(fileNameBin, ios::binary);
	ft.open(fileNameText, ios::out | ios::trunc);

	kass k;
	if (fb.is_open()) {
		fb.read((char*)&k, sizeof(kass));
		while (!fb.eof()) {
			ft << k.numKass << " ";
			ft << k.kodProduct << " ";
			ft << k.kolProduct << " ";
			ft << k.priceProduct << " ";
			ft << k.discont << " ";
			ft << k.summ << " ";
			ft << endl;
			fb.read((char*)&k, sizeof(kass));
		}
	}
	else {
		isName2(fileNameText);
		isName2(fileNameBin);
	}
	ft.close();
	fb.close();
}


void outputBinFile(string fileNameBin) {  // вывод всех записей двоичного файла
	ifstream fb;
	fb.open(fileNameBin, ios::binary | ios::in);
	kass k;
	if (fb.is_open()) {
		fb.read((char*)&k, sizeof(kass));
		while (!fb.eof()) {
			cout << k.numKass << " " << k.kodProduct << " " << k.kolProduct << " " << k.priceProduct << " " << k.discont << " " << k.summ;
			cout << endl;
			fb.read((char*)&k, sizeof(kass));
		}
		cout << endl;
	}
	else {
		isName2(fileNameBin);
	}
	fb.close();
}

int c(string fileNameBin) {  // Номер записи
	ifstream fb;
	int i = 0;
	fb.open(fileNameBin, ios::binary | ios::in);
	kass k;
	if (fb.is_open()) {
		fb.read((char*)&k, sizeof(kass));
		while (!fb.eof()) {
			i++;
			fb.read((char*)&k, sizeof(kass));
		}
	}
	else {
		isName2(fileNameBin);
	}
	fb.close();
	return i;
}

// Доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле;
// При применении механизма прямого доступа к записи файла выполнить контроль присутствия записи с заданным номером в файле.
void outputNode(string fileNameBin, int n, kass* k) {
	ifstream fb;
	fb.open(fileNameBin, ios::binary | ios::in);
	kass k_local;
	if (n > c(fileNameBin)) { cout << "Нет записи с таким номером" << endl; }
	else{
		if (fb.is_open()) {
			fb.seekg((n - 1) * sizeof(kass), ios::beg);
			fb.read((char*)&k_local, sizeof(kass));
			(*k) = k_local;
			cout << "Ваша запись:" << endl;
			cout << k_local.numKass << " " << k_local.kodProduct << " " << k_local.kolProduct << " " << k_local.priceProduct << " " << k_local.discont << " " << k_local.summ;
			cout << endl;
		}
		else {
			isName2(fileNameBin);
		}
	}

	fb.close();
}


void DeleteLineBinFile(string fileNameBin, int numKass) {  // удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись.
	fstream fb;
	fb.open(fileNameBin, ios::out | ios::in | ios::binary);

	kass k;
	kass k_last;
	if (fb.is_open()) {
		fb.seekg((c(fileNameBin) - 1) * sizeof(kass), ios::beg);
		fb.read((char*)&k_last, sizeof(kass));  // сохраняем последнюю запись
		int i = 0;
		fb.seekg(0 * sizeof(kass), ios::beg);  // ставим курсор на начало
		while (!fb.eof()) {
			i++;
			fb.read((char*)&k, sizeof(kass));
			if (k.numKass == numKass) {
				fb.seekg(sizeof(kass) * (i - 1), ios::beg);  // Запись в файл
				fb.write((char*)&k_last, sizeof(kass));  // Замена необходимой записи на последнюю запись
				fb.close();
				return;
			}
		}
	}
	else {
		isName2(fileNameBin);
	}
	fb.close();
}

/*
string nFileName(string oldFileName) {
	return oldFileName.substr(0, oldFileName.size() - 4) + "1.txt";
}
*/

void newDiscont(string fileNameBin, int numKass) {
	ifstream fb;
	string newFName = "newFile.txt";
	fb.open(fileNameBin, ios::out | ios::in | ios::binary);
	ofstream fb_new; fb_new.open(newFName, ios::binary | ios::out | ios::trunc);

	kass k;
	if (fb.is_open() and fb_new.is_open()) {
		fb.seekg(0 * sizeof(kass), ios::beg);
		while (!fb.eof()) {
			fb.read((char*)&k, sizeof(kass));
			if (k.numKass == numKass) {
				k.discont += 2;
				float d = k.discont;
				k.summ = k.priceProduct * (1 - d / 100);
				cout << "Новая запись: " << endl;
				fb_new.write((char*)&k, sizeof(kass));  // Запись в новый файл
			}
		}

	}
	else {
		isName2(fileNameBin);
	}
	fb.close();
	fb_new.close();
	outputBinFile(newFName);
}