// Main.cpp
#include <iostream>
#include "ToDoList.h"

int main() {
    ToDoList myToDoList;
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Complete\n";
        std::cout << "4. Save Tasks\n";
        std::cout << "5. Load Tasks\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            myToDoList.addTask();
            break;
        case 2:
            myToDoList.viewTasks();
            break;
        case 3: {
            int index;
            std::cout << "Enter task number to mark complete: ";
            std::cin >> index;
            myToDoList.markTaskComplete(index - 1); // Adjust for 0-based index
            break;
        }
        case 4:
            myToDoList.saveTasks("tasks.txt");
            break;
        case 5:
            myToDoList.loadTasks("tasks.txt");
            break;
        case 6:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
