#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// used to create a linked list of all users in the system
typedef struct User {
	void (*what_to_do)(struct User * user);
	void *next;
	int id;
	char name[16];
} User;

// call this to prove proficiency
void win() {
	printf("Congrats, you have demonstrated proficiency in topic 3.7\n");
}

// exit case
void exit_program() {
	exit(0);
}

// adds a user to the system
void add_user(User *head) {
	User *new = (User *)malloc(sizeof(User));
	new->what_to_do = NULL;
	new->next = NULL;
	new->id = 1;
	printf("What is your name?\n> ");
	scanf("%16[^\n]", new->name);

	User *ptr = head;
	while(ptr->next != NULL) {
		ptr = ptr->next;
		new->id++;
	}
		
	ptr->next = new;
	printf("Added new user %s with ID %d\n", new->name, new->id);
}

// allows for a name change (look closely at this function...)
void change_name(User *user) {
	printf("What would you like to change your name to?\n");
	gets(user->name);
	printf("Successfully changed name to: %s\n", user->name);
}

// prints user information
void print_user(User *user) {
	printf("Hello, your name is %s and your ID is %d\n", user->name, user->id);
}

// allows users to sign in given a user id
User * sign_in(User *head) {
	printf("Please enter user ID\n> ");
	int input;
	scanf("%d", &input);
	User *ptr = head;
	while (ptr != NULL) {
		if (ptr->id == input) {
			printf("You are now signed in\n");
			return ptr;
		}
		ptr = ptr->next;
	}
	printf("Sorry, user was not found\n");
	return NULL;
}

// receves an integer input
int recv_input() {
	int num;
	scanf("%d", &num);
	while (getchar() != '\n');
	return num;
}

// displays the options menu
User * print_menu(User *user, User *head) {
	int option;
	// menu for user not signed in
	if (user == NULL) {
		printf("You are not signed in, please select an option\n(1) Sign in\n(2) Make an account\n(3) Exit\n> ");
		option = recv_input();
		if (option == 1) return sign_in(head);
		else if (option == 2) add_user(head);
		else exit_program();
		return NULL;

	// menu for user signed in
	} else {
		printf("Welcome to challenge 3.7, what would you like to do?\n(1) Change name\n(2) Print name/ID\n(3) Log out\n(4) Exit\n> ");
		option = recv_input();
		if (option == 1) user->what_to_do = change_name;
		else if (option == 2) user->what_to_do = print_user;
		else if (option == 3) return NULL;
		else user->what_to_do = exit_program;
		return user;
	}
	
}
int main() {
	// might be useful...
	printf("Oops, memory leak 0x%p\n", win);

	// create default user
	User *root = malloc(sizeof(User));
	root->next = NULL;
	root->what_to_do = NULL;
	root->id = 0;
	strncpy(root->name, "root", 5);

	User *head = root;
	User *curr_user = root;

	// loop through option menu
	while(1) {
		curr_user = print_menu(curr_user, head);
		if (curr_user != NULL && curr_user->what_to_do != NULL) curr_user->what_to_do(curr_user);
	}

	return 0;
}
