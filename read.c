#include "library.h"
/**
 * @brief Read command
 * 
 * This function emulates the read command and store a value
 * as an environmental value
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @return void
 * */
void readMe(char *cmd){
    int i=0,len=strlen(cmd);
    char *varName = malloc(sizeof(char)*MAX_VAR);
    int index = 0;
    if(contains(cmd,"-p")){
        bool printing = false;
        for(i=0;i<len;i++){
            if(cmd[i] == '\"'){
                printing = !printing;
                index = i;
            }
            if(printing){
                if(cmd[i] != '\"')
                    printf("%c",cmd[i]);
            }
        }
    }
    else{
        index = 5;
    }
    int cnt = 0;
    for(;index<len;index++){
        if(!isspace(cmd[index]) && cmd[index] != '\"' )
            varName[cnt++] = cmd[index];
    }

    char *value = malloc(sizeof(char)*MAX_VALUE);
    fgets(value,MAX_VALUE,stdin);
    strtok(value, "\n");
    setenv(varName,value,1);
    free(value);
    free(varName);
    return;
}