#include "Submissions.h"

Submission::Submission(int id, string name, int aid, string date)
    : studentID(id),
      studentName(name),
      assignmentID(aid),
      submissionDate(date),
      review(""),
      score(0) { }

// Getters
int Submission::getStudentID() const {
    return studentID;
}

string Submission::getStudentName() const {
    return studentName;
}

int Submission::getAssignmentID() const {
    return assignmentID;
}

string Submission::getSubmissionDate() const {
    return submissionDate;
}

Vector<string> Submission::getSubmittedFiles() const {
    return submittedFiles;
}

string Submission::getReview() const {
    return review;
}

double Submission::getScore() const {
    return score;
}

// Setters
void Submission::setReview(const string& r) {
    review = r;
}

void Submission::setScore(double s) {
    score = s;
}

void Submission::addFile(const string& file) {
    submittedFiles.push_back(file);
}

// Display submission info
void Submission::display() const {
    cout << "Student ID: " << studentID << "\n";
    cout << "Student Name: " << studentName << "\n";    
    cout << "Assignment ID: " << assignmentID << "\n";
    cout << "Submission Date: " << submissionDate << "\n";
    cout << "Submitted Files: ";
    if (submittedFiles.empty()) {
        cout << "None";
    } else {
        for (int i = 0; i < submittedFiles.size(); i++) {
            cout << submittedFiles[i] << " ";
        }
    }
    cout << "\nReview: " << (review.empty() ? "No review yet" : review) << "\n";
    cout << "Score: " << score << "\n";
    cout << "---------------------------\n";
}
