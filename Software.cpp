#include <iostream>
#include <vector>
#include <string>

class TodoList {
public:
    std::vector<std::string> tasks;

    void addTask(std::string task) {
        tasks.push_back(task);
    }

    void showTasks() {
        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
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

    todo.showTasks();
    return 0;
}

