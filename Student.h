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
    string mail;
    int Enrollment;
    int GraduationYear;
    float cgpa;
    Vector<Club*> Clubs;
    Vector<Submission*> Assignment_Submission;
    Vector<Club*> clubRequest;

public:
    // Constructors
    Student();
    Student(string n,int Enrollment, string m, int gradYear, float g ,string pass="0");
    Student(Student* other);
    // Methods
    bool login(int Enrollment,string password);
    void addClubRequest(Club* c);
    void removeClubRequest(Club* c);
    void AddClub(Club* c);
    bool leaveClub(Club* c);
    Vector<Club*> ViewClubs(bool display=true) const;

    void submitAssignment(Submission* s);
    //setters
    void setName(const string& n) { name = n; }
    void setMail(const string& m) { mail = m; }
    void setGraduationYear(int year) { GraduationYear = year; }
    void setCGPA(float g) { cgpa = g; }

    // Getters
    string getName() const;
    int getEnrollment() const;
    string getMail() const;
    int getGraduationYear() const;
    float getCGPA() const;
    Vector<Submission*> getSubmissions() const { return Assignment_Submission; }
    
    Vector<Club*> getClubRequest() const {
        if(clubRequest.empty()) return Vector<Club*>(); ;
        return clubRequest;
    }


    virtual ~Student() {}

};



class Admin  {
    Club* club;
    Student* student;
    string joiningDate;
    Vector<string> notifications; // Notifications for Admin
public:
    Admin(Student* s ,string join );


    // Admin functionalities
    void addMember(Student* s);
    void removeMember(int studentId);

    void addAssignment(Assignment* a);
    void removeAssignment(int assignmentId);

    void setNewAdmin(Admin* newAdmin);
    void setClub(Club* c);
    Club* getClub() const;
    string getJoiningDate() const;
    Student* getStudent() const { return student; }

    void setNotifications(const string& note) ;
    void removeNotification(const string& note);
    void removeallnotifications();
    Vector<string> getNotifications() const;
};



#endif
