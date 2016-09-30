
#include<stdio.h>
#include<string.h>

void makeNext( const char * P, int *next )
{
    int len = strlen( P );
    int curMatchNum = 0;
    next[0] = 0;

    for ( int curPos = 1; curPos < len; ++curPos )
    {
        while( curMatchNum > 0 && P[curMatchNum] != P[curPos] )
            curMatchNum = next[curMatchNum-1];

        if( P[curMatchNum] == P[curPos] )
            ++ curMatchNum;

        next[curPos] = curMatchNum;
    }
}

void kmp( const char *T, const char *P )
{
    int lenT, lenP, j = 0;
    lenT = strlen( T );
    lenP = strlen( P );
    int next[lenP];
    makeNext( P, next );

    for ( int i = 0; i < lenT - lenP + 1; ++i )
    {
        while( j > 0 && P[j] != T[i] )
            j = next[j-1];
        if ( P[j] == T[i] )
            ++ j;
        if( j == lenP )
            printf("Pattern occurs with shift:%d\n", (i-lenP+1));
    }
}
