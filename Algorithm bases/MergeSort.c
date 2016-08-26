
void Merge( int *arr, int* tempArr, int left, int mid, int right )
{
    int i=left, j=mid+1, k=0;

    while( i <= mid && j <= right )
        tempArr[k++] = ( arr[i] <=arr[j] ) ? arr[i++]:arr[j++];

    while( i <= mid )
        tempArr[k++] = arr[i++];

    while( j <= right )
        tempArr[k++] = arr[j++];

    for (i = left, k = 0; i <= right; ++i, ++k)
        arr[i] = tempArr[k];
}

void MergeSort( int *arr, int *tempArr, int left, int right )
{
    int mid;
    if ( left < right )
    {
        mid = (left + right) >> 1;
        MergeSort( arr, tempArr, left, mid );
        MergeSort( arr, tempArr, mid+1, right );
        Merge( arr, tempArr, left, mid, right );
    }    
}
