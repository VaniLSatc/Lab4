using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    // Функция для подсчета баллов по методу Борда
    static string BordaWinner(List<List<string>> votes, List<string> candidates)
    {
        Dictionary<string, int> scores = new Dictionary<string, int>(); // В этом словаре будет накапливаться количество очков для кандидатов
        int n = candidates.Count;

        // Инициализация баллов для каждого кандидата
        foreach (var candidate in candidates)
        {
            scores[candidate] = 0;
        }

        // Подсчет баллов для каждого кандидата
        foreach (var vote in votes)
        {
            for (int i = 0; i < vote.Count; i++)
            {
                scores[vote[i]] += (n - 1 - i);
            }
        }

        // Находим кандидата с максимальным количеством баллов
        string winner = "";
        int maxScore = -1;
        int countScores = 0;
        
        foreach (var kvp in scores)
        {
            if (kvp.Value == maxScore) countScores++;
            if (kvp.Value > maxScore)
            {
                maxScore = kvp.Value;
                winner = kvp.Key;
            }
        }

        if (countScores == candidates.Count) 
            return "У участников одинаковое количество очков, победителя нет";

        return winner;
    }

    // Функция для определения победителя по методу Кондорсе
    static string CondorcetWinner(List<List<string>> votes, List<string> candidates)
    {
        int n = candidates.Count;

        // Создаем матрицу парных сравнений
        Dictionary<string, Dictionary<string, int>> pairwin = new Dictionary<string, Dictionary<string, int>>();

        // Инициализация матрицы
        foreach (var a in candidates)
        {
            pairwin[a] = new Dictionary<string, int>();
            foreach (var b in candidates)
            {
                if (a != b)
                {
                    pairwin[a][b] = 0;
                }
            }
        }

        // Заполняем матрицу парных сравнений
        foreach (var vote in votes)
        {
            for (int i = 0; i < vote.Count; ++i)
            {
                for (int j = i + 1; j < vote.Count; ++j)
                {
                    string a = vote[i];
                    string b = vote[j];
                    pairwin[a][b]++;
                }
            }
        }

        // Проверяем, есть ли кандидат, который побеждает всех в парных сравнениях
        foreach (var a in candidates)
        {
            bool condorcetWinner = true;
            foreach (var b in candidates)
            {
                if (a != b && pairwin[a][b] <= pairwin[b][a])
                {
                    condorcetWinner = false;
                    break;
                }
            }
            if (condorcetWinner)
            {
                return a;
            }
        }

        return "Нет победителя по Кондорсе";
    }

    static void Main()
    {
        // Пример входных данных
        List<string> candidates = new List<string> { "Петя", "Вася", "Оля" };
        List<List<string>> votes = new List<List<string>>
        {
            new List<string> { "Оля", "Петя", "Вася" },
            new List<string> { "Петя", "Вася", "Оля" },
            new List<string> { "Вася", "Оля", "Петя" }
        };

        string bordaW = BordaWinner(votes, candidates);
        string condorcetW = CondorcetWinner(votes, candidates);

        Console.WriteLine("Победитель по методу Борда: " + bordaW);
        Console.WriteLine("Победитель по методу Кондорсе: " + condorcetW);

        if (bordaW != condorcetW)
        {
            Console.WriteLine("Разные методы дали разных победителей");
        }
    }
}
