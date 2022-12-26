#include "library.h"
/**
 * @brief Export command
 * 
 * This function emulates the export command.
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @return void
 * */
void export(char *cmd){
    int i=0,len=strlen(cmd);
    char varName[MAX_VAR],value[MAX_VAR];
    int cnt1=0,cnt2=0;
    bool change = false;
    for(i=7 ;i<len;i++){
        if(cmd[i]=='=')
            change=true;
        if(!change && !isspace(cmd[i]))
            varName[cnt1++] = cmd[i];
        else if(!isspace(cmd[i]) && change && cmd[i]!='=')
            value[cnt2++] = cmd[i];
    }
    varName[cnt1]='\0';
    value[cnt2]='\0';
    setenv(varName,value,1);

    return;
}
