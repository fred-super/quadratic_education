#include "file.h"

int CheckTest ()
{
    struct TestCase line;

    FILE *file = fopen("test.txt", "r");

    if (file == NULL)

    {
        printf ("ERROR, file not found");
        return 0;
    }

    int scan_return = fscanf (file, "%lf %lf %lf %lf %lf %d",
                                    &line.a, &line.b, &line.c,
                                    &line.x1_Stated, &line.x2_Stated,
                                    &line.nRoots_Stated);
    int nTest = 1;
    double x1 = 0;
    double x2 = 0;

    while (scan_return == 6)

    {
        printf("íà÷àë òåñòû\n");

        int nRoots = SolveSquare (line.a, line.b, line.c, &x1, &x2);
        if (nRoots != line.nRoots_Stated || !IsZero (x1 - line.x1_Stated) || !IsZero(x2 - line.x2_Stated))

        {
            printf ("ERROR TEST %d, a = %lf, b = %lf, c = %lf\n"
                    "x1 = %lf, x2 = %lf, nRoots = %d\n"
                    "x1_Stated = %lf, x2_Stated = %lf, nRoots_Stated = %d\n",
                    nTest, line.a, line.b, line.c,
                    x1, x2, nRoots,
                    line.x1_Stated, line.x2_Stated, line.nRoots_Stated);
        }

        else

        {
            printf ( "òåñò %d ïðîéäåí\n", nTest);
        }

        nTest++;

        scan_return = fscanf (file, "%lf %lf %lf %lf %lf %d",
                                    &line.a, &line.b, &line.c,
                                    &line.x1_Stated, &line.x2_Stated,
                                    &line.nRoots_Stated);
    }

    printf ("êîíåö òåñòîâ");

    fclose(file);

    return 0;
}


