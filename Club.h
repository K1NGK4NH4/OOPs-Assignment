#ifndef CLUB_H
#define CLUB_H

#include <string>
#include <iostream>
#include "Assigment.h"
#include "Vector.h"
#include "Submissions.h"
#include "Student.h"

using namespace std;

class Club {

    int clubId;
    string name;
    string Mail;
    Vector<Assignment*> Assignments; 
    Vector<Student*> Members;        
    Student* Admin;                  

public:
    Club(int id = 0, string n = "", string m = "", Student* a = nullptr)
        : clubId(id), name(n), Mail(m), Admin(a) {}
    
    ~Club() { cout << "Club deleted" << endl; }

    // Getters
    int getClubId() const { return clubId; }
    string getName() const { return name; }
    string getMail() const { return Mail; }
    Vector<Assignment*> getAssignments() const { return Assignments; }
    Vector<Student*> getMembers() const { return Members; }
    Student* getAdmin() const { return Admin; }

    // Setters
    void setName(const string& n) { name = n; }
    void setMail(const string& m) { Mail = m; }
    void setAdmin(Student* a) { Admin = a; }

    // Member management
    void addMember(Student* s) { Members.push_back(s); }

    void removeMember(int studentId) {
        Vector<Student*> temp;
        bool found = false;
        for (int i = 0; i < Members.size(); i++) {
            if (Members[i]->getEnrollment() != studentId) {
                temp.push_back(Members[i]);
            } else {
                found = true;
            }
        }
        Members = temp;
        if (!found)
            cout << "Member with ID " << studentId << " not found." << endl;
    }

    // Assignment management
    void addAssignment(Assignment* a) { Assignments.push_back(a); }

    void removeAssignment(int assignmentId) {
        Vector<Assignment*> temp;
        bool found = false;
        for (int i = 0; i < Assignments.size(); i++) {
            if (Assignments[i]->getAssignmentId() != assignmentId) {
                temp.push_back(Assignments[i]);
            } else {
                found = true;
            }
        }
        Assignments = temp;
        if (!found)
            cout << "Assignment with ID " << assignmentId << " not found." << endl;
    }

    void listAssignments() const {
        if (Assignments.empty()) {
            cout << "No assignments available." << endl;
            return;
        }
        for (int i = 0; i < Assignments.size(); i++) {
            Assignments[i]->details(); // pointer access
            cout << "---------------------------" << endl;
        }
    }

    void listMembers() const {
        if (Members.empty()) {
            cout << "No members in the club." << endl;
            return;
        }
        for (int i = 0; i < Members.size(); i++) {
            // Members[i]->ViewCredentials(); use pointer when Student fixed
            cout << "---------------------------" << endl;
        }
    }

    void display() const {
        cout << "Club ID: " << clubId << endl;
        cout << "Name: " << name << endl;
        cout << "Mail: " << Mail << endl;
        if (Admin)
            cout << "Admin: " << Admin->getName() 
                 << " (ID: " << Admin->getEnrollment() << ")" << endl;
        else
            cout << "Admin: None" << endl;

        cout << "Number of Members: " << Members.size() << endl;
        cout << "Number of Assignments: " << Assignments.size() << endl;
    }
};

#endif
