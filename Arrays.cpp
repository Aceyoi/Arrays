// Код создан Сапожниковым Ю.С.
// Задача 136Д

#include <iostream>
#include "ArraysModul.h"
#include <string>


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));  // Инициализация генератора случайных чисел вне цикла                                              //# rand
    TestCheck();  // проверка данных


    string Chek;
    cout << "Хотите загрузить файл (Y) или начать генерацию нового массива (N)" << endl;  // Загрузка файла
    cin >> Chek;

    CheckFile(Chek);
}