#include <stdio.h>

//#include "filename"
/*
  when preprocessing the source file, the '#include' line is replaced 
  by the content of the file. If the filename is quoted, searching for
  the file typically begins where the source program was found; if the
  file is not found, or if the name is enclosed in < and >, searching
  follows an implementation-defined rule to find the file.

  in GCC, we can set include path with '-I'
*/

//wrong!
#define square(x) x*x

#define square_v1(x) ((x)*(x))

#define swap(t, x, y) do {                      \
        (t) = (x);                              \
        (x) = (y);                              \
        (y) = (t);                              \
    } while (0)

int main()
{
    int i = 1;
    int j = 2;
    int temp;

    printf("%d\t%d\n", i, j);
    swap(temp, i, j);
    printf("%d\t%d\n", i, j);

    return 0;    
}

    
