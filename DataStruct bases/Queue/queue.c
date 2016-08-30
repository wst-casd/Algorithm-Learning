
#include<stdlib.h>
#include"queue.h"

int createQueue( CQueue *Q )
{
    Q->base = (QElemType *)malloc(QUEUESIZE * sizeof(QElemType) );
    if( !(Q->base) ) exit(0);
    Q->front = 0;
    Q->rear = 0;
}

int queueLength( CQueue const Q )
{
    return ( Q.rear - Q.front + QUEUESIZE ) % QUEUESIZE;
}

int enQueue( CQueue *Q, QElemType value )
{
    if( isFull( *Q ) ) return 0;

    Q->base[Q->rear]  = value;
    Q->rear = ( Q->rear +1 ) % QUEUESIZE;
    return 1;
}

int deQueue( CQueue *Q, QElemType *e )
{
    if( isFull( *Q ) ) return 0;

    *e = Q->base[Q->front];
    Q->front = ( Q->front +1 ) % QUEUESIZE;
    return 1;
}

int isEmpty( const CQueue Q )
{
    return Q.front == Q.rear;
}

int isFull( const CQueue Q )
{
    return ( ( ( Q. rear + 1 ) % QUEUESIZE ) == Q.front );
}
 
QElemType getfront( const CQueue Q )
{
    return Q.base[Q.front];
}
