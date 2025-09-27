#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "Vector.h"        // Ensure Vector.h is in the same directory
#include "Submissions.h"
using namespace std;

class Assignment {
private:
    int AssignmentId;
    string title;
    string description;
    Vector<string> Givenby;               // Teachers who gave this assignment
    Vector<string> Iterations;
    Vector<int> StudentIds;
    bool completed;
    int issueingClubId;
    Vector<Submission*> Assignment_Submission;

public:
    // Constructor
    Assignment(string t, string d, Vector<string> g, string i, int id);

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
    int getIssuingClubId() const;
    Vector<string> getGivenBy() const;
    Vector<string> getIterations() const;
    Vector<int> getStudentIds() const;
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
