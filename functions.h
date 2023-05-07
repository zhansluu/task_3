#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <cmath>

double func (double x)
{
    return exp(x)-x;
}

/*Реализация интерполяции методом Лагранжа*/
double Lagrange(size_t n, double x_table[], double y_table[], double x)
{
    double result = 0;
    for (size_t i = 0; i < n; i++)
    {
        double frac = 1;
        for (size_t j = 0; j < n; j++)
        {
            if(i != j)
                frac *= (x - x_table[j])/(x_table[i]-x_table[j]);
        }
        result += frac * y_table[i];
    }
    return result;
}

#endif // FUNCTIONS_H_INCLUDED
