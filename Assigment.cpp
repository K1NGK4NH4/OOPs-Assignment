#include "Assigment.h"

// Constructor
Assignment::Assignment(string t, string d, Vector<string> g, string i, int id)
    : title(t),
      description(d),
      Givenby(g),
      issueingClubId(id),
      completed(false)
{
    static int nextId = 1;
    AssignmentId = nextId++;
    Iterations.push_back(i);
}

// Copy constructor
Assignment::Assignment(const Assignment& other)
    : AssignmentId(other.AssignmentId),
      title(other.title),
      description(other.description),
      Givenby(other.Givenby),
      Iterations(other.Iterations),
      StudentIds(other.StudentIds),
      completed(other.completed),
      issueingClubId(other.issueingClubId)
{
    // Shallow copy of submission pointers
    for (int i = 0; i < other.Assignment_Submission.size(); ++i) {
        Assignment_Submission.push_back(other.Assignment_Submission[i]);
    }
}

// Assignment operator
Assignment& Assignment::operator=(const Assignment& other) {
    if (this != &other) {
        AssignmentId = other.AssignmentId;
        title = other.title;
        description = other.description;
        Givenby = other.Givenby;
        Iterations = other.Iterations;
        StudentIds = other.StudentIds;
        completed = other.completed;
        issueingClubId = other.issueingClubId;

        Assignment_Submission = Vector<Submission*>();
        for (int i = 0; i < other.Assignment_Submission.size(); ++i) {
            Assignment_Submission.push_back(other.Assignment_Submission[i]);
        }
    }
    return *this;
}

// Destructor
Assignment::~Assignment() {}

// Getters
bool Assignment::isCompleted() const {
    return completed;
}

bool Assignment::markCompleted() {
    completed = true;
    return completed;
}

int Assignment::getAssignmentId() const {
    return AssignmentId;
}

string Assignment::getTitle() const {
    return title;
}

string Assignment::getDescription() const {
    return description;
}

int Assignment::getIssuingClubId() const {
    return issueingClubId;
}

Vector<string> Assignment::getGivenBy() const {
    return Givenby;
}

Vector<string> Assignment::getIterations() const {
    return Iterations;
}

Vector<int> Assignment::getStudentIds() const {
    return StudentIds;
}

Vector<Submission*> Assignment::getSubmissions() const {
    return Assignment_Submission;
}

// Display details
void Assignment::details() const {
    cout << "Assignment ID: " << AssignmentId << endl;
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;

    cout << "Given by: ";
    for (int i = 0; i < Givenby.size(); ++i) {
        cout << Givenby[i] << " ";
    }
    cout << endl;

    cout << "Iterations: ";
    for (int i = 0; i < Iterations.size(); ++i) {
        cout << Iterations[i] << " ";
    }
    cout << endl;

    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    cout << "Issuing Club ID: " << issueingClubId << endl;
}

// Modifiers
void Assignment::addTeacher(const string& teacher) {
    Givenby.push_back(teacher);
}

void Assignment::addIteration(const string& iteration) {
    Iterations.push_back(iteration);
}

void Assignment::addStudent(int studentId) {
    StudentIds.push_back(studentId);
}

void Assignment::addSubmission(Submission* submission) {
    Assignment_Submission.push_back(submission);
}
