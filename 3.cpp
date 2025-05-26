#include <iostream>
#include <ctime>
#include <cstdint>

using namespace std;

// Глобальное состояние генератора
static int32_t xorshift_state = 0;

// Инициализация генератора
void xorshift_seed(int32_t seed) {
    if (seed == 0) {
        seed = static_cast<int32_t>(time(nullptr));
    }
    xorshift_state = seed;
}

// Генерация случайного числа
int32_t xorshift(int min, int max) {
    uint32_t x = xorshift_state;
    x ^= x << 16;
    x ^= x >> 3;
    x ^= x << 9;
    xorshift_state = x;// Отрицательные числа генерируются за счёт беззнакового х
    return min + (x % (max - min + 1));
}

int main() {
    // Инициализация генератора
    xorshift_seed(0); // Можно передать 0 для автоматического инициализирования генератора
    
    cout << "Сколько чисел небходимо сгенерировать: ";
    int n;
    cin >> n;
    cout << "Задайте диапазон.\nОт ";
    int min, max;
    cin >> min;
    cout << "До ";
    cin >> max;
    for (int i = 0; i < n; ++i) {
        cout << xorshift(min, max) << endl;
    }
    
    return 0;
}
