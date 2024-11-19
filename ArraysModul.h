// Код создан Сапожниковым Ю.С.
// Задача 136Д

#pragma once    

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <sstream>
#include <string>

using namespace std;

/*Пространства имен используются для организации кода в виде логических групп
и с целью избежания конфликтов имен, которые могут возникнуть, особенно в таких случаях
когда база кода включает несколько библиотек.*/
namespace ArraysModul { // Поможет избежать конфликтов имен
    const size_t MAX = 100; // Максимальное число для случайного числа
    const size_t MIN = 1;  // Минимальное число для случайного числа


    // Функция создания случайного массива из N количества и минимально и макисмально возможными числами
    // Так же используется srand(time(NULL)) в главной программе для инициализации генератора случайных чисел вне цикла 
    namespace RandomArray {
        void random_array(int* a, size_t N, size_t MAX, size_t MIN) {
            for (int i = 0; i < N; i++) {
                a[i] = rand() % MAX + MIN;  // Случайное значение массива от MIN до MAX
            }
        }
    }

    //Функция возвращающую сумму квадратов из масиива a с N переменными
    // Используется template<typename T> для шаблонности функции
    template<typename T>
    T sum_array(T* a, size_t N) {
        T sum = 0;
        for (size_t i = 0; i < N; i++) {
            sum += a[i] * a[i];
        }
        return sum;
    }

    //Функция вывода массива a с N переменными
    // Используется template<typename T> для шаблонности функции
    template<typename T>
    void print_array(T* a, size_t N) {
        for (size_t i = 0; i < N; i++) {
            cout << a[i] << ", ";
        }
        cout << endl;
    }

    // Запись  массива в текстовый файл название которго передаётся через SFile
    // Используется template<typename T> для шаблонности функции
    template<typename T>
    void VText(vector<T>& a, string SFile) {
        ofstream out;  // поток для записи

        // Проверяем, если строка пустая
        if (SFile.empty()) {
            SFile = "Text"; // присваиваем название "Text" при пустом вводе
        }

        out.open(SFile);
        if (!out.is_open()) {
            throw runtime_error("ERROR OPEN FILE");
        }

        for (size_t i = 0; i < a.size(); i++) {
            out << a[i] << " ";
        }

        out.close();
    }

    // Вывод массива из текстового файла название которго передаётся через SFile в настоящий массив
    vector<int> ZText(string SFile) {
        ifstream in(SFile);  // открываем файл для чтения
        string line;

        vector<int> tempData;  // временный вектор для хранения чисел
        if (in.is_open()) {
            while (getline(in, line)) {
                stringstream ss(line);
                int number;
                while (ss >> number) {
                    tempData.push_back(number);
                }
            }
        }
        else {
            cerr << "ERROR OPEN FILE" << endl;
        }
        in.close();  // закрываем файл
        return tempData;
    }

    // Функция создания случайного массива из количества элементов векторного массива и минимально и макисмально возможными числами
    // Так же используется srand(time(NULL)) в главной программе для инициализации генератора случайных чисел вне цикла 
    template<typename T>
    void random_array(vector<T>& a, size_t MAX, size_t MIN) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = rand() % MAX + MIN;  // Случайное значение массива от MIN до MAX
        }
    }

    //Функция возвращающую сумму квадратов из векторного масиива нужная для проверки
    // Используется template<typename T> для шаблонности функции
    template<typename T>
    T sum_array_vector(vector<T>& a) {
        T sum = 0;
        for (size_t i = 0; i < a.size(); i++) {
            sum += a[i] * a[i];
        }
        return sum;
    }

    //Функция вывода векторного масиива a 
    // Используется template<typename T> для шаблонности функции
    template<typename T>
    void print_array_vector(vector<T>& a) {
        for (size_t i = 0; i < a.size(); i++) {
            cout << a[i] << ", ";
        }
        cout << endl;
    }

    // Тесты для вектоного и обычного массива
    void TestCheck() {
        int* arr1 = new int[5] { 1, 2, 3, 4, 5 };
        int* arrall1 = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int* arrrand1 = new int[4] { 4, 8, 3, 9 };
        int* arrtest1 = new int[5] { 1, 2, 3, 4, 5 };

        vector<int> arr = { 1, 2, 3, 4, 5 };
        vector<int> arrall = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        vector<int> arrrand = { 4, 8, 3, 9 };
        vector<int> arrtest = { 1, 2, 3, 4, 5 };

        assert(sum_array(arr1, 5) == 55);
        assert(sum_array(arrall1, 10) == 385);
        assert(sum_array(arrrand1, 4) == 170);
        assert(sum_array(arrtest1, 5) != 56);

        assert(sum_array_vector(arr) == 55);
        assert(sum_array_vector(arrall) == 385);
        assert(sum_array_vector(arrrand) == 170);
        assert(sum_array_vector(arrtest) != 56);
    }
}