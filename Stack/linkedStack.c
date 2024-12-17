#include <stdio.h>
#include <stdlib.h>

typedef int stackDataType;

typedef enum
{
    false,
    true
} Bool;

// create a node
typedef struct node
{
    stackDataType item;
    struct node *next;
} Node;

// create linked stack type
typedef struct
{
    int no_ele;
    Bool full;
    Node *top;

} LinkedStack;

// create and initialize
void CreateStack(LinkedStack *ls)
{
    ls->top = NULL;
    ls->full = false;
    ls->no_ele = 0;
}

// stack empty
Bool isStackEmpty(LinkedStack *ls)
{
    return (ls->top == NULL);
}

// stack full
Bool isStackFull(LinkedStack *ls)
{
    return (ls->full);
}

// push operation
void Push(LinkedStack *ls, stackDataType x)
{
    Node *nptr; // create pointer to a new node
    nptr = (Node *)malloc(sizeof(Node));

    // If malloc fails (returns NULL)
    if (nptr == NULL)
    {
        printf("Not enough memory\n");
        ls->full = true;
    }

    else
    {
        nptr->item = x;
        nptr->next = ls->top; // top is containing previous node address. it assign to new node's next pointer
        ls->top = nptr;       // new node's address is assign to the top pointer
        ls->no_ele++;         // increment no of elements
    }
}

// pop operation
void Pop(LinkedStack *ls)
{
    Node *nptr; // create tempary pointer to track node address

    nptr = ls->top; // assigned the address of the current top node
    ls->top = ls->top->next;
    ls->no_ele--;
    free(nptr);
}

// display stack
void DisplayStack(LinkedStack *ls)
{

    Node *np;
    np = ls->top;

    if (isStackEmpty(ls))
    {
        printf("Stack is empty\n");
    }
    while (np != NULL)
    {
        printf("%d |", np->item);
        np = np->next;
    }
}

int main()
{
    LinkedStack stack;
    CreateStack(&stack);

    // Push some elements onto the stack
    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);
    DisplayStack(&stack);
    // Pop elements from the stack
    printf("Popping elements...\n");
    Pop(&stack);

    DisplayStack(&stack);

    return 0;
}
