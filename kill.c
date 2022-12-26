#include "library.h"
/**
 * @brief Kill command
 * 
 * This function kills a process
 * 
 * @author Michail-Panagiotis Bofos
 * @param process the process id of the process we want to terminate
 * @return void
 * */
void killProcess(int process){
    kill(process, SIGTERM );
}
/**
 * @brief Print all signals
 * 
 * This function prints all the available signals
 * 
 * @author Michail-Panagiotis Bofos
 * @return void
 * */
void printSingals(){
    printf("SIGHUP	\t1	Hangup (POSIX)\nSIGINT	\t2	Terminal interrupt (ANSI)\n");
    printf("SIGQUIT	\t3	Terminal quit (POSIX)\nSIGILL	\t4	Illegal instruction (ANSI)\n");
    printf("SIGTRAP	\t5	Trace trap (POSIX)\nSIGIOT	\t6	IOT Trap (4.2 BSD)\n");
    printf("SIGBUS	\t7	BUS error (4.2 BSD)\nSIGFPE	\t8	Floating point exception (ANSI)\n");
    printf("SIGKILL	\t9	Kill(can't be caught or ignored) (POSIX)\n");
    printf("SIGUSR1	\t10	User defined signal 1 (POSIX)\nSIGSEGV	\t11	Invalid memory segment access (ANSI)\n");
    printf("SIGUSR2	\t12	User defined signal 2 (POSIX)\nSIGPIPE	\t13	Write on a pipe with no reader, Broken pipe (POSIX)\n");
    printf("SIGALRM	\t14	Alarm clock (POSIX)\nSIGTERM	\t15	Termination (ANSI)\nSIGSTKFLT \t16	Stack fault\n");
    printf("SIGCHLD	\t17	Child process has stopped or exited, changed (POSIX)\n");
    printf("SIGCONTv \t18	Continue executing, if stopped (POSIX)\nSIGSTOP	\t19	Stop executing(cant be caught or ignored) (POSIX)\n");
    printf("SIGTSTP	\t20	Terminal stop signal (POSIX)\nSIGTTIN	\t21	Background process trying to read, from TTY (POSIX)\n");
    printf("SIGTTOU	\t22	Background process trying to write, to TTY (POSIX)\nSIGURG	\t23	Urgent condition on socket (4.2 BSD)\n");
    printf("SIGXCPU	\t24	CPU limit exceeded (4.2 BSD)\nSIGXFSZ	\t25	File size limit exceeded (4.2 BSD)\n");
    printf("SIGVTALRM \t26	Virtual alarm clock (4.2 BSD)\nSIGPROF	\t27	Profiling alarm clock (4.2 BSD)\n");
    printf("SIGWINCH \t28	Window size change (4.3 BSD, Sun)\nSIGIO	\t29	I/O now possible (4.2 BSD)\n");
    printf("SIGPWR	\t30	Power failure restart (System V)\n");
}