#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


bool isName(string name) {  // �������� �� ��,��� ������ ����
	if (name == "") return 0;
	else return 1;
}


void createTextFile(string fileName) {  // �������� ���������� �����
	ofstream f;
	// out - ������� ���� ��� �������� � ������ � ������ (��������� �� ������ ������);
	// trunc � �������� ����, ���� �� ����������;
	f.open(fileName, ios::out | ios::trunc);
	if (!f.good() or !f.is_open())	// �������� ������������� � �������� �����
	{
		cout << "������ ��� �������� �����";
		return;
	}
	int n = rand() % 5 + 5;
	for (int i = 0; i < n; i++) {
		// ���������� ����� �������
		int m = rand() % 10 + 10;
		for (int j = 0; j < m; j++) {
			f << rand() % 15 << " ";
		}
		f << endl;
	}
	f.close();
	return;
}


void printTextFile(string fileName) {  // ������� ���������� �����

	if (isName(fileName)) {
		string s;
		ifstream f(fileName);
		if (!f.good()) {  // �������� ������������� � �������� �����
			cout << "������ ��� �������� �����";
			return;
		}
		while (!f.eof())
		{
			getline(f, s);
			cout << s << endl;
		}
	}
	else {
		cout << "���� �� ������. ��� ������ �������� ����." << endl;
		return;
	}
}


void openWriteInEndTextFile(string fileName, string s) {  // ������� ������������ ���� ��� ������ � ����� (��������� � �����)
	if (isName(fileName)) {
		ofstream f;
		f.open(fileName, ios::app);
		if (!f.good()) {  // �������� ������������� � �������� �����
			cout << "������ ��� �������� �����";
			return;
		}
		else {
			f << s << endl;
		}
	}
	else {
		cout << "���� �� ������. ��� ������ �������� ����." << endl;
		return;
	}
}


int countNumbersInTextFile(string fileName) {  // ���������� ���������� ����� � �����
	if (isName(fileName)) {
		int n = 0;
		ifstream f(fileName);
		if (!f.good()) {  // �������� ������������� � �������� �����
			cout << "������ ��� �������� �����";
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
		cout << "���� �� ������. ��� ������ �������� ����." << endl;
		return -1;
	}
}


void pullNumberInTextFile(string fileName, int n) {  // ��������� �������� �����, ������ ��� ���������� ����� � �����, � ������� ��� ��������
	if (isName(fileName)) {
		ifstream f(fileName);
		if (!f.good()) {  // �������� ������������� � �������� �����
			cout << "������ ��� �������� �����";
			return;
		}
		int buf = 0;

		if (n <= countNumbersInTextFile(fileName)) {
			for (int i = 1; i <= n; i++) {
				f >> buf;
			}
			cout << "���� �����: " << buf << endl;
		}
		else { cout << "��� ������ �����." << endl; }
	}
	else {
		cout << "���� �� ������. ��� ������ �������� ����." << endl;
		return;
	}
}


void matrix(string fileName) {  // �������� ���������� �������
	int i, n, num, matrixSize;
	n = countNumbersInTextFile(fileName);
	if (isName(fileName)) {
		ifstream f(fileName);
		if (!f.good()) {  // �������� ������������� � �������� �����
			cout << "������ ��� �������� �����" << endl;
			return;
		}
		int* numbers = new int[n];
		i = 0;  // �������
		while (f >> num) {  // ��������� ������
			numbers[i++] = num;
		}

		matrixSize = floor(sqrt(n));  // ������� ������ ���������� �������
		ofstream newFile;  // �������� ������ �����
		// out - ������� ���� ��� �������� � ������ � ������ (��������� �� ������ ������);
		// trunc � �������� ����, ���� �� ����������;
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
		cout << "���� �� ������. ��� ������ �������� ����." << endl;
		return;
	}
}