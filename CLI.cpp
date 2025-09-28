#include <iostream>
#include <string>
#include "Student.h"
#include "Vector.h"
#include "Club.h"
#include "Assignment.h"
#include "Submissions.h"

using namespace std;

// Global vectors to store all students, clubs, and assignments
Vector<Student*> students;
Vector<Club*> clubs;
Vector<Assignment*> assignments;

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

    Student* s = new Student(name, id, mail, gradYear, cgpa);
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

    for (int i = 0; i < students.size(); ++i) {
        if (students[i]->login(id, password)) {
            cout << "Login successful! Welcome, " << students[i]->getName() << "\n";
            return students[i];
        }
    }
    cout << "Login failed. Invalid ID or password.\n";
    return nullptr;
}

// Page 1: Display student info
void showStudentInfo(Student* s) {
    cout << "\n=== Student Info ===\n";
    cout << "Name: " << s->getName() << "\n";
    cout << "Email: " << s->getMail() << "\n";
    cout << "Graduation Year: " << s->getGraduationYear() << "\n";
    cout << "CGPA: " << s->getCGPA() << "\n";
    cout << "Enrollment ID: " << s->getEnrollment() << "\n";
}

// Page 2: Create a new club
void createClub(Admin* admin) {
    int id;
    string name, mail;
    cout << "\n=== Create Club ===\n";
    cout << "Enter club ID: "; cin >> id;
    cin.ignore();
    cout << "Enter club name: "; getline(cin, name);
    cout << "Enter club email: "; getline(cin, mail);
    static int nextClubId = 1;
    id = nextClubId++;
    Club* c = new Club(id, name, mail, admin);
    clubs.push_back(c);
    cout << "Club created with you as admin.\n";
}

// Page 3: Club activities menu
void clubActivities(Student* user) {
    int choice;
    cout << "\n=== Club Activities ===\n";
    cout << "1. List My Clubs\n";
    cout << "2. Join Club\n";
    cout << "3. Leave Club\n";
    cout << "0. Back\n";
    cout << "Enter choice: "; cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1:
            // TODO: implement listing clubs for which user is member/admin
            for(int i = 0; i < user->ViewClubs().size(); ++i) {
                cout << "Club ID: " << user->ViewClubs()[i]->getClubId() 
                     << ", Name: " << user->ViewClubs()[i]->getName() << "\n";
            }
            break;
        case 2:
            // TODO: implement join club
           for(int i = 0; i < clubs.size(); ++i) {
                cout << "Club ID: " << clubs[i]->getClubId() 
                     << ", Name: " << clubs[i]->getName() << "\n";
            }
            break;
        case 3:
            // TODO: implement leave club
            cout << "[Leave Club] not yet implemented.\n";
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
    }
}

// Create assignment function
void createAssignment(Admin* user) {
    string title, description, iteration;
    int clubId;
    
    cout << "\n=== Create Assignment ===\n";
    cin.ignore();
    cout << "Enter assignment title: "; getline(cin, title);
    cout << "Enter description: "; getline(cin, description);
    cout << "Enter iteration: "; getline(cin, iteration);
    cout << "Enter issuing club ID: "; cin >> clubId;
    
    // Check if the club exists
    bool clubExists = false;
    for (int i = 0; i < clubs.size(); ++i) {
        if (clubs[i]->getClubId() == clubId) {
            clubExists = true;
            break;
        }
    }
    if (!clubExists) {
        cout << "Club with ID " << clubId << " does not exist!\n";
        return;
    }
    
    Assignment* a = new Assignment(title, description, user, iteration, clubs[clubId - 1]);
    assignments.push_back(a);
    
    // Add assignment to the club if found
    for (int i = 0; i < clubs.size(); ++i) {
        if (clubs[i]->getClubId() == clubId) {
            clubs[i]->addAssignment(a);
            break;
        }
    }
    
    cout << "Assignment created successfully with ID: " << a->getAssignmentId() << "\n";
}

