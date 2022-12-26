#include "library.h"
/**
 * @brief Reformat a pipe command
 * 
 * This function adds a space right and left
 * of the pipe symbol and one at the end
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @param cmd1 the new command we reformat
 * @return void 
 * */
void breakPipe(char *cmd,char *cmd1){
    int i=0,len=strlen(cmd),cnt1=0;
    
    for(i=0;i<len;i++){
        cmd1[cnt1++] = cmd[i];
        if(cmd[i+1]=='|'){
            cmd1[cnt1++]=' ';
        }
        if(cmd[i]=='|'){
            cmd1[cnt1++]=' ';
        }
    }
    cmd1[cnt1++]=' ';
}
/**
 * @brief Find how many commas exist
 * 
 * This function finds how many commas
 * exists in a string
 * 
 * @author Michail-Panagiotis Bofos
 * @param str the original string
 * @return int
 * */
int findCommas(char *str){
    int c = 0, i = 0;
    for(i=0;i<strlen(str);i++)
        if(str[i]==';')
            c++;
    return c;
}
/**
 * @brief Add a space at the end of a string
 * 
 * This function add a space to the end
 * of a string
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original string
 * @param cmd1 the new string we generate
 * @return void
 * */
void addSpace(char *cmd,char *cmd1){
    int i=0,len=strlen(cmd),cnt1=0;
    
    for(i=0;i<len;i++){
        cmd1[cnt1++]=cmd[i];
     
    }
    cmd1[cnt1++]=' ';
}