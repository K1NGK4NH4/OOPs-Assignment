#ifndef CLUB_H
#define CLUB_H

#include <string>
#include <iostream>
#include "Vector.h"

// Forward declarations
class Student;
class Admin;
class Assignment;

using namespace std;

class Club {
private:
    int clubId;
    string name;
    string mail;
    Vector<Assignment*> assignments;
    Vector<Student*> members;
    Admin* admin;

public:
    // Constructor & Destructor
    Club(int id = 0, const string& n = "", const string& m = "", Admin* a = nullptr);
    ~Club();

    // Getters
    int getClubId() const;
    string getName() const;
    string getMail() const;
    Vector<Assignment*> getAssignments() const;
    Vector<Student*> getMembers() const;
    Admin* getAdmin() const;

    // Setters
    void setName(const string& n);
    void setMail(const string& m);
    void setAdmin(Admin* a);

    // Member management
    void addMember(Student* s);
    void removeMember(int studentId);

    // Assignment management
    void addAssignment(Assignment* a);
    void removeAssignment(int assignmentId);

    // Listing
    void listAssignments() const;
    void listMembers() const;

    // Display club info
    void display() const;
};

#endif
// --- End of code ---