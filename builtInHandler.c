#include "library.h"
/**
 * @brief Check and execute a built in command
 * 
 * This function basicaly runs the built in commands of our
 * shell. At this point we only have around 10 commands.
 * exit,logout,history,cd,pwd,exec,kill,export,read,echo
 * 
 * The implementation of these are in seperate files
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the command we want to check if it is a built in
 * @returns zero if we want to quit, a positive if its a built in and minus one if its not a built in command
 * */
int isBuilt(char *cmd){
    if(equals(cmd,"exit") || equals(cmd,"logout") || equals(cmd,"bye")){
        return 0;
    }
    if(equals(cmd,"history")){
        printHistory(queue);
        enqueue(cmd,queue);
        return 1;
    }
    if(startsWith(cmd,"cd")){
        int new_len = strlen(cmd) - 2,i=0,cnt=0;
        new_len = 7;

        char *directory = malloc(sizeof(char)*new_len);
        for(i=0;i<strlen(cmd);i++){
            if(!isspace(cmd[i]) && i > 2 ){
                directory[cnt++] = cmd[i];
            }
        }
        changeDirectory(directory);
        enqueue(cmd,queue);
        return 2;
    }
    if(equals(cmd,"pwd")){
        printWorkingDirectory();
        enqueue(cmd,queue);
        return 3;
    }
    if(startsWith(cmd,"exec")){
        execMe(cmd);
        enqueue(cmd,queue);
        return 4;
    }
    if(startsWith(cmd,"kill")){
        int cnt=0;
        int i =0,nums=0;
        if(equals(cmd,"kill-l")){
            printSingals();
            enqueue(cmd,queue);
            return 51;
        }
        for(i=0;i<strlen(cmd);i++){
            if(isdigit(cmd[i])){
            nums++;
            }
        }
        char new_cmd[nums];
        for(i=0;i<strlen(cmd);i++){
            if(isdigit(cmd[i])){
                new_cmd[cnt++] = cmd[i];
            }
        }
        killProcess(atoi(new_cmd));
        enqueue(cmd,queue);
            return 5;
    }
    if(startsWith(cmd,"read")){
        readMe(cmd);
        enqueue(cmd,queue);
        return 6;
    }

    if(startsWith(cmd,"echo")){
        if(contains(cmd,"-e") ||contains(cmd,"-E") )
            return -1;
        echo(cmd);
        enqueue(cmd,queue);
        return 7;
    }
    if(equals(cmd,"export")){
        seeVariables();
        enqueue(cmd,queue);
        return 8;
    }
    if(startsWith(cmd,"export")){
        export(cmd);
        enqueue(cmd,queue);
        return 9;
    }
    return -1;
}