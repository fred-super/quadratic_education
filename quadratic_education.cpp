#include "file.h"

//#define DEBUG

bool IsZero (double a)
{
    const double zero = 0.000000000001;
    return (fabs(a) < zero);
}

enum RootsNumber SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    if (IsZero(a))

    {
        if (IsZero(b) && IsZero(c))  { return INFINITY_ROOTS; }
        if (IsZero(b) && !IsZero(c)) { return NO_ROOTS; }
                                     { *x1 = -c/b; return ONE_ROOTS; }

    }

    double D = b*b - 4*a*c;

    if (D < 0) { return NO_ROOTS; }

    double Sqrt_D = sqrt(D);
    *x1 = (-b - Sqrt_D) / 2 / a ;
    *x2 = (-b + Sqrt_D) / 2 / a ;

    if (IsZero(*x1 - *x2)) { return ONE_ROOTS; }

    return TWO_ROOTS;
}

/*struct TestCase
{
    double a;
    double b;
    double c;
    double x1_Stated;
    double x2_Stated;
    int nRoots_Stated;
};

int CheckTest ()
{
    struct TestCase arr[] =

    {
      //   a   b   c   x1  x2  nRoots
        {  1,  2,  1, -1, -1,  1 },
        {  1, -6,  0,  0,  6,  2 }
    };

    int i = 0;
    double x1 = 0;
    double x2 = 0;

    size_t array_size = sizeof arr;
    size_t struct_size = sizeof (struct TestCase);
    size_t element_size = array_size / struct_size;

    while (i < element_size)

    {
        int nRoots = SolveSquare (arr[i].a, arr[i].b, arr[i].c, &x1, &x2);
        if (nRoots != arr[i].nRoots_Stated || x1 != arr[i].x1_Stated || x2 != arr[i].x2_Stated)

        {
            printf ("ERROR TEST %d, a = %lf, b = %lf, c = %lf\n"
                    "x1 = %lf, x2 = %lf, nRoots = %d\n"
                    "x1_Stated = %lf, x2_Stated = %lf, nRoots_Stated = %d\n",
                    ++i, arr[i].a, arr[i].b, arr[i].c,
                    x1, x2, nRoots,
                    arr[i].x1_Stated, arr[i].x2_Stated, arr[i].nRoots_Stated);
            return 1;
        }

        else

        i++;
    }
}  */

int main()
{
    double a  =  0;
    double b  =  0;
    double c  =  0;
    double x1 =  0;
    double x2 =  0;

#ifdef DEBUG

    CheckTest();

#else

    ScanCoeffs ( &a, &b, &c);

    enum RootsNumber nRoots = SolveSquare ( a, b, c, &x1, &x2 );

    PrintRoots ( nRoots, x1, x2 );

#endif

    return 0;
}

