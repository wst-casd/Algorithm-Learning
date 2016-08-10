
void Swap( int *varA, int *varB )
{
	int varTemp;

	varTemp = *varA;
	*varA = *varB;
	*varB = varTemp;
}

int SelectPivot( int arr[], int low, int high )
{
	int mid = ( low + high ) >> 1;

	if( arr[low] <= arr[mid] )
	{
		if( arr[mid] <= arr[high] )
			Swap( &arr[low], &arr[mid] );
		else
			if( arr[low] < arr[high] )
				Swap( &arr[low], &arr[high] ) ;
	}
	else
	{
		if( arr[mid] > arr[high] )
			Swap( &arr[low], &arr[mid] ;
		else
			if( arr[low] > arr[high] )
				Swap( &arr[low], &arr[high] );
	}

	return arr[low];
}

void BasicQuickSort( int arr[], int low, int high )
{
	if( high <= low )		//	
		return ;
			
	int pivotKey = arr[low];

	int left = low, right = high;
	while( left < right )
	{
		while( left < right && pivotKey <= arr[right] )	right--;
		arr[left] = arr[right];

		while( left < right && pivotKey >= arr[left] )	left++ ;
		arr[right] = arr[left];
	}

	arr[left] = pivotKey;

	BasicQuickSort( arr, low, left-1 );
	BasicQuickSort( arr, left+1, high );
}

void QuickSort( int arr[], int low, int high )
{
	if( high <= low )		//	
		return ;
			
	int pivotKey = arr[low];	//枢纽元
	int left = low, right = high;
	int leftCursor = low, rightCursor = high;
	int leftLen = 0, rightLen =0;

	while( left < right )
	{
		while( left < right && pivotKey <= arr[right] )	
		{
			if( pivotKey == arr[right] )
			{
				Swap( &arr[right], &arr[rightCursor] );
				rightCursor --;
				rightLen ++;
			}
			right--;
		}
		arr[left] = arr[right];

		while( left < right && pivotKey >= arr[left] )	
		{
			if( pivotKey == arr[left] )
			{
				Swap( &arr[left], &arr[leftCursor] );
				leftCursor ++;
				leftLen ++;
			}
			left++;
		}
		arr[right] = arr[left];
	}

	arr[left] = pivotKey;

	int ind_i = low;
	int ind_j = left - 1;
	while( ind_i < leftCursor && ind_i < ind_j && pivotKey == arr[ind_i] )
	{
		Swap( &arr[ind_i], &arr[ind_j] );
		ind_i ++;
		ind_j --;
	}

	int ind_m = left + 1;
	int ind_n = high;
	while( ind_n > right && ind_n > ind_m && pivotKey == arr[ind_i] )
	{
		Swap( &arr[ind_i], &arr[ind_j] );
		ind_i ++;
		ind_j --;
	}

	QuickSort( arr, low, left-1 );
	QuickSort( arr, left+1, high );
}


