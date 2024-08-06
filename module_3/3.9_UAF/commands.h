#ifndef COMMANDS_H
#define COMMANDS_H



typedef struct team_member {
    char name[8];
    int age;

    struct team_member *next;
} team_member;


typedef struct command {
    char user[8];

    void  (*cm)(struct command *);  // function pointer to actual command
    team_member * head; // list of team members
} command;

void show_team(command *);
void login(command *);
void logout(command *);
void add_member(command *);

#endif