// Task.h
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <ctime>

enum Priority { LOW, MEDIUM, HIGH };

class Task {
public:
    std::string description;
    Priority priority;
    bool isCompleted;
    std::time_t dueDate;

    Task(const std::string& desc, Priority prio, std::time_t dueDate)
        : description(desc), priority(prio), dueDate(dueDate), isCompleted(false) {}

    void markComplete() {
        isCompleted = true;
    }

    void displayTask() const {
        char buffer[26]; // Buffer to store the formatted date
        ctime_s(buffer, sizeof(buffer), &dueDate);
        std::cout << "Task: " << description << "\n";
        std::cout << "Priority: " << (priority == HIGH ? "High" : priority == MEDIUM ? "Medium" : "Low") << "\n";
        std::cout << "Due Date: " << buffer;
        std::cout << "Status: " << (isCompleted ? "Completed" : "Incomplete") << "\n";
    }
};

#endif // TASK_H