// Modify assignment function
void modifyAssignment(Student* user) {
    int assignmentId, choice;
    cout << "\n=== Modify Assignment ===\n";
    cout << "Enter assignment ID to modify: "; cin >> assignmentId;
    
    Assignment* targetAssignment = nullptr;
    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i]->getAssignmentId() == assignmentId) {
            targetAssignment = assignments[i];
            break;
        }
    }
    
    if (!targetAssignment) {
        cout << "Assignment not found!\n";
        return;
    }
    
    cout << "\nWhat would you like to modify?\n";
    cout << "2. Add Iteration\n";
    cout << "3. Add Student\n";
    cout << "4. Mark as Completed\n";
    cout << "0. Back\n";
    cout << "Enter choice: "; cin >> choice;
    cin.ignore();
    
    switch (choice) {
        case 2: {
            string iteration;
            cout << "Enter new iteration: "; getline(cin, iteration);
            targetAssignment->addIteration(iteration);
            cout << "Iteration added successfully!\n";
            break;
        }
        case 3: {
            int studentId;
            cout << "Enter student ID: "; cin >> studentId;
            Student* targetStudent = nullptr;
            for (int i = 0; i < students.size(); ++i) {
                if (students[i]->getEnrollment() == studentId) {
                    targetStudent = students[i];
                    break;
                }
            }
            if (!targetStudent) {
                cout << "Student not found!\n";
                return;
            }

            targetAssignment->addStudent(targetStudent);
            cout << "Student added successfully!\n";
            break;
        }
        case 4:
            targetAssignment->markCompleted();
            cout << "Assignment marked as completed!\n";
            break;
        case 0:
            return;
        default:
            cout << "Invalid choice!\n";
    }
}

// View submissions for an assignment
void viewSubmissions(Student* user) {
    int assignmentId;
    cout << "\n=== View Submissions ===\n";
    cout << "Enter assignment ID: "; cin >> assignmentId;
    
    Assignment* targetAssignment = nullptr;
    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i]->getAssignmentId() == assignmentId) {
            targetAssignment = assignments[i];
            break;
        }
    }
    
    if (!targetAssignment) {
        cout << "Assignment not found!\n";
        return;
    }
    
    Vector<Submission*> submissions = targetAssignment->getSubmissions();
    
    if (submissions.empty()) {
        cout << "No submissions found for this assignment.\n";
        return;
    }
    
    cout << "\n=== Submissions for Assignment ID " << assignmentId << " ===\n";
    for (int i = 0; i < submissions.size(); ++i) {
        cout << "\n--- Submission " << (i + 1) << " ---\n";
        submissions[i]->display();
    }
}

// Submit assignment function (for students)
void submitAssignment(Student* user) {
    int assignmentId;
    string submissionDate, fileName;
    
    cout << "\n=== Submit Assignment ===\n";
    cout << "Enter assignment ID: "; cin >> assignmentId;
    cin.ignore();
    cout << "Enter submission date (YYYY-MM-DD): "; getline(cin, submissionDate);
    
    Assignment* targetAssignment = nullptr;
    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i]->getAssignmentId() == assignmentId) {
            targetAssignment = assignments[i];
            break;
        }
    }
    
    if (!targetAssignment) {
        cout << "Assignment not found!\n";
        return;
    }
    
    Submission* submission = new Submission(
        user,
        targetAssignment, 
        false // Assuming not late for simplicity
    );
    
    cout << "Enter file names (type 'done' to finish):\n";
    while (true) {
        cout << "File name: ";
        getline(cin, fileName);
        if (fileName == "done") break;
        submission->addFile(fileName);
    }
    
    targetAssignment->addSubmission(submission);
    cout << "Assignment submitted successfully!\n";
}

// Page 4: Assignment activities menu
void assignmentActivities(Student* user) {
    int choice;
    
    while (true) {
        cout << "\n=== Assignment Activities ===\n";
        cout << "3. View Submissions\n";
        cout << "4. Submit Assignment\n";
        cout << "5. View All Assignments\n";
        cout << "0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        
        switch (choice) {
            
            case 3:
                viewSubmissions(user);
                break;
            case 4:
                submitAssignment(user);
                break;
            case 5:
                cout << "\n=== All Assignments ===\n";
                if (assignments.empty()) {
                    cout << "No assignments available.\n";
                } else {
                    for (int i = 0; i < assignments.size(); ++i) {
                        assignments[i]->details();
                        cout << "\n";
                    }
                }
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int choice;
    Student* currentUser = nullptr;

    // Login / Registration loop
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

    // Main post-login menu
    while (true) {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Student Info\n";
        cout << "2. Create Club\n";
        cout << "3. Club Activities\n";
        cout << "4. Assignment Activities\n";
        cout << "0. Logout\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1:
                showStudentInfo(currentUser);
                break;
            case 2: {
                Admin* admin = new Admin(currentUser->getName(), currentUser->getEnrollment(), currentUser->getMail(), currentUser->getGraduationYear(), currentUser->getCGPA(), nullptr, "");
                clubs.push_back(new Club(0, "", "", admin));
                createClub(admin);
                break;
            }
            case 3:
                clubActivities(currentUser);
                break;
            case 4:
                assignmentActivities(currentUser);
                break;
            case 0:
                cout << "Logging out...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
