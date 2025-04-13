#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "exec.h"
// To call run_command()
#define MAX_INPUT 1024
// Buffer size for reading in bytes

int main() {
    char input[MAX_INPUT];
    // Buffer for input
    while (1) {
        printf("applesh> ");
        fflush(stdout);
        // infinite Read-Evaluate-Print-Execute (REPL) loop
        // fflush(stdout) prints immediately
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }
        // fgets reads line of input, if it fails with an error we exit the loop
        input[strcspn(input, "\n")] = 0;
        // strcspn returns index of newline, set it equal to 0 to remove it
        if (strlen(input) == 0) {
            continue;
        }
        // if it's empty then we skip it
        run_command(input);
        // calls the run command function which parses and runs command
    }
    // if exited
    printf("\nExited using Ctrl+D\n");
    return 0;
}
/* Learned:
    fflush(stdout): prints immediately
    fgets: reads a line of input
    strcspn: returns index of newline
     */
