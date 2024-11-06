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
const size_t MAX = 100; // Максимальное число для случайного числа
const size_t MIN = 1;  // Минимальное число для случайного числа


// Функция создания случайного массива из N количества и минимально и макисмально возможными числами
// Так же используется srand(time(NULL)) в главной программе для инициализации генератора случайных чисел вне цикла 
void random_array(int* a, size_t N, size_t MAX, size_t MIN) {
    for (int i = 0; i < N; i++) {
        a[i] = rand() % MAX + MIN;  // Случайное значение массива от MIN до MAX
    }}

//Функция возвращающую сумму квадратов из масиива a с N переменными
// Используется template<typename T> для шаблонности функции
template<typename T>
T sum_array(T* a, size_t N) {
    T sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += a[i] * a[i];}
    return sum;}

//Функция вывода массива a с N переменными
// Используется template<typename T> для шаблонности функции
template<typename T>
void print_array(T* a, size_t N) {
    for (size_t i = 0; i < N; i++) {
        cout << a[i] << ", ";}
    cout << endl;}

// Запись  массива в текстовый файл со своим названием или "Text" если пропустить
// Используется template<typename T> для шаблонности функции
template<typename T>
void VText(T* a, size_t N) {
    ofstream out;  // поток для записи
    string SFile = "Text";

    cout << "Введите название файла: ";
    cin >> SFile;
    // Проверяем, если строка пустая
    if (SFile.empty()) {
        SFile = "Text"; // присваиваем название "Text" при пустом вводе
    }

    out.open(SFile);
    if (!out.is_open()) {
        throw runtime_error("Ошибка открытия файла"); /// try
    }

    for (size_t i = 0; i < N; i++) {
        out << a[i] << " ";
    }

    out.close();
}

// Вывод  массива из текстового файла со своим названием или "Text" если пропустить
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
        cerr << "Ошибка открытия файла" << endl;
    }
    in.close();  // закрываем файл
    return tempData;
}

//Функция возвращающую сумму квадратов из масиива с N переменными нужная для проверки
// Используется template<typename T> для шаблонности функции
template<typename T>
T sum_array_vector(vector<T>& a) {
    T sum = 0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += a[i] * a[i];
    }
    return sum;
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

// Функция отвечающая я основное действие
void CheckFile(string Check) {
    if (Check == "Y") {// Если файл загружен

        cout << "Введите название файла" << endl;
        string SFile;
        cin >> SFile;

        size_t N = ZText(SFile).size();
        // Теперь мы знаем количество чисел (N) и можем создать массив
        int* a = new int[N];

        // Копируем данные из временного вектора в массив
        for (int i = 0; i < N; i++) {
            a[i] = ZText(SFile)[i];
        }

        // Вывод считанных данных
        cout << "Данные из файла: ";
        print_array(a, N);
        cout << endl;

        // Функция решения задачи и вывода суммы
        int sum = sum_array(a, N);
        cout << "По формуле 'a1^2 + ... + an^2' сумма равна: " << sum << endl;

        delete[] a;  // Освобождение памяти
    }
    else // Если создаём новый файл
    {
        cout << "До какого числа будет производиться вычисление? ";
        int N;
        cin >> N;
        // Массив
        int* a = new int[N];
        // Заполнение массива случайными значениями от min до max
        random_array(a, N, MAX, MIN);
        // Функция решения задачи и вывода суммы
        int sum = sum_array(a, N);
        // Вывод
        cout << "Сумма массива ";
        print_array(a, N);
        cout << endl << "По формуле 'a1^2 + ... + an^2' ";
        cout << "Равна: " << sum << endl;

        try {  // Инструкции, которые могут вызвать исключение
            VText(a, N);
        }
        catch (runtime_error& e) {  // Обработка исключения
            cout << e.what();
        }
        delete[] a;  // Освобождение памяти
    }
}