#include <unistd.h>

void studentFunction1() {
    // TODO:    Implement a function (which can call other library functions)
    //          to pop a shell and read the contents on `flag.txt` using the shell.  
    char *cmds[2];
    cmds[0] = "/bin/sh";
    cmds[1] = NULL;
    execve(cmds[0], cmds, NULL);
    return;
}


int main () {
    studentFunction1();
    return 0;
}