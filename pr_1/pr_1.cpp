#include <iostream>
#include <iomanip>
using namespace std;

int bit_disjunction(int a, int b) {  // функция для поразрядной дизъюнкции
    return a | b;
}

int bit_conjunction(int a, int b) {  // функция для поразрядной конъюнкции
	return a & b;
}

int multiplication(int a, int b) {  // функция для побитового сдвига влево
	return a << b;
}

int division(int a, int b) {  // функция для побитового сдвига вправо
	return a >> b;
}

void coutp(unsigned int x)  // вывод в двоичной СС
{
	int n = sizeof(int) * 8;
	unsigned  maska = (1 << (n - 1));

	for (int i = 1; i <= n; i++)
	{
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	cout << setw(3) << " ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    long long int number = 0x412;  // ... 0100 0001 0010
    long long int mask = 0xE8;  // ... 1110 1000

    cout << "Задание 1.1: установить в значение 1 с 7-ого бита пять слева" << endl;
    cout << setw(10) << "Number: "; coutp(number); cout << endl;
	cout << setw(10) << "Mask: "; coutp(mask); cout << endl;
	cout << setw(10) << "Result: "; coutp(bit_disjunction(number, mask)); cout << "\n\n";

	long long int number2;
	long long int mask2 = 0xFFFFF75F;  // ... 0111 0101 1111

	cout << "Задание 1.2: установить в значение 0 5-ый, 7-ой, 11-ый биты" << endl;
	cout << "Введите число в 16-ичной СС: "; cin >> hex >> number2;
	cout << setw(10) << "Number: "; coutp(number2); cout << endl;
	cout << setw(10) << "Mask: "; coutp(mask2); cout << endl;
	cout << setw(10) << "Result: "; coutp(bit_conjunction(number2, mask2)); cout << "\n\n";

	long long int number3;

	cout << "Задание 1.3: умножить на 32" << endl;  // 32 = 2^5
	cout << "Введите число в 16-ичной СС: "; cin >> hex >> number3;
	cout << setw(10) << "Number: "; coutp(number3); cout << endl;
	cout << setw(10) << "Result: "; coutp(multiplication(number3, 5)); cout << "\n\n";

	long long int number4;

	cout << "Задание 1.4: разделить на 32" << endl;  // 32 = 2^5
	cout << "Введите число в 16-ичной СС: "; cin >> hex >> number4;
	cout << setw(10) << "Number: "; coutp(number4); cout << endl;
	cout << setw(10) << "Result: "; coutp(division(number4, 5)); cout << "\n\n";

	long long int number5;
	long long int mask5 = 0x01;
	unsigned int x;

	cout << "Задание 1.5: установить n-ый бит в значение 0" << endl;
	cout << "Введите число в 16-ичной СС: "; cin >> hex >> number5;
	cout << "Введите n-ый бит: "; cin >> x;
	mask5 = mask5 << x;
	mask5 = ~mask5;
	cout << setw(10) << "Number: "; coutp(number5); cout << endl;
	cout << setw(10) << "Mask: "; coutp(mask5); cout << endl;
	cout << setw(10) << "Result: "; coutp(bit_conjunction(number5, mask5)); cout << "\n\n";
}
