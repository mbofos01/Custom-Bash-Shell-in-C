#include "library.h"
/**
 * @brief Check if a command is a pipe command
 * 
 * This function checks if a string contains the pipe symbol
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the command we want to check
 * @return bool
 * */
bool hasPipe(char *cmd){
    int i=0,len=strlen(cmd);
    for(i=0;i<len;i++)
        if(cmd[i]=='|')
            return true;
    return false;
}
/**
 * @brief Check equality between strings
 * 
 * This function checks if two string are equal, ignoring
 * the space
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the first string we want to check
 * @param base the second string we want to check
 * @return bool
 * */
bool equals(char *cmd,char *base){
    int i=0,len=strlen(cmd),cnt = 0;
    char *no_space = malloc(sizeof(char)*len);
    for(i=0;i<len;i++)
        if(!isspace(cmd[i]))
            no_space[cnt++] = cmd[i];
    
    int equals = strcmp(no_space,base);
    free(no_space);
    return equals == 0;
}
/**
 * @brief Check if a string starts with another string
 * 
 * This function checks if a string starts with a substring given
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the string we want to check
 * @param base the part we want to check 
 * @return bool
 * */
bool startsWith(char *cmd,char *base){
    int i=0,len=strlen(base);
    for(i=0;i<len;i++)
        if(cmd[i]!=base[i])
            return false;
    return true;
}
/**
 * @brief Check if a string contains a substring
 * 
 * This function checks if a string contains another string
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the string we want to check
 * @param base the substring we search for
 * @return bool
 * */
bool contains(char *cmd,char *base){
    int i=0,counter=0,len=strlen(cmd),j=0,plen=strlen(base);
    for(i=0;i<len - plen;i++){
        counter = 0;
        for(j=0;j<plen;j++)
            if(cmd[i+j]==base[j])
                counter++;
        if(counter == plen)
            return true;
    }
    return false;
}
/**
 * @brief Check if a string has a specific character
 * 
 * This function checks if a string contains a character
 * 
 * @author Michail-Panagiotis Bofos
 * @param cmd the string we want to check
 * @param c the character we search for
 * @return bool
 * */
bool hasA(char *cmd,char c){
    int i=0,len=strlen(cmd);
    for(i=0;i<len;i++){
        if(cmd[i] == c)
            return true;
    }
    return false;
}
