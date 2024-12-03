#include <stdio.h>
#include "ui.h"

int main() {
    int choice;
    loadTasksFromFile(); // Load saved tasks at startup

    do {
        displayMenu();
        choice = getUserChoice();

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            displayAllTasks();
            break;
        case 3:
            saveTasksToFile();
            break;
        case 4:
            loadTasksFromFile();
            break;
        case 5:
            printf("Exiting Task Manager. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
