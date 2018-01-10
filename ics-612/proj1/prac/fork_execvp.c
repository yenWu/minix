#define _GNU_SOURCE // execvpe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // fork, exec
#include <stdbool.h> // bool, true, false

#include <sys/types.h> // waitpid
#include <sys/wait.h>

#define MAX_CMD 100

void display_prompt(void) {
    printf("\n$");
}

void readcmd(char cmd[], char *para[]) {
    scanf("%s", cmd); // No callback if just input 'Enter'
}

int main(int argc, char *argv[]) {
	/* Initialization */
    char cmd[MAX_CMD];
    char *paras[50];

    while (true) {
        display_prompt();          /* display prompt */
        readcmd(cmd, paras);

        pid_t chpid;
        int chstatus;
        
        /* Parent code */
        if ((chpid = fork()) > 0) {
            int opt = 0; // WNOHANG, WUNTRACED, WCONTINUED
            waitpid(chpid, &chstatus, opt);
        } else {
            /* Child code */
            // Refer to https://stackoverflow.com/questions/7656549/understanding-requirements-for-execve-and-setting-environment-vars#
            char *args[] = {"sh", "-c", "ls", NULL};
            char *env[] = {"PATH=/usr/bin:/bin", NULL};
            execvpe("/bin/sh", args, env);
        }
    }

	return 0;
}
