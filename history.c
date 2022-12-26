#include "library.h"
/**
 * @brief print current session history
 * 
 * We use a queue to store the command we have ran
 * when we want to print them all we dequeue and queue
 * queue size times
 * 
 * @author Michail-Panagiotis Bofos
 * @param queue history queue
 * @return void
 * */
void printHistory(Queue *queue){
    int size = queue->length,i;
    for(i=0;i<size;i++){
        char **returned = malloc(sizeof(char)*MAX_CMD);
        dequeue(queue,returned);
        printf("%d) %s\n",(i+1),*returned);
        enqueue(*returned,queue);
        free(returned);
    }
}