#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin() : Student("", 0, "",0,0.0,"","") {}
    //Constructor when you pass the value
Admin::Admin(string n,int e, string m, int gradYear, float g,Club* c,string join)
        : Student(n,e,m,gradYear,g),club(c),joiningDate(join) {}

// Add member
bool Admin::addMember(Student* s) {
    
    club->addMember(s);
    cout << s->getName() << " added to club " << club->getName() << endl;
}

// Remove member
void Admin::removeMember(int studentId) {
   club->removeMember(studentId);
}

// Add assignment
void Admin::addAssignment( Assignment* a) {
    club->addAssignment(a);
}

// Remove assignment
void Admin::removeAssignment(int assignmentId) {
    club->removeAssignment(assignmentId);
}

// Set a new admin
void Admin::setNewAdmin(Student* newAdmin) {
    club->setAdmin(newAdmin);
}
