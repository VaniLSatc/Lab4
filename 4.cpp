#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Функция для подсчета баллов по методу Борда
string bordaWinner(vector<vector<string>>& votes, vector<string>& candidates) {
    map<string, int> scores; // В этом контейнере будет накапливаться количество очков для кандидатов
    int n = candidates.size();

    // Инициализация баллов для каждого кандидата
    for (auto& candidate : candidates) {
        scores[candidate] = 0;
    }

    // Подсчет баллов для каждого кандидата
    for (auto& vote : votes) {
        for (int i = 0; i < vote.size(); i++) {
            scores[vote[i]] += (n - 1 - i);
        }
    }

    // Находим кандидата с максимальным количеством баллов
    string winner;
    int maxScore = -1;
    int count_scores = 0;
    for (auto& [candidate, score] : scores) {
        if(score = maxScore)count_scores++;
        if (score > maxScore) {
            maxScore = score;
            winner = candidate;
        }
    }

    if (count_scores == candidates.size()) return "У участников одинаковое количество очков, победителя нет";

    return winner;
}

// Функция для определения победителя по методу Кондорсе
string condorcetWinner(vector<vector<string>>& votes, vector<string>& candidates) {
    int n = candidates.size();

    // Создаем матрицу парных сравнений
    map<string, map<string, int>> pairwin;

    // Инициализация матрицы
    for (auto& a : candidates) {
        for (auto& b : candidates) {
            if (a != b) {
                pairwin[a][b] = 0;
            }
        }
    }

    // Заполняем матрицу парных сравнений
    for (auto& vote : votes) {
        for (int i = 0; i < vote.size(); ++i) {
            for (int j = i + 1; j < vote.size(); ++j) {
                string a = vote[i];
                string b = vote[j];
                pairwin[a][b]++;
            }
        }
    }

    // Проверяем, есть ли кандидат, который побеждает всех в парных сравнениях
    for (auto& a : candidates) {
        bool CondorcetWinner = true;
        for (auto& b : candidates) {
            if (a != b && pairwin[a][b] <= pairwin[b][a]) {
                CondorcetWinner = false;
                break;
            }
        }
        if (CondorcetWinner) {
            return a;
        }
    }

    return "Нет победителя по Кондорсе";
}

int main() {
    // Пример входных данных
    vector<string> candidates = {"Петя", "Вася", "Оля"};
    vector<vector<string>> votes = {
    {"Вася", "Петя", "Оля"},
    {"Петя", "Оля", "Вася"},
    {"Оля", "Петя", "Вася"}
};

    string bordaW = bordaWinner(votes, candidates);
    string condorcetW = condorcetWinner(votes, candidates);

    cout << "Победитель по методу Борда: " << bordaW << endl;
    cout << "Победитель по методу Кондорсе: " << condorcetW << endl;

    return 0;
}

//  Оба метода дают одинакового победителя
//     {"Вася", "Петя", "Оля"},
//     {"Петя", "Оля", "Вася"},
//     {"Оля", "Петя", "Вася"}
//};

// Метод Борда находит победителя, а Кондорсе нет
//     {"Оля", "Петя", "Вася"},
//     {"Петя", "Вася", "Оля"},
//     {"Вася", "Оля", "Петя"}
// };
