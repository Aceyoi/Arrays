// Код создан Сапожниковым Ю.С.
// Задача 136Д

#include <iostream>
#include "ArraysModul.h"
#include <string>
#include <vector>

using namespace std;
using namespace ArraysModul;  // Используем пространство имен ArraysModul

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  // Инициализация генератора случайных чисел вне цикла 
    TestCheck();  // проверка данных

    string Check; // Переменная отвечающая за выбор пользователя
    string SFile; // Переменная отвечающая за название файла
    SFile = "text";  // Название файла
    vector<int> array; // Переменная отвечающая за векторный массив

    cout << "Хотите загрузить файл (Y) или начать генерацию нового массива (N)" << endl;  // Загрузка файла
    cin >> Check;

    if (Check == "Y") {// Если файл загружен

        cout << "Введите название файла" << endl;
        cin >> SFile;
        array = ZText(SFile);

    }
    else // Если создаём новый файл
    {
        cout << "До какого числа будет производиться вычисление? "; 
        size_t N = 0;
        cin >> N;
        array.resize(N);
        // Заполнение массива случайными значениями от min до max
        random_array(array, MAX, MIN);

        try {  // Инструкции, которые могут вызвать исключение
            VText(array, SFile);
        }
        catch (runtime_error& e) {  // Обработка исключения
            cout << e.what();
        }

    }

    // Вывод
    cout << "Сумма массива ";
    //print_array(array, N);
    print_array_vector(array);

    // Функция решения задачи и вывода суммы
    //int sum = sum_array(array, N);
    int sum = sum_array_vector(array);
    cout << endl << "По формуле 'a1^2 + ... + an^2' " << "Равна: " << sum << endl;

    return 0;
}