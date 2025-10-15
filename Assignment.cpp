#include "Assignment.h"
#include "Student.h"
#include "Club.h"
#include "Submissions.h"

// Constructor
Assignment::Assignment(string t, string d, Admin* g, Club* c, string finalDate )
    : title(t),
      description(d),
      Givenby(g),

      issueingClub(c),
      completed(false),
    finalDate(finalDate)
{
    static int nextId = 1;
    AssignmentId = nextId++;
}

// Copy constructor
Assignment::Assignment(const Assignment& other)
    : AssignmentId(other.AssignmentId),
      title(other.title),
      description(other.description),
      Givenby(other.Givenby),
      Students(other.Students),
      completed(other.completed),
      issueingClub(other.issueingClub)
        ,finalDate(other.finalDate)
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
        Students = other.Students;
        completed = other.completed;
        issueingClub = other.issueingClub;
        finalDate = other.finalDate;
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

    cout << endl;
    cout << "Final Date: " << finalDate << endl;
    cout << "Number of Students Assigned: " << Students.size() << endl;
    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    cout << "Issuing Club ID: " << issueingClub->getClubId() << endl;
}

// Modifiers



void Assignment::addStudent(Student* student) {
    Students.push_back(student);
    Submission* newSubmission = new Submission(student, this, false);
    Assignment_Submission.push_back(newSubmission);
    student->addSubmission(newSubmission);
}

void Assignment::addSubmission(Submission* submission) {
    Assignment_Submission.push_back(submission);
}

void Assignment::setTitle(const string& t) { title = t; }
void Assignment::setDescription(const string& d) { description = d; }
void Assignment::setFinalDate(const string& date) { finalDate = date; }
void Assignment::removeStudent(int studentId) {
    Vector<Student*> temp;
    bool found = false;
    Student* studentToRemove = nullptr;
    for (int i = 0; i < Students.size(); ++i) {
        if (Students[i]->getEnrollment() != studentId) {
            temp.push_back(Students[i]);
        } else {
            studentToRemove = Students[i];
            found = true;
        }
    }
    studentToRemove->removeSubmission(this);
    Students = temp;
    if (!found) {
        cout << "Student with ID " << studentId << " not found." << endl;
    }
}