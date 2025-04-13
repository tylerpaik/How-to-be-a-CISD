#ifndef APPLESH_EXEC_H
#define APPLESH_EXEC_H
// header guard to prevent multiple versions of file

void run_command(char *input);

#endif

/* Learned:
    Header functions help with abstraction/encapsulation to protect code from being tied to how the function works
    and can help make code easier to read. Additionally compilers can work on separate .c files indepenently using the .h file
    main.c can see that run_command exists but nothing else, and trusts that when it calls it it will work.
    exec.c has the definition of run_command but is private, and exec.h is the public view of exec.c
     */