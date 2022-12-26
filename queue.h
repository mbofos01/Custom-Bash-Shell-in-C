#ifndef QUEUE_H
#define QUEUE_H
/**
* @brief A char* node
* 
* A node has its value and a pointer
* to the next node
*
*
**/
typedef struct node{
  char *data;
  struct node *next;
}NODE;
/**
* @brief A queue containing nodes
*	
* A queue is a set of nodes with each one
* pointing to another
*
*
**/
typedef struct {
  int length;
  NODE *head;
  NODE *tail;
}Queue;

Queue *initQueue();
int isEmpty(Queue *queue);
char *peek(Queue *queue);
int enqueue(char *value,Queue *queue);
int dequeue(Queue *queue,char **return_value);
void freeSpace(Queue *queue);
#endif
