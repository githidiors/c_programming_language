#include <stdio.h>

/******************************/
/*
Shell sort for sorting an array of integers.
The basic idea of this sorting algorithm, which was invented in 1959 by
D.L.Shell, is that in early stages, far-apart elements are compared, rather
than adjacent ones as in simpler interchange sorts.This tends to eliminate large
amounts of disorder quickly, so later stages have less work to do. The interval
between compared elements is gradually decreased to one, at which point the sort
effectively becomes an adjacent interchange method.
*/
/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

void test_shellsort()
{
    int i;
    int v[] = {100, 71, 70, 44, 23, 18, 30, 41};

    for (i = 0; i < 8; i++)
        printf("%d\t", v[i]);
    printf("\n");

    shellsort(v, 8);

    for (i = 0; i < 8; i++)
        printf("%d\t", v[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    test_shellsort();

    return 0;
}
