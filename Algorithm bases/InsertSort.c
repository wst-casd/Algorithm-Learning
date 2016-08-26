
// Insertion Sort
void InsertSort( int *arr, int length )
{
    if( length <= 1 )
        return;
    else{
        int pivotkey, j;

        for( int i = 1; i < length; ++i )
        {
            if( arr[i] < arr[i-1] )
            {
                pivotkey = arr[i];

                for ( j = i-1; j >= 0 && arr[j] > pivotkey ; --j )
                    arr[j+1] = arr[j];

                arr[j+1] = pivotkey;
            }
        } 
    } 
}

//insertion Sort  bu binary search
void BInsertSort( int *arr, int length )
{
    if( length <= 1 )
        return;
    else{
        int low, high, mid, pivotkey;

        for (int i = 1; i < length; ++i)
        {
            if( arr[i] < arr[i-1] )
            {
                low = 0;
                high = i-1;

                pivotkey = arr[i];
                while( low <= high )
                {
                    mid = ( low + high ) >> 1;
                    if ( arr[mid] > pivotkey )
                        high = mid - 1;
                    else if ( arr[mid] < pivotkey )
                                low = mid + 1;
                            else
                                break;
                }

                for (int j = i-1; j >= mid; --j)
                    arr[j+1] = arr[j];

                arr[mid] = pivotkey;
            }    
        }
    }
}
