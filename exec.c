#include "library.h"
/**
 * @brief Exec command
 * 
 * This function emulates the exec command basically
 * it runs a command and then exits
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @return void
 * */
void execMe(char *cmd){
    int cnt=0;
    int i =0,spaces=0;
 
    for(i=0;i<strlen(cmd);i++){
        if(!isspace(cmd[i]) && i > 4 ){
           spaces++;
        }
    }
    char new_cmd[spaces];
    for(i=0;i<strlen(cmd)+1;i++){
        if( i > 4 ){
            new_cmd[cnt++] = cmd[i];
        }
    }
    if(isBuilt(new_cmd) != -1){
        exit(0);
    }
    char *name[] = {"/bin/bash","-c",new_cmd, NULL};
    execvp(name[0], name);
}