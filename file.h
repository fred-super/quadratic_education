#ifndef FILE_H
#define FILE_H

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief RootsNumber enumeration of constants that mean number of roots
 * @param NO_ROOTS the number of roots is zero
 * @param ONE_ROOT the number of roots is one
 * @param TWO_ROOTS the number of roots is two
 * @param INFINITY_ROOTS the number of roots is infinity
 */

enum RootsNumber
{
    NO_ROOTS = 0,
    ONE_ROOTS = 1,
    TWO_ROOTS = 2,
    INFINITY_ROOTS = 3,
};

/**
 * @brief Structure for storing data for tests
 * @param a the square equation coefficient
 * @param b the square equation coefficient
 * @param c the square equation coefficient
 * @param x1_Stated the first expected root
 * @param x2_Stated the second expected root
 * @param nRoots_Stated the expected number of roots
 */

struct TestCase
{
    double a;
    double b;
    double c;
    double x1_Stated;
    double x2_Stated;
    int nRoots_Stated;
};

/**
 * @brief Checks the number for equality to zero
 * @param a the number being compared to zero
 * @return Return true or false
 */

bool IsZero (double a);

/**
 * @brief Calculates the roots of a quadratic equation
 *        by three input coefficients
 * @param a the square equation coefficient
 * @param b the square equation coefficient
 * @param ñ the square equation coefficient
 * @param x1 the first root
 * @param x2 the second root
 * @return Returns the number of roots
 */

enum RootsNumber SolveSquare (double a, double b, double c, double* x1, double* x2);

/**
 * @brief Checks of the SolveSquare function
 */

int CheckTest ();

/**
 * @brief Scans three numbers from the command line
 * @param a the first scanned number
 * @param b the second scanned number
 * @param c the fhird scanned number
 */

void ScanCoeffs (double* a, double* b, double* c);

/**
 * @brief Outputs the number of roots and the roots of the equation
 * @param RootsNumber nRoots the number of roots
 * @param x1 the first root
 * @param x2 the second root
 */

void PrintRoots (enum RootsNumber nRoots, double x1, double x2);

#endif
