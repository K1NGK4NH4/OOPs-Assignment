#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Vector.h"
#include "Club.h"
#include "Submissions.h"
#include "Assignment.h"
using namespace std;

class Student {
protected:
    string name;
    int Enrollment;
    string mail;
    int GraduationYear;
    float cgpa;
    Vector<Club*> Clubs;
    Vector<Submission*> Assignment_Submission;
    Vector<Club*> clubRequest;

public:
    // Constructors
    Student();
    Student(string n,int Enrollment, string m, int gradYear, float g);

    // Methods

    void accessJoinClub(Club* c);
    bool leaveClub(Club* c);
    Vector<Club*> ViewClubs() const;

    void submitAssignment(Submission* s);
    Vector<Assignment*> getAssignment(Club* c) const;

    // Getters
    string getName() const;
    int getEnrollment() const;
    int getGraduationYear() const;
    float getCGPA() const;
};



class Admin : public Student {
    Club* club;
    string joiningDate;
public:
    Admin(string n, int e, string m, int gradYear, float g, Club* c, string join);


    // Admin functionalities
    void addMember(Student* s);
    void removeMember(int studentId);

    void addAssignment(Assignment* a);
    void removeAssignment(int assignmentId);

    void setNewAdmin(Student* newAdmin);
};

#endif
