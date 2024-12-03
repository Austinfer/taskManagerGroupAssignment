#ifndef TASK_H
#define TASK_H

typedef struct Task {
    char title[50];
    char description[100];
    int priority;
} Task;

int addTaskToList(const char* title, const char* description, int priority);
int saveTasks(const char* filename);
int loadTasks(const char* filename);
void displayAllTasks();

#endif // TASK_H
