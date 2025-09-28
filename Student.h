#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Vector.h"

// Forward declarations
class Club;
class Submission;
class Assignment;
class Admin;

using namespace std;

class Student {
protected:
    string password;
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
    Student(string n,int Enrollment, string m, int gradYear, float g ,string pass="0");

    // Methods
    bool login(int Enrollment,string password);
    void accessJoinClub(Club* c);
    void AddClub(Club* c);
    bool leaveClub(Club* c);
    Vector<Club*> ViewClubs() const;

    void submitAssignment(Submission* s);
    Vector<Assignment*> getAssignment(Club* c) const;
    // Getters
    string getName() const;
    int getEnrollment() const;
    string getMail() const;
    int getGraduationYear() const;
    float getCGPA() const;
    virtual ~Student() {}
};



class Admin : public Student {
    Club* club;
    string joiningDate;
public:
    Admin(string n, int e, string m, int gradYear, float g, Club* c, string join,string pass="0");

    // Admin functionalities
    void addMember(Student* s);
    void removeMember(int studentId);

    void addAssignment(Assignment* a);
    void removeAssignment(int assignmentId);

    void setNewAdmin(Admin* newAdmin);
    Club* getClub() const;
    string getJoiningDate() const;
};

#endif
