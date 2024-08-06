// 3.9 (U) Describe and demonstrate achieving code execution through a heap buffer overflow 
// (CWE-416) on an object containing function pointers

#include <stdio.h>
#include <stdlib.h>



typedef struct command {
    char buf[64]; // should NOT need more than 64 bytes for a given command

    void  (*cm)();  // function pointer to actual command
} command;


// Prints the available command options
void print_options() {
    printf("=== AVAILABLE COMMANDS ===\n");

}



int main(int argc, char ** argv) {
    printf("=== Welcome to SENTINEL ===\nCurrently logged in as: GUEST\n");

    command c; // command to be executed
    while (1) {
        print_options();


    }

    return 0;
}