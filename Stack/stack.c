#include <stdio.h>

#define MAXSTACK 20

typedef int stackType;

typedef enum
{
    false,
    true
} Bool;

typedef struct
{
    int top;
    stackType StackArr[MAXSTACK];
} Stack;

// intialize the stack
void CreateStack(Stack *s)
{
    s->top = -1;
}

// check stack empty
Bool isStackEmpty(Stack *s)
{
    return (s->top == -1);
}

// check stack full
Bool isStackFull(Stack *s)
{
    return (s->top == MAXSTACK - 1);
}

// push
void Push(Stack *s, stackType x)
{
    if (isStackFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->StackArr[++s->top] = x;
    }
}

// pop
void Pop(Stack *s, stackType *item)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        *item = s->StackArr[s->top--];
    }
}

// see top most element without popping
stackType Peek(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        return (s->StackArr[s->top]);
    }
}

// traverse
void Traverse(Stack *s)
{
    if (isStackEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        printf("| ");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d| ", s->StackArr[i]);
        }
    }
}
int main()
{
    Stack mystack;
    CreateStack(&mystack);
    int garbage;

    // push operations
    Push(&mystack, 5);
    Push(&mystack, 10);
    Push(&mystack, 15);
    Push(&mystack, 20);
    Push(&mystack, 25);
    Push(&mystack, 30);

    printf("Show stack\n");
    Traverse(&mystack);

    Pop(&mystack, &garbage);
    printf("\nTop most element = %d\n", Peek(&mystack));
    printf("popped element = %d", garbage);

    return 0;
}