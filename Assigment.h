#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "Vector.h" // Ensure Vector.h is in the same directory
#include "Submissions.h"
using namespace std;

class Assignment {
    int AssignmentId;
    string description;
    Vector<string> Givenby; // Teachers who gave this assignment
    Vector<string> Iterations;
    Vector<int> StudentIds;
    bool completed;
    int issueingClubId;
    Vector<Submission*> Assignment_Submission; // Use pointers
    string title;

public:
    Assignment(string t, string d, Vector<string> g, string i, int id) 
        : title(t), description(d), Givenby(g), issueingClubId(id) { 
        completed = false; 
        static int nextId = 1; 
        AssignmentId = nextId++; 
        Iterations.push_back(i);
    }

    // Copy constructor
    Assignment(const Assignment& other) 
        : AssignmentId(other.AssignmentId), description(other.description),
          Givenby(other.Givenby), Iterations(other.Iterations), 
          StudentIds(other.StudentIds), completed(other.completed),
          issueingClubId(other.issueingClubId), title(other.title) 
    {
        // copy pointers as-is (shallow copy)
        for (int i = 0; i < other.Assignment_Submission.size(); i++)
            Assignment_Submission.push_back(other.Assignment_Submission[i]);
    }

    // Assignment operator
    Assignment& operator=(const Assignment& other) {
        if (this != &other) {
            AssignmentId = other.AssignmentId;
            description = other.description;
            Givenby = other.Givenby;
            Iterations = other.Iterations;
            StudentIds = other.StudentIds;
            completed = other.completed;
            issueingClubId = other.issueingClubId;
            title = other.title;
            Assignment_Submission = Vector<Submission*>(); // clear
            for (int i = 0; i < other.Assignment_Submission.size(); i++)
                Assignment_Submission.push_back(other.Assignment_Submission[i]);
        }
        return *this;
    }

    ~Assignment() {}

    // Getters 
    bool isCompleted() const { return completed; }
    bool markCompleted() { return completed = true; }
    int getAssignmentId() const { return AssignmentId; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    int getIssuingClubId() const { return issueingClubId; }
    Vector<string> getGivenBy() const { return Givenby; }
    Vector<string> getIterations() const { return Iterations; }
    Vector<int> getStudentIds() const { return StudentIds; }
    Vector<Submission*> getSubmissions() const { return Assignment_Submission; }
    
    void details() const {
        cout << "Assignment ID: " << AssignmentId << endl;
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;

        cout << "Given by: ";
        for (int i = 0; i < Givenby.size(); i++) {
            cout << Givenby[i] << " ";
        }
        cout << endl;

        cout << "Iterations: ";
        for (int i = 0; i < Iterations.size(); i++) {
            cout << Iterations[i] << " ";
        }
        cout << endl;
        cout << "Completed: " << (completed ? "Yes" : "No") << endl;
        cout << "Issuing Club ID: " << issueingClubId << endl;
    }
    
    // Additional useful methods
    void addTeacher(string teacher) {
        Givenby.push_back(teacher);
    }
    
    void addIteration(string iteration) {
        Iterations.push_back(iteration);
    }
    
    void addStudent(int studentId) {
        StudentIds.push_back(studentId);
    }

    void addSubmission(Submission* submission) {
        Assignment_Submission.push_back(submission);
    }
};

#endif
