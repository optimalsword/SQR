#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct command {
    char user[8];

    void  (*cm)(struct command *);  // function pointer to actual command
} command;

typedef struct team_member {
    char name[8];
    char age;

    struct team_member *next;
} team_member;


void show_team(command *);
void login(command *);
void logout(command *);
void add_member(command *);

#endif