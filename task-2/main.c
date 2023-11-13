#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct active_2 {
    bool flag;
};

union active_1 {
    struct active_2 a2;
} a1;

void register_user(char *user_name, char *email, char *password, bool active_status) {
    a1.a2.flag = active_status;
}

int login_user(char *user_name_or_email, char *password) {
    return 1;
}

int main() {
    char user_name[100];
    char email[100];
    char password[100];
    char active_status_str[10];
    int choice;

    do {
        printf("What do you need?\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Register\nPlease Enter your Data:\n");

                printf("User Name: ");
                scanf("%s", user_name);

                printf("E-mail: ");
                scanf("%s", email);

                printf("Password: ");
                scanf("%s", password);

                // Get active status from the user
                printf("Active (true/false): ");
                scanf("%s", active_status_str);

                bool active_status;
                if (strcmp(active_status_str, "true") == 0 || strcmp(active_status_str, "1") == 0) {
                    active_status = true;
                } else {
                    active_status = false;
                }

                register_user(user_name, email, password, active_status);
                break;

            case 2:
                printf("\nLogin\n");
                char user_name_or_email[100];
                char password_login[100];

                printf("User Name or E-mail: ");
                scanf("%s", user_name_or_email);

                printf("Password: ");
                scanf("%s", password_login);

                int login_successful = login_user(user_name_or_email, password_login);

                if (a1.a2.flag) {
                    if (login_successful) {
                        printf("User is active and login successful!\n");
                    } else {
                        printf("User is active, but invalid user name or email, or incorrect password.\n");
                    }
                } else {
                    printf("User is inactive. Login failed.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
