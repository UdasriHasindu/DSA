#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// list data
typedef int listData;

// node structure
typedef struct listnode
{
    listData element;
    struct listnode *next;
} ListNode;

// Implementation of the linked list
typedef struct
{
    ListNode *head;
    int count;
    bool full;
} LinkedList;

// create and initialize the list
void CreateList(LinkedList *l)
{
    l->head = NULL;
    l->count = 0;
    l->full = false;
}

// Check list is empty
bool isListEmpty(LinkedList *l)
{
    return (l->head == NULL);
}

// Check list is full
bool isListfull(LinkedList *l)
{
    return (l->full);
}

// Return the size of the list
int ListSize(LinkedList *l)
{
    return (l->count);
}

// Make a list node and return its address
ListNode *MakeListNode(listData x)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode != NULL)
    {
        newNode->element = x;
        newNode->next = NULL;
    }
    return newNode;
}

// Set the position in the list and get the pointer to the node at that position
void SetPosition(LinkedList *l, int position, ListNode **current)
{
    if (position < 0 || position > l->count)
    {
        printf("Invalid position\n");
        *current = NULL;
        return;
    }

    *current = l->head; // Start at the head
    for (int i = 0; i < position; i++)
    {
        *current = (*current)->next;
    }
}

// Insert a node at a given position
void InsertList(LinkedList *l, int position, listData x)
{
    if (position < 0 || position > l->count)
    {
        printf("Invalid position to insert.\n");
        return;
    }

    ListNode *newNode = MakeListNode(x);
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Inserting at the head
    if (position == 0)
    {
        newNode->next = l->head;
        l->head = newNode;
    }
    else
    {
        // Find the node just before the insertion position
        ListNode *prev = NULL;
        SetPosition(l, position - 1, &prev);
        if (prev != NULL)
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    l->count++;
}

// Function to display the list
void DisplayList(LinkedList *l)
{
    ListNode *temp = l->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->element);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the linked list
int main()
{
    LinkedList list;
    CreateList(&list);

    InsertList(&list, 0, 10); // Insert at head
    InsertList(&list, 1, 20); // Insert at the end
    InsertList(&list, 1, 15); // Insert in the middle
    InsertList(&list, 0, 5);  // Insert at head again

    printf("Linked List Elements:\n");
    DisplayList(&list);

    printf("List size: %d\n", ListSize(&list));

    return 0;
}
