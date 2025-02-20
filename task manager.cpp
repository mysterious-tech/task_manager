#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

// Structure to represent a Task
struct Task {
    string name;
    int priority;
};

// Class to represent the Task Scheduler
class TaskScheduler {
private:
    Task tasks[MAX_TASKS]; // Fixed-size array to store tasks
    int taskCount; // Number of tasks in the list

public:
    TaskScheduler() : taskCount(0) {} // Constructor initializes task count

    // Function to add a task
    void addTask(const string& name, int priority) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount].name = name;
            tasks[taskCount].priority = priority;
            taskCount++;
            cout << "Task added: " << name << " with priority " << priority << endl;
        } else {
            cout << "Task list is full!" << endl;
        }
    }

    // Function to view all tasks
    void viewTasks() {
        if (taskCount == 0) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "\nCurrent Tasks:\n";
        for (int i = 0; i < taskCount; i++) {
            cout << "Task: " << tasks[i].name << ", Priority: " << tasks[i].priority << endl;
        }
    }

    // Function to remove the highest priority task
    void removeTask() {
        if (taskCount == 0) {
            cout << "No tasks to remove." << endl;
            return;
        }

        // Find the task with the highest priority
        int highestPriorityIndex = 0;
        for (int i = 1; i < taskCount; i++) {
            if (tasks[i].priority > tasks[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }

        // Remove the highest priority task by shifting the array
        cout << "Removed task: " << tasks[highestPriorityIndex].name << " with priority " << tasks[highestPriorityIndex].priority << endl;
        for (int i = highestPriorityIndex; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--; // Reduce the task count
    }
};

// Main function to demonstrate the Task Scheduler
int main() {
    TaskScheduler scheduler;
    int choice;
    string taskName;
    int priority;

    do {
        cout << "\nTask Scheduler Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Highest Priority Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter task name: ";
                getline(cin, taskName);
                cout << "Enter task priority (higher number = higher priority): ";
                cin >> priority;
                scheduler.addTask(taskName, priority);
                break;
            case 2:
                scheduler.viewTasks();
                break;
            case 3:
                scheduler.removeTask();
                break;
            case 4:
                cout << "Exiting the Task Scheduler." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

