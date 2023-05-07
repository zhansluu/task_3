/**
     * Программа позволяет выполнить обратную интерполяцию за счет перестановки местами образа и прообраза функции(1 способ)
     * или сделать обратное интерполирование при помощи интерполяционного многочлена.
     * Алгебраическое уравнение решаем при помощи метода биссекций предварительно отделив корни на отрезке.
     */

#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "Задание 3.1. Обратное интерполирование." << endl;
    cout << "Вариант 3." << endl << "Дана функция f(x)=exp(x)-x" << endl;

    size_t m, n;
    double a, b, F;
    /*Ввод данных с клавиатуры*/
    cout << "Введите число значений в таблице: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "Введите число m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "Введите значение a(нижнюю границу): ";
    cin >> a;
    cout << endl << "Введите значение b(верхнюю границу): ";
    cin >> b;
    if (b < a)
        swap(a,b);

    /*Создание таблицы*/
    double x_table[1000], y_table[1000], step;
    step = (b-a)/m;
    cout << "Исходная таблица значений функций:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << "x = " << x_table[i] << "; y = " << y_table[i] << endl;
    }

    cout << endl << "Введите значение функции, аргумент которого мы должны найти: F = ";
    cin >> F;
    cout << endl << "Введите степень n интерполяционного многочлена (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "Введено недопустимое значение n. Введите степень n интерполяционного многочлена (n <= " << m << "): ";
        cin >> n;
    }

    cout << "Отсортированная таблица:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < m-1; j++)
        {
            if (fabs(y_table[j]-F) > fabs(y_table[j+1]-F))
            {
                swap (y_table[j], y_table[j+1]);
                swap (x_table[j], x_table[j+1]);
            }
        }
    }
    for (size_t i = 0; i < m; i++)
        cout << "x = " << x_table[i] << "; y = " << y_table[i] << endl;

    cout << "Получившийся аргумент, найденный при помощи представления Лагранжа (способ 1): x = " << Lagrange(n, y_table, x_table, F) << endl;
    cout << "Абсолютная фактическая погрешность: " << fabs(func(Lagrange(n, y_table, x_table, F)) - F) << endl;

/** 2 способ */
    double eps;
    cout << endl << "Введите степень n интерполяционного многочлена для способа 2 (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "Введено недопустимое значение n. Введите степень n интерполяционного многочлена (n <= " << m << "): ";
        cin >> n;
    }
    cout << endl << "Введите точность eps, с которой находится корень алгебраического уравнения во 2 способе: " << endl;
    cin >> eps;
    while (eps < 0)
    {
        cout << "Введено недопустимое значение eps! Повторите ввод: ";
        cin >> eps;
    }

    double c, X;
    size_t counter = 0;

    while ((b - a) > 2*eps)
    {
        c = (a+b)/2;
        if ((Lagrange(n, x_table, y_table, a)-F)*(Lagrange(n, x_table, y_table, c)-F) <= 0)
            b = c;
        else
            a = c;
        counter++;
    }
    X = (a + b)/2;
    std::cout << "Получившийся аргумент, найденный 2 способом: x = "  << X << std::endl;
    std::cout << "Абсолютная величина невязки для приближенного решения: " << fabs(func(X) - F) << std::endl;
    std::cout << "Количество шагов для достижения точности эпсилон: " << counter + 1 << std::endl << std::endl;

    return 0;
}
