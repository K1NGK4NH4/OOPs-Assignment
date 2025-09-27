#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>
#include <iostream>
#include "Vector.h"
using namespace std;

class Submission {
private:
    int studentID;                 // ID of the student who submitted
    string studentName;            // Name of student
    int assignmentID;              // ID of the assignment
    string submissionDate;         // Date of submission
    Vector<string> submittedFiles; // List of submitted files
    string review;                 // Review comments
    int score;                     // Score / grade

public:
    // Constructor
    Submission(int id = 0, string name = "", int aid = 0, string date = "");

    // Getters
    int getStudentID() const;
    string getStudentName() const;
    int getAssignmentID() const;
    string getSubmissionDate() const;
    Vector<string> getSubmittedFiles() const;
    string getReview() const;
    double getScore() const;

    // Setters
    void setReview(const string& r);
    void setScore(double s);

    void addFile(const string& file);

    // Display submission info
    void display() const;
};

#endif
