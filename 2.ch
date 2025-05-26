using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int SwitchNumbers(int n)
    {
        char[] digits = n.ToString().ToCharArray();
        Array.Sort(digits);
        return int.Parse(new string(digits));
    }

    static List<int> Task1Arr1(Random rand, int min, int max)
    {
        int n;
        while (true)
        {
            Console.WriteLine("Введите n - количество элементов в векторе arr1. Значения n должны быть 15 <= n <= 30 !");
            n = int.Parse(Console.ReadLine());
            if (n >= 15 && n <= 30) break;
        }

        Console.WriteLine("Задание 1.");
        List<int> arr1 = new List<int>(n);
        Console.Write("arr1: ");
        for (int i = 0; i < n; i++)
        {
            arr1.Add(rand.Next(min, max + 1));
            Console.Write(arr1[i] + " ");
        }
        Console.WriteLine();
        return arr1;
    }

    static List<int> Task1Arr2(Random rand, int min, int max)
    {
        List<int> arr2 = new List<int>(5);
        Console.Write("arr2: ");
        for (int i = 0; i < 5; i++)
        {
            arr2.Add(rand.Next(min, max + 1));
            Console.Write(arr2[i] + " ");
        }
        Console.WriteLine();
        return arr2;
    }

    static void Task2(List<int> arr1)
    {
        Console.WriteLine("\nЗадание 2.");
        int countChetNumbrs = 0;
        for (int i = 1; i < arr1.Count; i += 2)
        {
            if (arr1[i] % 2 == 0)
            {
                countChetNumbrs++;
                Console.Write(arr1[i] + " ");
            }
        }
        Console.WriteLine("\nКоличество найденных элементов: " + countChetNumbrs);
    }

    static void Task3(List<int> arr1, List<int> arr2)
    {
        Console.WriteLine("\nЗадание 3.");
        Dictionary<int, int> freq = new Dictionary<int, int>();
        foreach (int num in arr1)
        {
            if (freq.ContainsKey(num))
                freq[num]++;
            else
                freq[num] = 1;
        }

        for (int i = 0; i < 5; i++)
        {
            if (freq.ContainsKey(arr2[i]))
            {
                Console.WriteLine($"Число {arr2[i]} встречается в arr1 {freq[arr2[i]]} раз");
            }
            else
            {
                Console.WriteLine($"Число {arr2[i]} не встречается в arr1");
            }
        }
    }

    static void Task4(List<int> arr1)
    {
        Console.WriteLine("\nЗадание 4.");
        Console.Write("old arr1: ");
        foreach (int num in arr1)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();

        int firstElement = arr1[0];
        for (int i = 0; i < arr1.Count - 1; i++)
        {
            arr1[i] = arr1[i + 1];
        }
        arr1[arr1.Count - 1] = firstElement;

        Console.Write("new arr1: ");
        foreach (int num in arr1)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }

    static void Task5(Random rand, int min, int max)
    {
        Console.WriteLine("\nЗадание 5.");
        int n = 0;
        while (true)
        {
            Console.WriteLine("Введите n - количество элементов в векторе ARR. Количество должно быть >0 !");
            n = int.Parse(Console.ReadLine());
            if (n > 0) break;
        }

        List<int> ARR = new List<int>(n);
        int sum1 = 0;
        Console.Write("ARR: ");
        for (int i = 0; i < n; i++)
        {
            ARR.Add(rand.Next(min, max + 1));
            Console.Write(ARR[i] + " ");
            sum1 += ARR[i];
        }
        Console.WriteLine("\nСумма: " + sum1);

        for (int i = 0; i < n; i++)
        {
            ARR[i] = SwitchNumbers(ARR[i]);
        }
        ARR.Sort();

        int sum2 = 0;
        Console.Write("ARR: ");
        foreach (int num in ARR)
        {
            Console.Write(num + " ");
            sum2 += num;
        }
        Console.WriteLine("\nСумма: " + sum2);
        Console.WriteLine("Сумма изначального массива больше суммы массива после сортировки на " + (sum1 - sum2));
    }

    static void Main()
    {
        // Инициализация генератора
        Random rand = new Random();

        // Задаем диапазон [a, b] для целых чисел
        int a = 10, b = 30;
        int c = 1000, d = 9000; // Для задания 5

        // Задание 1
        List<int> arr1 = Task1Arr1(rand, a, b);
        List<int> arr2 = Task1Arr2(rand, a, b);

        // Задание 2
        Task2(arr1);

        // Задание 3
        Task3(arr1, arr2);

        // Задание 4
        Task4(arr1);

        // Задание 5
        Task5(rand, c, d);
    }
}
