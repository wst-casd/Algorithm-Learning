
#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

Node* createList(  int num )
{
    Node *head;
    Node *cur;
    Node *newNode;
    int value;

    head = NULL;

    for (int i = 0; i < num; ++i)
    {
        scanf( "%d", &value );
        newNode = ( Node* )malloc( sizeof( Node ) );

        if( newNode == NULL )
            exit( 0 );

        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    return head;
}

int listLength( Node *head )
{
    int len = 0;

    while( head != NULL )
    {
        ++ len;
        head = head->next;
    }

    return len;
}

int listInsert( Node **linkp, const int value )
{
    Node *newNode;

    while( (*linkp) != NULL && (*linkp)->value < value )
        linkp = &(*linkp)->next;

    newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
        return 0;

    newNode->value = value;

    newNode->next = *linkp;
    *linkp = newNode;

    return 1;
}

int listDelete( Node **linkp, Node const *node )
{
    Node *cur;

    while( (*linkp) != NULL && (*linkp) != node )
        linkp = &(*linkp)->next;

    cur = *linkp;
    if( cur != NULL )
    {
        *linkp = cur->next;
        free( cur );
        return 1;
    }
    else
        return 0;
}

void reverse( Node **head )
{
    Node *cur=*head;
    Node *later; 
    *head = NULL;

    while( cur != NULL )
    {
        later = cur->next;
        cur->next = *head;
        *head = cur;
        cur = later;
    }
}
