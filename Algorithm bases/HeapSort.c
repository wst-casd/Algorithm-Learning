
void Swap( int *varA, int *varB )
{
    int varTemp;

    varTemp = *varA;
    *varA = *varB;
    *varB = varTemp;
}

//the procedure of adjust for MaxHeap
void HeapAdjust(int *arr, int s, int length)
{
    int tmp, child;

    for ( tmp = arr[s], child = 2*s+1;  child <= length-1; child = 2*child +1 )
    {
        if( child != length-1 && arr[child+1] > arr[child] )
            ++child;

        if( tmp >= arr[child] )
            break;

        arr[s] = arr[child];
        s = child;
    }

    arr[s] = tmp;
}

void HeapSort( int *arr, int length )
{
    if( NULL == arr )
        return;

    //build heap
    for (int i = (length >> 1) - 1; i >= 0; --i)
        HeapAdjust(arr, i, length);

    //adjust the heap
    for (int j = length-1; j > 0; --j)
    {
        Swap(&arr[0], &arr[j]);
        HeapAdjust(arr, 0, j);
    }
}

