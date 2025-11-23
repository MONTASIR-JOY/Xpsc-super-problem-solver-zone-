#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int generterandomnumbers(int n)
{
    n++;
    return rand() % n;
}
int main()
{
    srand(time(NULL));
    printf("Random number Between 1 to 5 is %d\n", generterandomnumbers(5));
    return 0;
}