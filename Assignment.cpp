#include "Assignment.h"
#include "Student.h"
#include "Club.h"
#include "Submissions.h"

// Constructor
Assignment::Assignment(string t, string d, Admin* g, string i, Club* c)
    : title(t),
      description(d),
      Givenby(g),
      issueingClub(c),
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
      Students(other.Students),
      completed(other.completed),
      issueingClub(other.issueingClub)
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
        Students = other.Students;
        completed = other.completed;
        issueingClub = other.issueingClub;

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

Club* Assignment::getIssueingClub() const {
    return issueingClub;
}

Admin* Assignment::getGivenBy() const {
    return Givenby;
}

Vector<string> Assignment::getIterations() const {
    return Iterations;
}

Vector<Student*> Assignment::getStudents() const {
    return Students;
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
    if (Givenby)
        cout << Givenby->getStudent()->getName();
    else
        cout << "N/A";
    cout << endl;

    cout << "Iterations: ";
    for (int i = 0; i < Iterations.size(); ++i) {
        cout << Iterations[i] << " ";
    }
    cout << endl;

    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    cout << "Issuing Club ID: " << issueingClub->getClubId() << endl;
}

// Modifiers

void Assignment::addIteration(const string& iteration) {
    Iterations.push_back(iteration);
}

void Assignment::addStudent(Student* student) {
    Students.push_back(student);
}

void Assignment::addSubmission(Submission* submission) {
    Assignment_Submission.push_back(submission);
}
