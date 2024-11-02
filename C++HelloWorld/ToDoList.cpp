// ToDoList.cpp
#include "ToDoList.h"
#include <iostream>
#include <fstream>

void ToDoList::addTask() {
    std::string description;
    int priorityInput;
    int year, month, day;

    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, description);

    std::cout << "Enter priority (0 = Low, 1 = Medium, 2 = High): ";
    std::cin >> priorityInput;
    Priority priority = static_cast<Priority>(priorityInput);

    std::cout << "Enter due date (YYYY MM DD): ";
    std::cin >> year >> month >> day;

    // Set due date
    std::tm dueDateInfo = {};
    dueDateInfo.tm_year = year - 1900;
    dueDateInfo.tm_mon = month - 1;
    dueDateInfo.tm_mday = day;
    std::time_t dueDate = std::mktime(&dueDateInfo);

    Task newTask(description, priority, dueDate);
    tasks.push_back(newTask);

    std::cout << "Task added successfully!\n";
}

void ToDoList::viewTasks() const {
    for (const auto& task : tasks) {
        task.displayTask();
        std::cout << "-----------------------\n";
    }
}

void ToDoList::markTaskComplete(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markComplete();
        std::cout << "Task marked as complete.\n";
    }
    else {
        std::cout << "Invalid task number.\n";
    }
}

void ToDoList::saveTasks(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task.description << "\n";
        file << task.priority << "\n";
        file << task.isCompleted << "\n";
        file << task.dueDate << "\n";
    }
    std::cout << "Tasks saved successfully.\n";
}

void ToDoList::loadTasks(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for reading.\n";
        return;
    }

    tasks.clear();
    std::string description;
    int priorityInput;
    bool isCompleted;
    std::time_t dueDate;

    while (std::getline(file, description)) {
        file >> priorityInput;
        file >> isCompleted;
        file >> dueDate;
        file.ignore();

        Task task(description, static_cast<Priority>(priorityInput), dueDate);
        task.isCompleted = isCompleted;
        tasks.push_back(task);
    }
    std::cout << "Tasks loaded successfully.\n";
}
