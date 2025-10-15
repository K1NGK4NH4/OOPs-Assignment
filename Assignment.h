#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "Vector.h"

// Forward declarations
class Student;
class Admin;
class Club;
class Submission;

using namespace std;

class Assignment {
private:
    int AssignmentId;
    string title;
    string description;
    Admin* Givenby;               
    Vector<Student*> Students;
    bool completed;
    Club* issueingClub;
    string finalDate;
    Vector<Submission*> Assignment_Submission;

public:
    // Constructor
    Assignment(string t, string d, Admin* g, Club* c, string finalDate = "");

    // Copy constructor (shallow copy of submissions)
    Assignment(const Assignment& other);

    // Assignment operator (shallow copy of submissions)
    Assignment& operator=(const Assignment& other);

    // Destructor
    ~Assignment();

    // Getters
    bool isCompleted() const;
    bool markCompleted();
    int getAssignmentId() const;
    string getTitle() const;
    string getFinalDate() const;
    string getDescription() const;
    Club* getIssueingClub() const;
    Admin* getGivenBy() const;
    Vector<Student*> getStudents() const;
    Vector<Submission*> getSubmissions() const;

    // Display details
    void details() const;

    // Modifiers
    void setFinalDate(const string& date) {}
    void addStudent(Student* student);
    void setTitle(const string& t) { }
    void setDescription(const string& d) {}
    void addSubmission(Submission* submission);
    void removeStudent(int studentId);
};

#endif
