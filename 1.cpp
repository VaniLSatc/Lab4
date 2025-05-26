#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// Уравн     << setw(10) << b << " | " 
<< setw(10) << (b - a) << " |\n";
        
if (f(c) == 0.0) {
    break;
} else if (f(a) * f(c) < 0) {
    b = c;
} else {
    a = c;
}
}
cout << "----------------------------------------------\n";
cout << "Корень: " << (a+b)/2 << endl << endl;
return pair<double, int> ((a + b) / 2, iteration);
}

// Метод Ньютона
pair<double, int> newton_method(double x0, double eps) {
cout << "Метод Ньютона:\n";
cout << "----------------------------------------------\n";
cout << "|  N  |     Xn     |    Xn+1    |  Xn+1 - Xn |\n";
cout << "----------------------------------------------\n";

int iteration = 0;
double x = x0;
double del;
double Xn;
do {
del = f(x) / df(x);
Xn = x - del;
iteration++;

cout << "| " << setw(3) << iteration << " | " 
     << setw(10) << x << " | " 
     << setw(10) << Xn << " | " 
     << setw(10) << fabs(del) << " |\n";

x = Xn;
} while (fabs(del) > eps);
cout << "----------------------------------------------\n";
cout << "Корень: " << x << endl << endl;
return pair<double, int> (x, iteration);
}

// Метод простых итераций
pair<double, int> simple_method(double x0, double eps) {
cout << "Метод простых итераций:\n";
cout << "----------------------------------------------\n";
cout << "|  N  |    Xn     |    Xn+1   |   Xn+1 - Xn  |\n";
cout << "----------------------------------------------\n";

int iteration = 0;
double x = x0;
double Xn;
while (true){
Xn = sin(x + 1) - 1;
iteration++;

cout << "| " << setw(3) << iteration << " | " 
     << setw(10) << x << "| " 
     << setw(10) << Xn << " | " 
     << setw(10) << fabs(Xn - x) << " |\n";

if (fabs(Xn - x) < eps) {
    break;
}
x = Xn;
}
cout << "----------------------------------------------\n";
if (fabs(cos(x0 + 1)) >= 1.0) {
cout << "Предупреждение: |fi'(x)| >= 1. Сходимость не гарантирована.\n\n";
}

cout << "Корень: " << Xn << endl << endl;
return pair<double, int> (Xn, iteration);
}

int main() {
double eps = 0.0001;
double a = -100.0, b = 101.01111111;
double x0_newton = -1.000001;
double x0_iter = -1.0;

// Вызов методов с выводом таблиц
pair<double, int> bisection = bisection_method(a, b, eps);
pair<double, int> newton = newton_method(x0_newton, eps);
pair<double, int> simple = simple_method(x0_iter, eps);

// Вывод итоговых результатов
cout << "\nИтоговые результаты:\n";
cout << "---------------------------------------------------------------------\n";
cout << "| Метод                | Корень               | Кол-во итераций     |\n";
cout << "---------------------------------------------------------------------\n";
cout << "| Половинного деления  | " << setw(20) << left << bisection.first << " |"
<< setw(20) << left << bisection.second << " |\n";
cout << "---------------------------------------------------------------------\n";
cout << "| Ньютона              | " << setw(20) << left << newton.first << " |"
<< setw(20) << left << newton.second << " |\n";
cout << "---------------------------------------------------------------------\n";
cout << "| Простых итераций     | " << setw(20) << left << simple.first << " |"
<< setw(20) << left << simple.second << " |\n";
cout << "---------------------------------------------------------------------\n";

return 0;
}ение функции
double f(double x) {
    return sin(x + 1) - x - 1;
}

// Производная функции
double df(double x) {
    return cos(x + 1) - 1;
}

// Метод половинного деления
pair<double, int> bisection_method(double a, double b, double eps) {
    cout << "Метод половинного деления:\n";
    cout << "----------------------------------------------\n";
    cout << "|  N  |     An     |     Bn     |   Bn - An  |\n";
    cout << "----------------------------------------------\n";
    
    int iteration = 0;
    double c;
    while (fabs(b - a) > eps) {
        c = (a + b) / 2;
        iteration++;
        
        cout << "| " << setw(3) << iteration << " | " 
             << setw(10) << a << " | " 
             << setw(10) << b << " | " 
             << setw(10) << (b - a) << " |\n";
        
        if (f(c) == 0.0) {
            break;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    cout << "----------------------------------------------\n";
    cout << "Корень: " << (a+b)/2 << endl << endl;
    return pair<double, int> ((a + b) / 2, iteration);
}

// Метод Ньютона
pair<double, int> newton_method(double x0, double eps) {
    cout << "Метод Ньютона:\n";
    cout << "----------------------------------------------\n";
    cout << "|  N  |     Xn     |    Xn+1    |  Xn+1 - Xn |\n";
    cout << "----------------------------------------------\n";
    
    int iteration = 0;
    double x = x0;
    double del;
    double Xn;
    do {
        del = f(x) / df(x);
        Xn = x - del;
        iteration++;
        
        cout << "| " << setw(3) << iteration << " | " 
             << setw(10) << x << " | " 
             << setw(10) << Xn << " | " 
             << setw(10) << fabs(del) << " |\n";
        
        x = Xn;
    } while (fabs(del) > eps);
    cout << "----------------------------------------------\n";
    cout << "Корень: " << x << endl << endl;
    return pair<double, int> (x, iteration);
}

// Метод простых итераций
pair<double, int> simple_method(double x0, double eps) {
    cout << "Метод простых итераций:\n";
    cout << "----------------------------------------------\n";
    cout << "|  N  |    Xn     |    Xn+1   |   Xn+1 - Xn  |\n";
    cout << "----------------------------------------------\n";
    
    int iteration = 0;
    double x = x0;
    double Xn;
    while (true){
        Xn = sin(x + 1) - 1;
        iteration++;
        
        cout << "| " << setw(3) << iteration << " | " 
             << setw(10) << x << "| " 
             << setw(10) << Xn << " | " 
             << setw(10) << fabs(Xn - x) << " |\n";
        
        if (fabs(Xn - x) < eps) {
            break;
        }
        x = Xn;
    }
    cout << "----------------------------------------------\n";
    if (fabs(cos(x0 + 1)) >= 1.0) {
        cout << "Предупреждение: |fi'(x)| >= 1. Сходимость не гарантирована.\n\n";
    }

    cout << "Корень: " << Xn << endl << endl;
    return pair<double, int> (Xn, iteration);
}

int main() {
    double eps = 0.0001;
    double a = -100.0, b = 101.01111111;
    double x0_newton = -1.000001;
    double x0_iter = -1.0;

    // Вызов методов с выводом таблиц
    pair<double, int> bisection = bisection_method(a, b, eps);
    pair<double, int> newton = newton_method(x0_newton, eps);
    pair<double, int> simple = simple_method(x0_iter, eps);

    // Вывод итоговых результатов
    cout << "\nИтоговые результаты:\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "| Метод                | Корень               | Кол-во итераций     |\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "| Половинного деления  | " << setw(20) << left << bisection.first << " |"
    << setw(20) << left << bisection.second << " |\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "| Ньютона              | " << setw(20) << left << newton.first << " |"
    << setw(20) << left << newton.second << " |\n";
    cout << "---------------------------------------------------------------------\n";
    cout << "| Простых итераций     | " << setw(20) << left << simple.first << " |"
    << setw(20) << left << simple.second << " |\n";
    cout << "---------------------------------------------------------------------\n";

    return 0;
}
