#include "library.h"
/**
 * @brief Pwd command
 * 
 * This function prints the current working directory
 * 
 * @author Michail-Panagiotis Bofos
 * @return void
 * */
void printWorkingDirectory(){
    char cwd[1000];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }
}