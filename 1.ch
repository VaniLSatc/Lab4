using System;
using System.Collections.Generic;

class Program
{
    // Уравнение функции
    static double f(double x)
    {
        return Math.Sin(x + 1) - x - 1;
    }

    // Производная функции
    static double df(double x)
    {
        return Math.Cos(x + 1) - 1;
    }

    // Метод половинного деления
    static Tuple<double, int> BisectionMethod(double a, double b, double eps)
    {
        Console.WriteLine("Метод половинного деления:");
        Console.WriteLine("----------------------------------------------");
        Console.WriteLine("|  N  |     An     |     Bn     |   Bn - An  |");
        Console.WriteLine("----------------------------------------------");
        
        int iteration = 0;
        double c;
        while (Math.Abs(b - a) > eps)
        {
            c = (a + b) / 2;
            iteration++;
            
            Console.WriteLine($"| {iteration,3} | {a,10:F6} | {b,10:F6} | {(b - a),10:F6} |");
            
            if (f(c) == 0.0)
            {
                break;
            }
            else if (f(a) * f(c) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
        Console.WriteLine("----------------------------------------------\n");
        return Tuple.Create((a + b) / 2, iteration);
    }

    // Метод Ньютона
    static Tuple<double, int> NewtonMethod(double x0, double eps)
    {
        Console.WriteLine("Метод Ньютона:");
        Console.WriteLine("----------------------------------------------");
        Console.WriteLine("|  N  |     Xn     |    Xn+1    |  Xn+1 - Xn |");
        Console.WriteLine("----------------------------------------------");
        
        int iteration = 0;
        double x = x0;
        double del;
        double Xn;
        do
        {
            del = f(x) / df(x);
            Xn = x - del;
            iteration++;
            
            Console.WriteLine($"| {iteration,3} | {x,10:F6} | {Xn,10:F6} | {Math.Abs(del),10:F6} |");
            
            x = Xn;
        } while (Math.Abs(del) > eps);
        Console.WriteLine("----------------------------------------------\n");
        return Tuple.Create(x, iteration);
    }

    // Метод простых итераций
    static Tuple<double, int> SimpleMethod(double x0, double eps)
    {
        Console.WriteLine("Метод простых итераций:");
        Console.WriteLine("----------------------------------------------");
        Console.WriteLine("|  N  |    Xn     |    Xn+1   |   Xn+1 - Xn  |");
        Console.WriteLine("----------------------------------------------");
        
        int iteration = 0;
        double x = x0;
        double Xn;
        while (true)
        {
            Xn = Math.Sin(x + 1) - 1;
            iteration++;
            
            Console.WriteLine($"| {iteration,3} | {x,10:F6} | {Xn,10:F6} | {Math.Abs(Xn - x),10:F6} |");
            
            if (Math.Abs(Xn - x) < eps)
            {
                break;
            }
            x = Xn;
        }
        Console.WriteLine("----------------------------------------------");
        if (Math.Abs(Math.Cos(x0 + 1)) >= 1.0)
        {
            Console.WriteLine("Предупреждение: |fi'(x)| >= 1. Сходимость не гарантирована.\n");
        }

        return Tuple.Create(Xn, iteration);
    }

    static void Main()
    {
        double eps = 0.0001;
        double a = -100.0, b = 101.01111111;
        double x0_newton = -1.000001;
        double x0_iter = -1.0;

        // Вызов методов с выводом таблиц
        var bisection = BisectionMethod(a, b, eps);
        var newton = NewtonMethod(x0_newton, eps);
        var simple = SimpleMethod(x0_iter, eps);

        // Вывод итоговых результатов
        Console.WriteLine("\nИтоговые результаты:");
        Console.WriteLine("---------------------------------------------------------------------");
        Console.WriteLine("| Метод                | Корень               | Кол-во итераций     |");
        Console.WriteLine("---------------------------------------------------------------------");
        Console.WriteLine($"| Половинного деления  | {bisection.Item1,-20:F6} | {bisection.Item2,-20} |");
        Console.WriteLine("---------------------------------------------------------------------");
        Console.WriteLine($"| Ньютона              | {newton.Item1,-20:F6} | {newton.Item2,-20} |");
        Console.WriteLine("---------------------------------------------------------------------");
        Console.WriteLine($"| Простых итераций     | {simple.Item1,-20:F6} | {simple.Item2,-20} |");
        Console.WriteLine("---------------------------------------------------------------------");
    }
}
