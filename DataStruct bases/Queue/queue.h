#ifndef _CIRCULARQUEUE_H
#define _CIRCULARQUEUE_H

#define QElemType int
#define QUEUESIZE 100

typedef struct{
    QElemType *base;
    int front;
    int rear;
}CQueue;
    
int createQueue( CQueue *Q );
int queueLength( CQueue const Q );
int enQueue( CQueue *Q, QElemType value );
int deQueue( CQueue *Q, QElemType *e );
int isEmpty( const CQueue Q );
int isFull( const CQueue Q );
QElemType getfront( const CQueue Q );

#endif