#include <stdio.h>
#include <stdbool.h>

#define MAXLIST 10

typedef char ListData;

typedef struct
{
    int count;
    char listArr[MAXLIST];
} List;

// Create list
void CreateList(List *l)
{
    l->count = 0;
}

// Check if the list is empty
bool isListEmpty(List *l)
{
    return (l->count == 0);
}

// Check if the list is full
bool isListFull(List *l)
{
    return (l->count == MAXLIST);
}

// Size of the list
int ListSize(List *l)
{
    return (l->count);
}

// Insert data into the last position
void InsertLast(List *l, ListData x)
{
    if (isListFull(l))
    {
        printf("List is full, can't insert\n");
    }
    else
    {
        l->listArr[l->count] = x;
        (l->count)++;
    }
}

// Insert data into a specific position
void InsertData(List *l, ListData x, int position)
{
    if (isListFull(l))
    {
        printf("List is full, can't insert\n");
    }
    else if (position < 1 || position > l->count + 1)
    {
        printf("Attempt to insert at invalid position\n");
    }
    else
    {
        for (int i = ListSize(l) - 1; i >= (position - 1); i--)
        {
            l->listArr[i + 1] = l->listArr[i];
        }
        printf("Element %c inserted at position %d\n", x, position);
        l->listArr[position - 1] = x;
        l->count++;
    }
}

// Delete data in a position
void DeleteList(List *l, int position){
    if(isListEmpty(l)){
        printf("Attempt to delete a item from empty list");
    }
    else if(position < 1 || position > l->count + 1){
        printf("Attempt to delete item from invalid position");
    }
    else{
        for(int i= position-1; i < ListSize(l); i++){
            l->listArr[i] = l->listArr[i+1];
        }
        printf("Element deleted at position %d\n", position);
        l->count--;
    }
}

// Traverse and print the list
void TraverseList(List *l)
{
    for (int i = 0; i < l->count; i++)
    {
        printf("%c, ", l->listArr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    List myList;
    CreateList(&myList);

    // Insert elements at the end
    InsertLast(&myList, 'A');
    InsertLast(&myList, 'B');
    InsertLast(&myList, 'C');
    InsertLast(&myList, 'D');
    InsertLast(&myList, 'E');

    printf("Size of the list = %d\n", ListSize(&myList));
    TraverseList(&myList);

    // Insert an element at a specific position
    InsertData(&myList, 'F', 3);
    TraverseList(&myList);

    // Delete element from a specific position
    DeleteList(&myList, 4);
    TraverseList(&myList);

    return 0;
}
