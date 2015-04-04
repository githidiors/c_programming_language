#include <stdio.h>
#include <time.h>

/* getbits: get n bits from position p
   position 0 is at the rightmost
 */
unsigned getbits(unsigned x, int p, int n)
{
    //unsigned x1 = x >> (p+1-n);
    //x = x1 & (~(~0 << n));
    //return x;
    return (x >> (p+1-n)) & (~(~0 << n)); // ~0 is independent of word length
}

/* returns x with the n bits that begin at position p set to the rightmost */
/* n bits of y, leaving the other bits unchanged */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x | ((y & (~(~0 << n))) << (p+1-n));
}

/* returns x with the n bits that begin at position p inverted, leaving the  */
/* others unchanged */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ ((~(~0 << n)) << (p+1-n));
}

/* returns the value of the integer x rotated to the right by n bit position */
int rightrot(int x, int n)
{
    unsigned ux = (unsigned)x;
    int m = 1;
    if (0 == x)
        return 0;
    while (ux >> 1)
        m++;
    return (int)((ux << n) | (ux | (~(~0 << (m-n)))));
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
            b++;
    }

    return b;
}
/* x &= (x-1) deletes the rightmost 1-bits in x */
int bitcount_v2(unsigned x)
{
    int b = 0;

    while (x)
    {
        b++;
        x &= (x-1);
    }

    return b;
}

void compare_bitcount()
{
    clock_t time_taken;
    int i, j;

    for (i = 0, time_taken = clock(); i < 10000; i++)
        for (j = 0; j < 10000; j++) {
            bitcount(j);
        }
    time_taken = clock() - time_taken;
    printf("bitcount took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);

    for (i = 0, time_taken = clock(); i < 10000; i++)
        for (j = 0; j < 10000; j++) {
            bitcount_v2(j);
        }
    time_taken = clock() - time_taken;
    printf("bitcount V2 took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
}

int main(int argc, char* argv[])
{
    printf("0x%x\n", getbits(0xa2, 5, 5));
    printf("0x%x\n", getbits(0xa2, 5, 4));
    printf("0x%x\n", getbits(0xa2, 5, 6));

    printf("0x%x\n", setbits(0xa2, 5, 2, 0xf));

    printf("0x%x\n", invert(0xa2, 5, 6));

    printf("0x%x has %d bits\n", 0xb8, bitcount(0xb8));
    printf("0x%x has %d bits\n", 0xb8, bitcount_v2(0xb8));

    compare_bitcount();

    return 0;
}
