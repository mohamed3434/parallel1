#include <stdio.h>
#include <string.h>

// Maximum number of users
#define MAX_USERS 10

// User structure
struct User {
    char username[50];
    char password[50];
};

// User database
struct User users[MAX_USERS];
int userCount = 0;

// Function to register a new user
void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter a username: ");
        scanf("%s", users[userCount].username);
        printf("Enter a password: ");
        scanf("%s", users[userCount].password);
        userCount++;
        printf("Registration successful!\n");
    } else {
        printf("User database is full. Cannot register more users.\n");
    }
}

// Function to login a user
void loginUser() {
    char username[50];
    char password[50];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    int i;
    for (i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful! Welcome, %s\n", username);
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Register\n2. Login\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}
