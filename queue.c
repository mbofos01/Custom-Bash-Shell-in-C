#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
 * @brief Initialize queue
 * 
 * Basic initialization of a char* queue
 * SOURCE: EPL232 Module
 * 
 * @return Queue
 * */
Queue *initQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) 
      return NULL;
    queue->head = queue->tail = NULL;
    queue->length = 0;
    return queue;
  }
/**
 * @brief Enqueue string
 * 
 * Enqueue function, we enter a string in the queue
 * 
 * @param value the value we enqueue
 * @param q the queue
 * @return int
 * */
  int enqueue (char *value, Queue *q) {
      NODE *p = NULL;
      if (q == NULL){ 
        return EXIT_FAILURE; 
      }
      p = (NODE *)malloc(sizeof(NODE));
      if ( p == NULL ) {
        printf("System out of memory…\n");
      return EXIT_FAILURE;
    }
    p->data = value;
    p->next = NULL;
    if (q->length == 0)
      q->head = q->tail = p;
    else { // append on end
      q->tail->next = p;
      q->tail = p;
    }
    (q->length)++;
  return EXIT_SUCCESS;
}
/**
 * @brief Dequeue
 * 
 * Dequeue function, we remove the first string of
 * the queue
 * 
 * @param retval a pointer string we write on
 * @param q the queue
 * @return int
 * */
int dequeue(Queue *q, char **retval) {
  NODE *p = NULL; // copy pointer used for free()
  if ((q == NULL) || (q->head == NULL)) {
  printf("Sorry, queue is empty \n");
  return EXIT_FAILURE;
  }
  if (retval == NULL) {
  printf("Retval is null"); return EXIT_FAILURE; }
  p = q->head;
  *retval = q->head->data;
  q->head = q->head->next;
  free(p);
  --(q->length);
  if (q->length == 0) {
  q->tail = NULL;
  }
return EXIT_SUCCESS;
}
/**
 * @brief Check if queue empty
 * 
 * This function checks if a queue is empty or not
 * 
 * @param queue the queue
 * @return int
 * */
int isEmpty(Queue *queue){
  if(queue->length==0)
      return 1;
  return 0;
}
/**
 * @brief Peek the first value of a queue
 * 
 * This function gets the first string
 * of the queue, without removing it
 * 
 * @param queue the queue
 * @return char*
 * */
char *peek(Queue* queue)
{    if (isEmpty(queue))
        return NULL;
    return (queue->head)->data;
}
/**
 * @brief Clean up space
 * 
 * This function is used to free the space used by
 * a queue
 * 
 * @param queue the queue
 * @return void
 * */
void freeSpace(Queue *queue){
    while (!isEmpty(queue)) {
      char **dump = malloc(sizeof(char)*100);
      dequeue(queue,dump);
      free(*dump);
      free(dump);
    }
}