#include <iostream>
#include <string>
#include "Student.h"
#include "Vector.h"

using namespace std;

// Global vector to store all students
Vector<Student*> students;

// Function to register a new student
Student* registerStudent() {
    string name, mail, password;
    int gradYear, id;
    float cgpa;

    cout << "=== Student Registration ===\n";
    cin.ignore();
    cout << "Enter name: "; getline(cin, name);
    cout << "Enter mail: "; getline(cin, mail);
    cout << "Enter graduation year: "; cin >> gradYear;
    cout << "Enter CGPA: "; cin >> cgpa;
    cout << "Enter enrollment ID: "; cin >> id;
    cin.ignore();
    cout << "Set password: "; getline(cin, password);

    Student* s = new Student(name, mail, gradYear, cgpa, id, password);
    students.push_back(s);
    
    cout << "Registration successful!\n";
    return s;
}

// Function to login a student
Student* loginStudent() {
    int id;
    string password;

    cout << "=== Student Login ===\n";
    cout << "Enter enrollment ID: "; cin >> id;
    cin.ignore();
    cout << "Enter password: "; getline(cin, password);

    for (int i = 0; i < students.size(); i++) {
        if (students[i]->login(id, password)) {
            cout << "Login successful! Welcome, " << students[i]->getName() << "\n";
            return students[i];
        }
    }
    cout << "Login failed. Invalid ID or password.\n";
    return nullptr;
}

// Main login/registration CLI
int main() {
    int choice;
    Student* currentUser = nullptr;

    while (!currentUser) {
        cout << "\n===== Welcome to Student Portal =====\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "0. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1:
                currentUser = loginStudent();
                break;
            case 2:
                currentUser = registerStudent();
                break;
            case 0:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    // After successful login
    cout << "\nWelcome, " << currentUser->getName() << "! You can now access the system.\n";

    // TODO: Add further CLI for clubs, assignments, etc.

    
    return 0;
}
