#include<stdio.h>


int main()
{
    int a[] = { 49, 38, 65, 97, 76, 13, 27, 49, 55, 4 };

    int len = sizeof(a)/sizeof(int);
    //ShellSort( a, len );

    for (int i = 0; i < len; ++i)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}