#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 10

typedef enum {false, true} Bool;

// create Queue data type
typedef struct{
    int QueueArr[MAXQUEUE];
    int front;
    int rear;
    int count;
}Queue;

// create Queue
void CreateQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// check queue empty
Bool isQueueEmpty(Queue *q){
    return(q->rear < q->front);
}

// check queue full
Bool isQueueFull(Queue *q){
    return(q->rear == MAXQUEUE - 1);
}

// Append
void Append(Queue *q, int item){
    if(isQueueFull(q)){
        printf("Queue is full\n");
        exit(1);
    }
    else{
        q->rear++;
        q->QueueArr[q->rear] = item;
        q->count++;
    }
}

// serve
void Serve(Queue *q, int *intptr){
    if(isQueueEmpty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    else{
        *intptr = q->QueueArr[q->front];
        q->front++;
        q->count--;
    }
}

// display
void display(Queue *q){
    if(isQueueEmpty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    else{
        for(int i=q->front; i<=q->rear; i++){
            printf("%d| ", q->QueueArr[i]);
        }
    }
}

int main(){

    Queue myqueue;
    CreateQueue(&myqueue);
    int garbage;

    Append(&myqueue, 3);
    Append(&myqueue, 6);
    Append(&myqueue, 9);
    Append(&myqueue, 12);
    Append(&myqueue, 15);
    Append(&myqueue, 18);

    // display queue
    display(&myqueue);

    // Serve
    Serve(&myqueue, &garbage);
    printf("\nAfter serve \n");
    display(&myqueue);
    printf("Served item %d", garbage);

    Serve(&myqueue, &garbage);
    printf("\nAfter serve \n");
    display(&myqueue);
    printf("Served item %d", garbage);

    return 0;
}