#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ui.h"
#include "task.h"

void displayMenu() {
    printf("\n--- Task Manager Menu ---\n");
    printf("1. Add New Task\n");
    printf("2. Display All Tasks\n");
    printf("3. Save Tasks to File\n");
    printf("4. Load Tasks from File\n");
    printf("5. Exit\n");
}

int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add tasks
void addTask() {
    char title[50];
    char description[100];
    int priority;

    printf("Enter task title: ");
    scanf(" %[^\n]", title);
    printf("Enter task description: ");
    scanf(" %[^\n]", description);
    printf("Enter task priority (1-5): ");
    scanf("%d", &priority);

    if (addTaskToList(title, description, priority)) {
        printf("Task added successfully!\n");
    }
    else {
        printf("Failed to add task. Task list might be full.\n");
    }
}

void saveTasksToFile() {
    if (saveTasks("tasks.txt")) {
        printf("Tasks saved successfully to tasks.txt.\n");
    }
    else {
        printf("Failed to save tasks.\n");
    }
}

void loadTasksFromFile() {
    if (loadTasks("tasks.txt")) {
        printf("Tasks loaded successfully from tasks.txt.\n");
    }
    else {
        printf("Failed to load tasks.\n");
    }
}
