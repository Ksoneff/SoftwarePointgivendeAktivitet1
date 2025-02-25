#include <iostream>
#include <vector>
#include <string>

class TodoList {
public:
    std::vector<std::pair<std::string, bool>> tasks; // Pair of task + completion status

    void addTask(std::string task) {
        tasks.push_back({task, false}); // Default: Not completed
    }

    void markComplete(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].second = true;
            std::cout << "Task " << index << " marked as complete!\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void showtasks() {
        std::cout << "\nto-do list Visualization:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". [" 
                      << (tasks[i].second ? "X" : " ") << "] " 
                      << tasks[i].first << std::endl;
        }
    }
};

int main() {
    TodoList todo;
    std::string task;
    
    std::cout << "Enter tasks (type 'exit' to stop):\n";
    while (true) {
        std::getline(std::cin, task);
        if (task == "exit") break;
        todo.addTask(task);
    }

    while (true) {
        todo.showTasks();
        std::cout << "Enter task number to mark as complete (or 'exit' to finish): ";
        std::getline(std::cin, task);

        if (task == "exit") break;
        
        int taskNumber = std::stoi(task);
        todo.markComplete(taskNumber);
    }

    std::cout << "\nFinal To-Do List:\n";
    todo.showTasks();
    return 0;
}


