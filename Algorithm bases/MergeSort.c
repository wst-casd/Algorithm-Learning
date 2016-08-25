#include<stdio.h>

//Bubble Sort with a flag to indicate that whethor or not the exchange happened in last turn
void BubbleSort( int *arr, int length )
{
    int iter = length-1, tmp, flag = 1;

    while( flag )
    {
        flag = 0;
        for (int i = 1; i <= iter; ++i)
        {
            if (arr[i] < arr[i-1])
            {
                tmp      = arr[i];
                arr[i]     = arr[i-1];
                arr[i-1] =  tmp;
                flag = 1;
            }
        }
        --iter;
    }
}

//Bubble Sort with recording the final exchanging position in last turn
void BubbleSort_1( int *arr, int length )
{
    int tmp, flag = length-1, iter;

    while( flag > 0 )
    {
        iter = flag;
        flag = 0;
        for (int i = 1; i <= iter; ++i)
        {
            if (arr[i] < arr[i-1])
            {
                tmp      = arr[i];
                arr[i]     = arr[i-1];
                arr[i-1] =  tmp;
                flag = i-1;
            }
        }
    }
}


//Binary search Bubble Sort
void BiBubbleSort( int *arr, int length )
{
    int low = 0, high = length-1, tmp, pos;

    while( low < high )
    {
        for (int i = low; i < high; ++i)
        {
            if (arr[i+1] < arr[i])
            {
                tmp       = arr[i+1];
                arr[i+1]  = arr[i];
                arr[i]      =  tmp;
                pos = i; 
            }
        }

        high = pos;

        for (int j = high; j > low; --j)
        {
            if (arr[j] < arr[j-1])
            {
                tmp      = arr[j];
                arr[j]     = arr[j-1];
                arr[j-1] =  tmp;
                pos = j; 
            }
        }

        low = pos;
    }
}

int main()
{
    //int a[] = { 49, 38, 65, 97, 76, 13, 27, 49, 55, 4 };
    int a[] = { 49, 45 };

    int len = sizeof(a)/sizeof(int);
    BiBubbleSort( a, len );

    for (int i = 0; i < len; ++i)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}