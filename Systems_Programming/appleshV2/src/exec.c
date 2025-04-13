#include "exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
// Maximum of space delimited tokens in a single command
void run_command(char *input) {
    char *args[MAX_ARGS];
    int i = 0;
    // Tokenize input string into arguments
    char *token = strtok(input, " ");
    // strtok() splits input at " "
    // modifies input buffer in place
    while (token && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    // fills args with tokens, sets end to NULL as execvp() expects null ending
    // Fork a child process
    pid_t pid = fork();
    // child gets copy with different return value from fork()
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
        // execvp() replaces current process image and if fails prints error and exits child
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        // Waits for child to finish with waitpid()
    } else {
        perror("fork failed");
        // Else means failure, so we print error
    }
}

/* Learned:
    strtok(): splits variable at character, essentially tokenizes string based on delimiter
    modification in place: changing contents of memory directly without copy creation (no extra memory allocation)
    execvp(): removes old code and starts next program in same process
    program is just a file on disk, process is a program that is currently running
    waitpid() tells parent when and how child exits, as well as waits until that point.
     */