#include "file.h"

void ScanCoeffs (double* a, double* b, double* c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    int toEnter = scanf ("%lf %lf %lf", a, b, c);
    int lastS = getchar();

    while (toEnter != 3 || !(lastS == '\n' || lastS == ' '))

    {
        printf ("ERROR\n");

        while (1)

        {
            int sym = getchar();
            if (sym == '\n' || sym == EOF)
            break;
        }

        toEnter = scanf ("%lf %lf %lf", a, b, c);
        lastS = getchar();
    }
}

void PrintRoots (enum RootsNumber nRoots, double x1, double x2)
{
    switch (nRoots)

    {
        case INFINITY_ROOTS:   printf ("áåñêîíå÷íîå ìíîæåñòâî");
                               break;

        case NO_ROOTS:         printf ("íåò ðåøåíèé");
                               break;

        case ONE_ROOTS:        printf ("x1 = %lf", x1);
                               break;

        case TWO_ROOTS:        printf ("x1 = %lf x2 = %lf", x1, x2);
                               break;

        default:               printf ("ERROR");
                               break;
    }
}
