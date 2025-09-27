#include "Submissions.h"

Submission::Submission(Student* s, Assignment* a, bool isLate)
    : student(s), assignment(a), late(isLate), review(""), score(0) { }

// Getters
Student* Submission::getStudent() const {
    return student;
}

Assignment* Submission::getAssignment() const {
    return assignment;
}

bool Submission::isLate() const {
    return late;
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
    cout << "Student ID: " << student->getEnrollment() << "\n";
    cout << "Student Name: " << student->getName() << "\n";    
    cout << "Assignment ID: " << assignment->getAssignmentId() << "\n";
    cout << "isLate: " << isLate() << "\n";
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
