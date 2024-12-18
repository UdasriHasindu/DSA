#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create node data type
typedef struct node
{
    int queueIteme; //  |   item | next ptr |
    struct node *next;
} Node;

// create LinkedQueue data tyoe
typedef struct
{
    Node *front;
    Node *rear;
    int count;
    bool full;
} LinkedQueue;

// intialize the LinkedQueue
void CreateQueue(LinkedQueue *lq)
{
    lq->front = NULL;
    lq->rear = NULL;
    lq->count = 0;
    lq->full = false;
}

// check queue empty
bool isQueueEmpty(LinkedQueue *lq)
{
    return (lq->front == NULL && lq->rear == NULL);
}

// check queue full
bool isQueueFull(LinkedQueue *lq)
{
    return (lq->full);
}

// append
void Append(LinkedQueue *lq, int x)
{

    Node *nptr; // create new node
    nptr = (Node *)malloc(sizeof(Node));

    if (nptr == NULL)
    {
        printf("Memory is not enough\n");
        lq->full = true;
        return;
    }
    else
    {
        nptr->queueIteme = x;
        nptr->next = NULL;

        if (isQueueEmpty(lq))
        {
            lq->front = lq->rear = nptr;
        }
        else
        {
            lq->rear->next = nptr;
            lq->rear = nptr; // Update the rear pointer
        }

        lq->count++;
    }
}

// serve
void Serve(LinkedQueue *lq, int *servedItem)
{

    Node *temp;

    if (isQueueEmpty(lq))
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        *servedItem = lq->front->queueIteme;

        temp = lq->front;            // Assign the address of served node to a variable
        lq->front = lq->front->next; // Assign the address of the second node to the front of the queue

        // if there is no any node in queue
        if (lq->front == NULL)
        {
            lq->rear = NULL;
        }
        free(temp); // free up the served node
    }
}

void DisplayQueue(LinkedQueue *lq)
{

    Node *temp;
    temp = lq->front;
    if (isQueueEmpty(lq))
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d |", temp->queueIteme);
            temp = temp->next;
        }
    }
}

int main()
{

    LinkedQueue myQueue;
    CreateQueue(&myQueue);
    int garbageCollector;

    Append(&myQueue, 8);
    Append(&myQueue, 16);
    Append(&myQueue, 32);
    Append(&myQueue, 64);
    Append(&myQueue, 128);

    DisplayQueue(&myQueue);

    printf("\n\nAfter served\n");
    
    Serve(&myQueue, &garbageCollector);
    printf("\nServed item %d\n", garbageCollector);
    DisplayQueue(&myQueue);

    Serve(&myQueue, &garbageCollector);
    printf("\nServed item %d\n", garbageCollector);
    DisplayQueue(&myQueue);

    return 0;
}