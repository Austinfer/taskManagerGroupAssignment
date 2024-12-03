#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"

#define MAX_TASKS 100

static Task taskList[MAX_TASKS];
static int taskCount = 0;

int addTaskToList(const char* title, const char* description, int priority) {
    if (taskCount >= MAX_TASKS) {
        return 0; // Task list is full
    }
    strcpy(taskList[taskCount].title, title);
    strcpy(taskList[taskCount].description, description);
    taskList[taskCount].priority = priority;
    taskCount++;
    return 1; // Task added successfully
}

int saveTasks(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        return 0; // Failed to open file
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s|%s|%d\n", taskList[i].title, taskList[i].description, taskList[i].priority);
    }

    fclose(file);
    return 1; // Successfully saved
}

int loadTasks(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 0; // Failed to open file
    }

    taskCount = 0;
    while (fscanf(file, "%49[^|]|%99[^|]|%d\n", taskList[taskCount].title, taskList[taskCount].description, &taskList[taskCount].priority) == 3) {
        taskCount++;
        if (taskCount >= MAX_TASKS) break;
    }

    fclose(file);
    return 1; // Successfully loaded
}

void displayAllTasks() {
    printf("\n--- All Tasks ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n   Description: %s\n   Priority: %d\n",
            i + 1, taskList[i].title, taskList[i].description, taskList[i].priority);
    }
}
