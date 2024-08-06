#include "commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void show_team(command * cmd) {
    printf("%s showing team members\n", cmd->user);

    team_member * cur = cmd->head;
    while (cur != NULL) {
        // print the team member's info
        printf("%s    %d\n", cur->name, cur->age);
        cur = cur->next;
    }
}


void login(command * cmd) {
    printf("LOGGED IN AS %s\n", cmd->user);
    printf("ERROR, no privileges to run as root\n");
    printf("*BEEP BOOP* printf located at %p *WRRRR*\n", printf);
}


void logout(command * cmd) {
    printf("Logging out as: %s\n", cmd->user);
    free(cmd);
    printf("LOGGED OUT\n\n\n");
}


void add_member(command * cmd) {
    team_member * new_user;


    char name[8];
    printf("Enter Name: ");
    if (!fgets(name, 8, stdin)) {
        exit(1);
    }

    char age[8];
    puts("\n");
    printf("Enter Age: ");
    if (!fgets(age, 8, stdin)) {
        exit(1);
    }

    new_user = (team_member *)malloc(sizeof(team_member));
    memcpy(new_user->name, name, 8);
    sscanf(age, "%d", &new_user->age);


    if (cmd->head == NULL) {
        cmd->head = new_user;
    } else {
        // need to traverse the list to find end
        team_member * prev;
        team_member * cur = cmd->head;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
        }
        // prev should point to last node
        prev->next = new_user;
    }

    new_user->next = NULL;

    printf("USER CREATED\n");
}