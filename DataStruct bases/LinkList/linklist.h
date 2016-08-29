#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct  NODE{
    int value;
    struct NODE *next;
} Node;

Node* createList(  int num );
int listLength( Node *head );
int insert( Node **head, const int value );
int delete( Node **head, Node *node );
void reverse( Node **head );

#endif
