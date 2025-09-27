#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Club.h"
#include "Student.h"
#include "Assignment.h"
using namespace std;

class Admin : public Person {
public:
    Admin(string n, int a, string i);

    // Admin functionalities
    void addMember(Club& club, Student* s);
    void removeMember(Club& club, Student* s);

    void addAssignment(Club& club, Assignment* a);
    void removeAssignment(Club& club, Assignment* a);

    void setNewAdmin(Club& club, Student* newAdmin);
};

#endif
