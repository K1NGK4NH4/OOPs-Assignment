#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>
#include <iostream>
#include "Vector.h"

// Forward declarations
class Student;
class Assignment;

using namespace std;

class Submission {
private:
    Student* student;          // Pointer to the student who made the submission
    Assignment* assignment;    // Pointer to the assignment being submitted
    bool late;                         // Whether the submission is late
    Vector<string> submittedFiles; // List of submitted files with namd like dd-mm-yy_iteration_filename
    string review;                 // Review comments
    double score;                     // Score / grade

public:
    // Constructor
    Submission(Student* s, Assignment* a, bool isLate);
    
    // Getters
    Student* getStudent() const;
    Assignment* getAssignment() const;
    bool isLate() const { return late; }
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
