#ifndef LIBRARY_H
#define LIBRARY_H
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE
#define _GNU_SOURCE

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include "queue.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <setjmp.h>
#include <time.h>

#define MAX_CMD 100
#define MAX_VAR 50
#define MAX_VALUE 30
#define MAX_SOURCES 10
#define WRITE 1
#define READ 0

extern bool running;
extern Queue *queue;
extern int active;
extern int used;

int isBuilt(char *cmd);
int findCommas(char *str);
bool hasPipe(char *cmd);
bool hasA(char *cmd,char c);
bool startsWith(char *cmd,char *base);
bool contains(char *cmd,char *base);
bool equals(char *cmd,char *base);
bool run(char *cmd);
void changeDirectory(char *dir);
void printWorkingDirectory();
void printHistory(Queue *queue);
void runPipe(char *argv);
void breakPipe(char *cmd,char *cmd1);
void execMe(char *cmd);
void killProcess(int process);
void readMe(char *cmd);
void addSpace(char *cmd,char *cmd1);
void printSingals();
void echo(char *cmd);
void seeVariables();
void export(char *cmd);
void sigchld_handler (int signum);
void breakRedirect(char *cmd,char *command,char *file_name);
#endif