#include "library.h"
/**
 * @brief Change directory command
 * 
 * This function changes the current directory we use
 * 
 * @author Michail-Panagiotis Bofos
 * @param dir the directory we want to change to
 * @return void
 * */
void changeDirectory(char *dir){
    chdir(dir);
    char cwd[1000];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
        setenv("PWD",cwd,1);
   } else {
       perror("getcwd() error");
   }
    return;
}