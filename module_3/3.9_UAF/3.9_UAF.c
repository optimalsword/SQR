// 3.9 (U) Describe and demonstrate achieving code execution through a heap buffer overflow 
// (CWE-416) on an object containing function pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"


#define BUFSIZE 64


// Prints the available command options
void print_options() {
    printf("=== AVAILABLE COMMANDS ===\n");
    printf("s: SHOW TEAM MEMBERS\n");
    printf("a: ADD TEAM MEMBER\n");
    printf("L: Login\n");
    printf("e: Logout\n");

}



void process_command(char * cmd, command* c) {
    char choice;
    sscanf(cmd, "%c", &choice);

    if (choice == 'L') {
        c->cm = login;
    } else if (choice == 'e') {
        c->cm = logout;
    } else if (choice == 'a') {
        c->cm = add_member;
    }

    // if the choice is invalid, then just redo the last command
    
}



int main() {
    command * c = (command *)malloc(sizeof(command)); // command to be executed
    memset(c->user, 0, 8);
    char tmp[8] = "T1Lead ";
    memcpy(c->user, tmp, 8);

    char cmd[8];

    while (1) {
        fflush(stdin);
        printf("=== Welcome to SENTINEL ===\nCurrently logged in as: %s\n\n\n", c->user);
        print_options();

        // get user input
        printf("Please choose an option: ");
        if (!fgets(cmd, 8, stdin)) {
            printf("ERROR READING INPUT\n");
            break;
        }
        //printf(&cmd);

        process_command(cmd, c);
        
        // now execute the command
        c->cm(c);


    }

    return 0;
}