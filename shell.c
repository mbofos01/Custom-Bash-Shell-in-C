#include "library.h"
 bool running;
 Queue *queue;
 int active;
 int used;
 
 /**
  * @brief Shell 
  * 
  * This is the most important part of the project.
  * In a loop we request from the user to enter a 
  * command for our shell, if it is exit, logout or bye
  * we terminate the loop, otherwise we execute the command.
  * 
  * @author Michail-Panagiotis Bofos
  * @date 30/03/2021
  * @version 1.0.0
  * @return int 
  * */
 
int main(void){
    queue = NULL;
    queue = initQueue();
    running = true;
    active = 0;
    used=0;
    char *buffer = NULL;

    do{
        buffer = malloc(sizeof(char)*MAX_CMD);
        printf("%d)%s@%s%s - ucysh > ",used,getenv("USER"),getenv("HOSTNAME"),getenv("PWD"));
        fgets(buffer,MAX_CMD,stdin);
        strtok(buffer, "\n");
        if(equals(buffer,"exit")||equals(buffer,"logout")||equals(buffer,"bye")){
            running = false;
            free(buffer);
            continue;
        }
        buffer = strtok(buffer, ";");
        while (buffer != NULL && running ) { 
            running = run(buffer);
            buffer = strtok(NULL, ";"); 
        }  
        used++;
        free(buffer);
    }while(running);
    freeSpace(queue);
    free(queue);
   return 0;
}
