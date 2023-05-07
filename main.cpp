/**
     * ��������� ��������� ��������� �������� ������������ �� ���� ������������ ������� ������ � ��������� �������(1 ������)
     * ��� ������� �������� ���������������� ��� ������ ����������������� ����������.
     * �������������� ��������� ������ ��� ������ ������ ��������� �������������� ������� ����� �� �������.
     */

#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "������� 3.1. �������� ����������������." << endl;
    cout << "������� 3." << endl << "���� ������� f(x)=exp(x)-x" << endl;

    size_t m, n;
    double a, b, F;
    /*���� ������ � ����������*/
    cout << "������� ����� �������� � �������: ";
    cin >> m;
    while (m > 1000)
    {
        cout << "������� ����� m < 1000" << endl;
        cin >> m;
    }
    m--;
    cout << "������� �������� a(������ �������): ";
    cin >> a;
    cout << endl << "������� �������� b(������� �������): ";
    cin >> b;
    if (b < a)
        swap(a,b);

    /*�������� �������*/
    double x_table[1000], y_table[1000], step;
    step = (b-a)/m;
    cout << "�������� ������� �������� �������:" << endl;
    for (size_t i = 0; i < m; i++)
    {
        x_table[i] = a + i*step;
        y_table[i] = func(x_table[i]);
        cout << "x = " << x_table[i] << "; y = " << y_table[i] << endl;
    }

    cout << endl << "������� �������� �������, �������� �������� �� ������ �����: F = ";
    cin >> F;
    cout << endl << "������� ������� n ����������������� ���������� (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "������� ������������ �������� n. ������� ������� n ����������������� ���������� (n <= " << m << "): ";
        cin >> n;
    }

    cout << "��������������� �������:" << endl;
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

    cout << "������������ ��������, ��������� ��� ������ ������������� �������� (������ 1): x = " << Lagrange(n, y_table, x_table, F) << endl;
    cout << "���������� ����������� �����������: " << fabs(func(Lagrange(n, y_table, x_table, F)) - F) << endl;

/** 2 ������ */
    double eps;
    cout << endl << "������� ������� n ����������������� ���������� ��� ������� 2 (n <= " << m << "): ";
    cin >> n;
    while (n > m)
    {
        cout << "������� ������������ �������� n. ������� ������� n ����������������� ���������� (n <= " << m << "): ";
        cin >> n;
    }
    cout << endl << "������� �������� eps, � ������� ��������� ������ ��������������� ��������� �� 2 �������: " << endl;
    cin >> eps;
    while (eps < 0)
    {
        cout << "������� ������������ �������� eps! ��������� ����: ";
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
    std::cout << "������������ ��������, ��������� 2 ��������: x = "  << X << std::endl;
    std::cout << "���������� �������� ������� ��� ������������� �������: " << fabs(func(X) - F) << std::endl;
    std::cout << "���������� ����� ��� ���������� �������� �������: " << counter + 1 << std::endl << std::endl;

    return 0;
}
