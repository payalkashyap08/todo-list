#include <iostream>
#include <string>
#include <iomanip> // for setw
using namespace std;

// Node for singly linked list
struct Task {
    string description;
    bool completed;
    Task* next;

    Task(string desc) {
        description = desc;
        completed = false;
        next = NULL;
    }
};

Task* head = NULL;

// Function to add a task
void addTask(string desc) {
    Task* newTask = new Task(desc);
    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }
}

// Function to display tasks
void displayTasks() {
    if (head == NULL) {
        cout << "\nNo tasks found.\n";
        return;
    }

    cout << "\n---------------------------------------------\n";
    cout << left << setw(6) << "No." << setw(40) << "Task Description" << "Status" << endl;
    cout << "---------------------------------------------\n";

    Task* temp = head;
    int i = 1;
    while (temp != NULL) {
        cout << left << setw(6) << i << setw(40) << temp->description;
        cout << (temp->completed ? "Completed" : "Pending") << endl;
        temp = temp->next;
        i++;
    }
    cout << "---------------------------------------------\n";
}

// Function to mark task completed
void markCompleted(int index) {
    Task* temp = head;
    int i = 1;

    while (temp != NULL) {
        if (i == index) {
            temp->completed = true;
            cout << "Task marked as completed.\n";
            return;
        }
        temp = temp->next;
        i++;
    }

    cout << "Invalid task number.\n";
}

// Function to delete completed tasks
void deleteCompleted() {
    Task* temp = head;
    Task* prev = NULL;

    while (temp != NULL) {
        if (temp->completed) {
            if (prev != NULL)
                prev->next = temp->next;
            else
                head = temp->next;

            Task* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Completed tasks deleted.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n========= TO-DO LIST MENU =========\n";
        cout << "1. Add New Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Completed Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        if (choice == 1) {
            string desc;
            cout << "Enter task description: ";
            getline(cin, desc);
            addTask(desc);
        } else if (choice == 2) {
            displayTasks();
        } else if (choice == 3) {
            int num;
            cout << "Enter task number to mark completed: ";
            cin >> num;
            markCompleted(num);
        } else if (choice == 4) {
            deleteCompleted();
        } else if (choice == 5) {
            cout << "Exiting To-Do List App. Goodbye!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}