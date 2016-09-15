
//one shell insertion sort
void ShellInsert( int *arr, int gap, int length )
{
    int tmp, j;
    for (int i = gap; i < length; ++i)
    {
        if ( arr[i] < arr[i-gap] )
        {
            tmp = arr[i];
            for (j = i-gap; j >= 0 && arr[j] > tmp; j -= gap)
                arr[j+gap] = arr[j];

            arr[j+gap] = tmp;
        }
    }
}

//shell sort
//In fact, the gap function can be replaced with other forms
void ShellSort( int *arr, int length )
{
    if ( NULL == arr )
        return;
    else{
        for( int gap = length >> 1; gap > 0; gap >= 1 )
            ShellInsert( arr, gap, length );
    }
}
