#include "library.h"

/**
 * @brief Run a ucyshell command
 * 
 * This function is one of the most important functions of
 * this project, it checks if a command is built in, has a pipe, or its 
 * a basic command and handles it accordingly.
 * 
 * We check how many active commands we have ( < 10)
 * When a command is executed we insert it in a queue
 * 
 * If the command is exit, logout or bye it returns false
 * otherwise true
 * @bug There is not resources check might lead to a deadlock
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @return bool
 * */
bool run(char *cmd){
    //signal (SIGCHLD, delete_zombies);
    int status;
    int pid;
   // bool background = false;
   // if(hasA(cmd,'&'))
   // {
   //    background = true;
   // }
   //    printf("ACTIVE: %d\n",active);*/
        if(active >= MAX_SOURCES)
            {   
                printf("Insufficient  Resources\n"); 
                printf("Abort command `%s`\n",cmd);
             

                return true;
            }
        int build = isBuilt(cmd);
        if(build == 0){
            return false;
        }
        else if(build != -1){
            return true;
        }
        if(hasPipe(cmd)){
            active++;
            enqueue(cmd,queue);
            char *cmdpipe = malloc(sizeof(char)*(strlen(cmd)+5));
            breakPipe(cmd,cmdpipe);
            runPipe(cmdpipe);
            free(cmdpipe);
            active--;
            return true;
        }
        active++;

        if ( (pid = fork()) < 0) 
            perror("fork error");
        else if (pid == 0) { /* child 1 */
        char *name[] = {"/bin/bash","-c",cmd, NULL};
        execvp(name[0], name);
        }
        else { /* parent */
            wait(&status);
            active--;
         enqueue(cmd,queue);
        }
 
    return true;
    
}