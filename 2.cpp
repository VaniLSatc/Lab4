#include <iostream>
#include <random>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int switch_numbers(int n) {
    string numStr = to_string(n);
    sort(numStr.begin(), numStr.end());
    return stoi(numStr);
}

vector<int> task1_arr1(mt19937_64& gen, uniform_int_distribution<int>& rand) {
    int n;
    while (true) {
        cout << "Введите n - количество элементов в векторе arr1. Значения n должны быть 15 <= n <= 30 !" << endl;
        cin >> n;
        if (n >= 15 && n <= 30) break;
    }

    cout << "Задание 1." << endl;
    vector<int> arr1(n);
    cout << "arr1: ";
    for (int i = 0; i < n; i++) {
        arr1[i] = rand(gen);
        cout << arr1[i] << " ";
    }
    cout << endl;
    return arr1;
}

vector<int> task1_arr2(mt19937_64& gen, uniform_int_distribution<int>& rand) {
    vector<int> arr2(5);
    cout << "arr2: ";
    for (int i = 0; i < 5; i++) {
        arr2[i] = rand(gen);
        cout << arr2[i] << " ";
    }
    cout << endl;
    return arr2;
}

void task2(const vector<int>& arr1) {
    cout << endl << "Задание 2." << endl;
    int count_chet_numbrs = 0;
    for (int i = 1; i < arr1.size(); i+=2) {
        if (arr1[i] % 2 == 0) {
            count_chet_numbrs++;
            cout << arr1[i] << " ";
        }
    }
    cout << endl << "Количество найденных элементов: " << count_chet_numbrs << endl;
}

void task3(const vector<int>& arr1, const vector<int>& arr2) {
    cout << endl << "Задание 3." << endl;
    map<int, int> freq;
    for (int i = 0; i < arr1.size(); i++) {
        freq[arr1[i]]++;
    }

    for (int i = 0; i < 5; i++) {
        if (freq.count(arr2[i])) {
            cout << "Число " << arr2[i] << " встречается в arr1 " << freq[arr2[i]] << " раз" << endl;
        }
        else {
            cout << "Число " << arr2[i] << " не встречается в arr1" << endl;
        }
    }
}

void task4(vector<int>& arr1) {
    cout << endl << "Задание 4." << endl;
    cout << "old arr1: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int first_element = arr1[0];
    for (int i = 0; i < arr1.size() - 1; i++) {
        arr1[i] = arr1[i + 1];
    }
    arr1[arr1.size() - 1] = first_element;

    cout << "new arr1: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

void task5(mt19937_64& gen, uniform_int_distribution<int>& rand5) {
    cout << endl << "Задание 5." << endl;
    int n = 0;
    while (true) {
        cout << "Введите n - количество элементов в векторе ARR. Количество должно быть >0 !" << endl;
        cin >> n;
        if (n > 0) break;
    }

    vector<int> ARR(n);
    int sum1 = 0;
    cout << "ARR: ";
    for (int i = 0; i < n; i++) {
        ARR[i] = rand5(gen);
        cout << ARR[i] << " ";
        sum1 += ARR[i];
    }
    cout << endl << "Сумма: " << sum1 << endl;

    for (int i = 0; i < n; i++) {
        ARR[i] = switch_numbers(ARR[i]);
    }
    sort(ARR.begin(), ARR.end());

    int sum2 = 0;
    cout << "ARR: ";
    for (int i = 0; i < n; i++) {
        cout << ARR[i] << " ";
        sum2 += ARR[i];
    }
    cout << endl << "Сумма: " << sum2 << endl;
    cout << "Сумма изначального массива больше суммы массива после сортировки на " << sum1 - sum2 << endl;
}

int main() {
    // Инициализация генератора
    random_device rd;
    mt19937_64 gen(rd());

    // Задаем диапазон [a, b] для целых чисел
    int a = 10, b = 30;
    int c = 1000, d = 9000; // Для задания 5
    uniform_int_distribution<int> rand(a, b);
    uniform_int_distribution<int> rand5(c, d);

    // Задание 1
    vector<int> arr1 = task1_arr1(gen, rand);
    vector<int> arr2 = task1_arr2(gen, rand);

    // Задание 2
    task2(arr1);

    // Задание 3
    task3(arr1, arr2);

    // Задание 4
    task4(arr1);

    // Задание 5
    task5(gen, rand5);

    return 0;
}
