#include "library.h"

/**
 * @brief Print environment variables 
 * 
 * This function prints all the environmental
 * variables of our shell (export)
 * 
 * @author Michail-Panagiotis Bofos
 * @return void
 * */
void seeVariables(void){
    int i;   
        for (i = 0; environ[i] != NULL; i++)
    {
        printf("var = %s - %d\n", environ[i], (int)strlen(environ[i]));
    }
    return;
}
/**
 * @brief Random number generator
 * 
 * This function prints count random numbers 
 * between lower and upper bound
 * 
 * @author Michail-Panagiotis Bofos
 * @param lower smallest number possible
 * @param upper biggest number possible
 * @param count number of random numbers generated
 * @return void
 * */
void printRandoms(int lower, int upper,int count)
{
    int i;
    printf("Random number: ");
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}
/**
 * @brief Echo command
 * 
 * This function emulates the echo command. If the 
 * command contains -n we do not print a new line character
 * and if it contains a $variable we print its value
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the original command we execute
 * @return void
 * */  
void echo(char *cmd){
    srand(time(0));
    char *new_cmd = malloc((sizeof(char)*strlen(cmd))+1);
    addSpace(cmd,new_cmd);
    int cnt =0;
    int i=0,len=strlen(new_cmd);
    bool new_line = false;
    if(!contains(new_cmd,"-n")) 
        new_line = true;
    char possible_variable[MAX_VAR];
    for(i=5;i<len;i++){
       if(new_cmd[i] == '\"')
            continue;
        if(new_cmd[i] != '$')
            printf("%c",new_cmd[i]);
        if(new_cmd[i] == '$'){
            cnt = 0;
            i++;
            while(!isspace(new_cmd[i])){
                possible_variable[cnt++]=new_cmd[i];
                i++;
            } 
             possible_variable[cnt] = '\0';
            if(equals(possible_variable,"RANDOM"))
                printRandoms(10000,99999,1);
            else
                printf("%s", getenv(possible_variable)); 
        }
    }
    if(new_line)
        printf("\n");
    free(new_cmd);
}
