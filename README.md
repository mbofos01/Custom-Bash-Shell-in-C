/**

@mainpage shell

@author Michail-Panagiotis Bofos

This program is a custom shell based on the utilities of bash shell.

IMPORTANT: The check for the system resources is not implemented
I tried to enable the SIGCHLD signal to handle when a child is
terminated but, because i use the execvp("/bin/bash") command 
each child process was getting a new pid so the handler was called
in the wrong time and not when the process was terminated. If we could 
got a signal when the process ended we could decrease the active counter
and make room for new processes. This check is implemented, but our counter
never gets decreased, so we'll have a deadlock when the counter reaches its limit.

How to run: ./ucysh


**/