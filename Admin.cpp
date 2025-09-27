#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string n, int a, string i) 
    : Student(n, a, i) {}

// Add member
void Admin::addMember(Club& club, Student* s) {
    club.getMembers().push_back(s);
    cout << s->getName() << " added to club " << club.getName() << endl;
}

// Remove member
void Admin::removeMember(Club& club, Student* s) {
    Vector<Student*> temp;
    for (int i = 0; i < club.getMembers().size(); i++) {
        if (club.getMembers()[i] != s)
            temp.push_back(club.getMembers()[i]);
    }
    club.getMembers() = temp;
    cout << s->getName() << " removed from club " << club.getName() << endl;
}

// Add assignment
void Admin::addAssignment(Club& club, Assignment* a) {
    club.getAssignments().push_back(a);
    cout << "Assignment \"" << a->getTitle() << "\" added to club " << club.getName() << endl;
}

// Remove assignment
void Admin::removeAssignment(Club& club, Assignment* a) {
    Vector<Assignment*> temp;
    for (int i = 0; i < club.getAssignments().size(); i++) {
        if (club.getAssignments()[i] != a)
            temp.push_back(club.getAssignments()[i]);
    }
    club.getAssignments() = temp;
    cout << "Assignment \"" << a->getTitle() << "\" removed from club " << club.getName() << endl;
}

// Set a new admin
void Admin::setNewAdmin(Club& club, Student* newAdmin) {
    club.setAdmin(newAdmin);
    cout << "New admin set for club " << club.getName() 
         << ": " << newAdmin->getName() << endl;
}
