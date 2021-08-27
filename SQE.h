/*
 * \file
 * \brief Программа, решающая квадратный трехчлен по заданным параметрам a, b, c.
 * \date Летняя школа 25.08-31.08
 *
 * \param [in] a, b, c Коэффиценты квадратного трехчлена \f$ax^2 + bx + c\f$
 * \param [in, out] x (x1, x2) Решения трехчлена
 *
 * \return Корни квадратного трехчлена
 *
 * Включает в себя функцию, решающую квадратный чрехчлен по заданным параметрам и тестриующую систему.
 *
 *
 * */

#ifndef TEST_SQE_H
#define TEST_SQE_H

const double PRECISION; ///< Констанста, используется при появлении погрешностей в вычислениях данных типа double

/// Возможный результат
enum RootsNumber {
    NULL_POINT = -1, ///< Ошибка при обнулении указателя
    NO_ROOTS, ///< Нет корней
    SINGLE_ROOT, ///< Единственный корень x
    TWO_ROOTS, ///< Два корня x1 и x2
    INFINITE_NUMBER_OF_ROOTS ///< Любое число
};

int SolveQuadraticEquation(double, double, double, double*, double*); ///< Функция, вычисляющая корни квадратного трехчлена
int TestQuadraticEquation(); ///< Тестирующая функция

#endif //TEST_SQE_H
