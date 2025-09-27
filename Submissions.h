    #ifndef SUBMISSION_H
    #define SUBMISSION_H

    #include <string>
    #include <iostream>
    #include "Vector.h"
    using namespace std;

    class Submission  {
    private:
        int studentID;                 // ID of the student who submitted
        string studentName  ;            // Name of student
        int assignmentID;              // ID of the assignment
        string submissionDate;         // Date of submission
        Vector<string> submittedFiles; // List of submitted files
        string review;                 // Review comments
        int score;                  // Score / grade

    public:
        // Constructor
        Submission(int id = 0, string name = "", int aid = 0,
                string date = "")
            : studentID(id), studentName(name), assignmentID(aid), submissionDate(date), review(""), score(0) { }

        // Getters
        int getStudentID() const { return studentID; }
        string getStudentName() const { return studentName; }
        int getAssignmentID() const { return assignmentID; }
        string getSubmissionDate() const { return submissionDate; }
        Vector<string> getSubmittedFiles() const { return submittedFiles; }
        string getReview() const { return review; }
        double getScore() const { return score; }

        // Setters
        void setReview(const string& r) { review = r; }
        void setScore(double s) { score = s; }

        void addFile(const string& file) { submittedFiles.push_back(file); }

        // Display submission info
        void display() const {
            cout << "Student ID: " << studentID << "\n";
            cout << "Student Name: " << studentName << "\n";    
            cout << "Assignment ID: " << assignmentID << "\n";
            cout << "Submission Date: " << submissionDate << "\n";
            cout << "Submitted Files: ";
            if (submittedFiles.empty())
                cout << "None";
            else
                for (int i = 0; i < submittedFiles.size(); i++)
                    cout << submittedFiles[i] << " ";
                    
            cout << "\nReview: " << (review.empty() ? "No review yet" : review) << "\n";
            cout << "Score: " << score << "\n";
            cout << "---------------------------\n";
        }
    };

    #endif
