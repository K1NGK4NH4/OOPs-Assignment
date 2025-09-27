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

public:
    // Constructors
    Student();
    Student(string n,int Enrollment, string m, int gradYear, float g);

    // Methods
    void AddCredentials();
    void ViewCredentials() const;

    bool requestJoinClub(Club* c);
    bool leaveClub(Club* c);
    Vector<Club*> ViewClubs() const;

    void submitAssignment(Assignment* a, bool late);
    void getAssignment(Club* c) const;

    // Getters
    string getName() const;
    int getEnrollment() const;
    int getGraduationYear() const;
    float getCGPA() const;
};

#endif
