#include <stdio.h>
#include <math.h>
#include "SQE.h"

// #define TEST_RUN
#define PRINT_ERROR

#ifdef TEST_RUN
#define RUN_PRO \
if (TestQuadraticEquation() != 0)       \
    {                                   \
        printf("Something wrong(((\n"); \
        return -1;                      \
    }                                   \
    printf("Tests passed\n");           \
    return 0;
#else
#define RUN_PROG solve_eq()
#endif /* TEST_RUN */

int solve_eq();

int main() {
    RUN_PROG;
}

/* Решает квадратный трехчлен по введеным пользователям коэффицентам a, b, c
 * \param [in] a, b, c Коэффиценты квадратного трехчлена \f$ax^2 + bx + c\f$
 * \param [out] x1, x2 Решения трехчлена
 *
 * Содержит проверку при некорректном вводе a, b, c, при обнулении указателей, находит количество решений при заданных коэффицентах
 *
 * */
int solve_eq()
{
    printf("Enter the a, b, c: ");
    double a = NAN, b = NAN, c = NAN;
    int check_input = scanf("%lg %lg %lg", &a, &b, &c);
    while (check_input != 3)
    {
        printf("Error when entering a, b, c!\n");
        while (getchar() != '\n');
        printf("Enter the a, b, c: ");
        check_input = scanf("%lg %lg %lg", &a, &b, &c);
    }

    double x1 = NAN, x2 = NAN;
    int nRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);
    if (nRoots < 0)
    {
        printf("Error code: %d\n", nRoots);
        return 0;
    }

    switch (nRoots)
    {
        case NO_ROOTS: printf("No roots.\n"); break;
        case SINGLE_ROOT: printf("x = %lg\n", x1); break;
        case TWO_ROOTS: printf("x1 = %lg, x2 = %lg\n", x1, x2); break;
        case INFINITE_NUMBER_OF_ROOTS: printf("Any number.\n"); break;
        default: printf("ERROR: nRoots = %d.\n", nRoots); break;
    }

    getchar();
    getchar();
    return 0;
}