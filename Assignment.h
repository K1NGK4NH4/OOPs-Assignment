#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "Vector.h"        // Ensure Vector.h is in the same directory
#include "Submissions.h"
#include "Student.h"
using namespace std;

class Assignment {
private:
    int AssignmentId;
    string title;
    string description;
    Admin* Givenby;               
    Vector<string> Iterations; 
    Vector<Student*> Students;
    bool completed;
    Club* issueingClub;
    Vector<Submission*> Assignment_Submission;

public:
    // Constructor
    Assignment(string t, string d, Admin* g, string i, Club* c);

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
    string getDescription() const;
    int getIssueingClub() const;
    Vector<string> getGivenBy() const;
    Vector<string> getIterations() const;
    Vector<int> getStudents() const;
    Vector<Submission*> getSubmissions() const;

    // Display details
    void details() const;

    // Modifiers
    void addTeacher(const string& teacher);
    void addIteration(const string& iteration);
    void addStudent(int studentId);
    void addSubmission(Submission* submission);
};

#endif
