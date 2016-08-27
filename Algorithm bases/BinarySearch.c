
int BinarySearch( int const* arr, int length, int key )
{
    if( length <= 0 || arr[0] > key || arr[length-1] < key )
        return -1;

    int low = 0, high = length - 1, mid;

    while( low <= high )
    {
        mid = ( low + high ) >> 1;

        if( arr[mid] == key )
            return mid;
        else if ( arr[mid] > key )
                    high = mid - 1;                  
                else
                    low = mid + 1;
    }

    return -1;
}

