/*
 * \file
 * \brief Программа, решающая квадратный трехчлен по заданным параметрам a, b, c.
 * \date Летняя школа 25.08-31.08
 *
 * \param [in] a, b, c Коэффиценты квадратного трехчлена \f$ax^2 + bx + c\f$
 * \param [out] x (x1, x2) Решения трехчлена
 *
 * \return Корни квадратного трехчлена
 *
 * */


#include <math.h>
#include <stdio.h>
#include "SQE.h"

#ifdef PRINT_ERROR
#define PRINT_ERROR printf("Error: the pointer is null!\n");
#else
#define PRINT_ERROR ;
#endif /* PRINT_ERROR */

const double PRECISION = 0.001; ///< Констанста, используется при появлении погрешностей в вычислениях данных типа double

/// Проверяет равенство нулю double переменных с погрешностью
int CloseToZero(double val)
{
    return (fabs(val) < PRECISION);
}

/* Для решения линейных уравнений (при a = 0, b != 0)
 * \param [in] b, c Коэффиценты уравнения вида \f$bx + c\f$
 * \param [in, out] x1 Решение уравнения
 *
 * \return Количество решений nRoots
 *
 * */
int SolveLinear(double b, double c, double* x1) {
    if (CloseToZero(b))
        return (CloseToZero(c)) ? INFINITE_NUMBER_OF_ROOTS : NO_ROOTS;
    else
    {
        *x1 = -c / b;
        return SINGLE_ROOT;
    }
}

/// Для вывода ошибки при обнулении указателя
void print_error()
{
    printf("Error: the pointer is null!\n");
}

/* Находит решения и их количество квадратного трехчлена
 * \param [in] a, b, c Коэффиценты квадратного трехчлена \f$ax^2 + bx + c\f$
 * \param [in, out] x1, x2 Корни трехчлена
 *
 * \return Количество решений nRoots
 *
 * Содержит проверку обнуления указателей. Способна вывести решения при различных коэффицентах a, b, c
 *
 * */
int SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    if (x1 == NULL || x2 == NULL)
    {
        PRINT_ERROR;
        return NULL_POINT;
    }

    if (CloseToZero(a))
        return SolveLinear(b, c, x1);

    double d = b * b - 4 * a * c;

    if (d < 0)
        return NO_ROOTS;

    if (CloseToZero(d))
    {
        *x1 = -b / (2*a);
        return SINGLE_ROOT;
    }

    double d_sqrt = sqrt(d);
    *x1 = (-b - d_sqrt) / (2*a);
    *x2 = (-b + d_sqrt) / (2*a);
    return TWO_ROOTS;
}