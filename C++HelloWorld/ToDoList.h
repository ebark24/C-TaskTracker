// ToDoList.h
#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include "Task.h"

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask();
    void viewTasks() const;
    void markTaskComplete(int index);
    void saveTasks(const std::string& filename) const;
    void loadTasks(const std::string& filename);
};

#endif // TODOLIST_H


