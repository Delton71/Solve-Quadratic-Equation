/*
 * \file
 * \brief Тестриует программу, решающую квадратных трехчлен
 * \date Летняя школа 25.08-31.08
 *
 * Выводит сообщения об успешно и не очень пройденных тестах с подробным описанием подаваемых на вход и требуемых значений при возникновении ошибки
 *
 * */

#include "SQE.h"
#include <stdio.h>


int Test_patt(int num_test, double a, double b, double c, double x1_need, double x2_need, int nRoots_need);

/* Включает в себя все проводимые тесты с испольованием функции-шаблона
 * \param [in] isBadResults Количество проваленных тестов
 * \param [in] num_test Счетчик тестов
 *
 * \return количество проваленных тестов
 *
 * */
int TestQuadraticEquation()
{
    int isBadResults = 0, num_test = 1;
    //                       (num_test, a, b, c, x1, x2, nRoots)
    // No roots
    isBadResults += Test_patt(num_test, 2, 3, 4, 0, 0, NO_ROOTS);
    num_test++;

    // No roots
    isBadResults += Test_patt(num_test, 0, 0, 1, 0, 0, NO_ROOTS);
    num_test++;

    // Any roots
    isBadResults += Test_patt(num_test, 0, 0, 0, 0, 0, INFINITE_NUMBER_OF_ROOTS);
    num_test++;

    // Single root (a = 0)
    isBadResults += Test_patt(num_test, 0, 4, 5, -1.25, 0, SINGLE_ROOT);
    num_test++;

    // Single root (d = 0)
    isBadResults += Test_patt(num_test, 1, -2, 1, 1, 0, SINGLE_ROOT);
    num_test++;

    // Two roots
    isBadResults += Test_patt(num_test, 4, 8, 3, -1.5, -0.5, TWO_ROOTS);
    num_test++;

    return isBadResults;
}


/* Шаблон теста
 * \param [in] num_test Номер теста
 * \param [in] a, b, c Коэффиценты квадратного трехчлена \f$ax^2 + bx + c\f$
 * \param [in] x1_need, x2_need Необходимые корни трехчлена
 * \param [in] nRoots_need Необходимое количество решений
 *
 * \return Успешно ли пройден тест
 *
 * */
int Test_patt(int num_test, double a, double b, double c, double x1_need, double x2_need, int nRoots_need)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);
    if (x1 != x1_need || x2 != x2_need || nRoots != nRoots_need)
    {
        printf("Test %d: FAIL; a = %lg, b = %lg, c = %lg\nOUTPUT: nRoots = %d, x1 = %lg, x2 = %lg\n  NEED: nRoots = %d, x1 = %lg, x2 = %lg\n", num_test, a, b, c, nRoots, x1, x2, nRoots_need, x1_need, x2_need);
        return 1;
    }
    printf("Test %d: OK; a = %lg, b = %lg, c = %lg\nOUTPUT: nRoots = %d, x1 = %lg, x2 = %lg\n", num_test, a, b, c, nRoots, x1, x2);
    return 0;
}