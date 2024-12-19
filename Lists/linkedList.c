#include <stdio.h>

// Define boolean values
typedef enum
{
    FALSE,
    TRUE
} Bool;

typedef int datatype;

// Node
typedef struct listnode
{
    datatype element;
    struct listnode *nextnode
} ListNode;

// Linked list
typedef struct
{
    ListNode *head;
    int count;
    Bool full;
} LinkedList;

// create linked list
void CreateList(LinkedList *l)
{
    l->count = 0;
    l->full = FALSE;
    l->head = NULL;
}

// check list empty
Bool isListEmpty(LinkedList *l){
    return(l->head == NULL);
}

// check list full
Bool isListFull(LinkedList *l){
    return(l->full == TRUE);
}

// Size of the list
int ListSize(LinkedList *l){
    return(l->count);
}

// make list
// listnode MakeListNode(LinkedList )