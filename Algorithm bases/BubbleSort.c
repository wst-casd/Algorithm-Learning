
//Bubble Sort with a flag to indicate that whethor or not the exchange happened in last turn
void BubbleSort( int *arr, int length )
{
    int iter = length-1, tmp, flag = 1;

    while( flag ){
        flag = 0;
        for (int i = 1; i <= iter; ++i){
            if (arr[i] < arr[i-1]){
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
    int tmp, pos = length-1, iter;

    while( pos > 0 ){
        iter = pos;
        pos = 0;
        for (int i = 1; i <= iter; ++i){
            if (arr[i] < arr[i-1]){
                tmp      = arr[i];
                arr[i]     = arr[i-1];
                arr[i-1]  =  tmp;
                pos = i-1;
            }
        }
    }
}


//Binary search Bubble Sort
void BiBubbleSort( int *arr, int length )
{
    if( NULL == arr )
        return;
    
    int low = 0, high = length-1, tmp, pos;

    while( low < high ){
        for (int i = low; i < high; ++i){
            pos = low;
            if (arr[i+1] < arr[i]){
                tmp       = arr[i+1];
                arr[i+1]  = arr[i];
                arr[i]      =  tmp;
                pos = i; 
            }
        }

        high = pos;

        for (int j = high; j > low; --j){
            pos = high;
            if (arr[j] < arr[j-1]){
                tmp       = arr[j];
                arr[j]      = arr[j-1];
                arr[j-1]   =  tmp;
                pos = j; 
            }
        }

        low = pos;
    }
}
