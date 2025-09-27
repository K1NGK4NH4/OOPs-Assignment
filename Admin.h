#ifndef ADMIN_H
#define ADMIN_H

#include "Club.h"
#include "Student.h"
#include "Assignment.h"
using namespace std;

class Admin : public Student {
    Club* club;
    string joiningDate;
public:
    Admin();
    Admin(string n,int Enrollment, string m, int gradYear, float g,Club* c,string joining);

    // Admin functionalities
    bool addMember( Student* s);
    void removeMember(int studentId);

    void addAssignment(Assignment* a);
    void removeAssignment(int assignmentId);

    void setNewAdmin(Student* newAdmin);
};

#endif
