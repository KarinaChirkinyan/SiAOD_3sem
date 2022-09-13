#include <iostream>
#include <fstream>
#include <bitset> 
#include <vector>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

class Stopwatch {
    chrono::steady_clock::time_point point;
    chrono::nanoseconds dim;
public:
    void start_countdown() {
        point = chrono::steady_clock::now();
    }
    double get_milliseconds() {
        dim = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - point);
        return (double)dim.count() / 1'000'000;
    }
};

const int N = 10000000;
void outSort(fstream& f, bitset<N>* set = nullptr, unsigned int* arr = nullptr);
void sorting_by_bitarray();
void fill_storage_random(int n, bitset<N>* set = nullptr, unsigned int* arr = nullptr);

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    system("cls");
    sorting_by_bitarray();
}

void fill_storage_random(int n, bitset<N>* set, unsigned int* arr) {
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<unsigned int> dist(1'000'000, 9'999'999);
    if (set) {
        for (int i = 0; i < n; i++)
            set->set(dist(rng));

    }
    else {
        unsigned int t;
        for (int i = 0; i < n; i++) {
            t = dist(rng);
            arr[t / 32] |= (1 << t % 32);
        }
    }
}

void sorting_by_bitarray() {
    Stopwatch s;
    fstream f;
    unsigned int t = 0, * arr = new unsigned int[N / 32]{ 0 };
    int n;
    /*
    cout << "Введите количество чисел: ";  // ручной ввод
    cin >> n;
    s.start_countdown();
    for (int i = 0; i < n; i++) {
        cin >> t;
        arr[t / 32] |= (1 << t % 32);
    }
    */
    
    cout << "Введите количество чисел: ";  // заполнение рандомными числами
    cin >> n;
    s.start_countdown();
    fill_storage_random(n, nullptr, arr);
    

    outSort(f, nullptr, arr);
    cout << "\nВремя выполнения: " << s.get_milliseconds() << "ms\n";

    delete[] arr;
}

void outSort(fstream& f, bitset<N>* set, unsigned int* arr) {
    if (set) {
        f.open("sortS.txt", ios::out);
        for (int i = 0; i < N; i++)
            if (set->test(i) == 1) {
                f << i << '\n';
                cout << i << ' ';
            }
        f.close();
    }
    else {
        f.open("sortA.txt", ios::out);
        for (int i = 0; i < N; i++)
            if ((arr[i / 32] & (1 << i % 32)) != 0) {
                f << i << '\n';
                cout << i << ' ';
            }
        f.close();
    }
}

