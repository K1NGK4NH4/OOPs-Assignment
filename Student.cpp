#include "Student.h"
#include "Club.h"
#include "Submissions.h"
#include "Assignment.h"

// Default constructor
Student::Student() 
    : Student("", 0, "",0,0.0){}

// Parameterized constructor
Student::Student(string n,int e, string m, int gradYear, float g)
    : name(n),Enrollment(e),mail(m),GraduationYear(gradYear),cgpa(g) {}

bool Student::login(int enroll,string pass) {
    // Access admin from club
    if(enroll == Enrollment && pass == password) return true;
    return false;
}
// Join a club
void Student::accessJoinClub(Club* c) {
    // Access admin from club
    clubRequest.push_back(c);
}

// Leave a club
bool Student::leaveClub(Club* c) {
    Clubs.pop(c);
    return true;
}

// View clubs
Vector<Club*> Student::ViewClubs() const {
    return Clubs;
}

// Submit assignment
void Student::submitAssignment(Submission* s) {
   Assignment* hw =  s->getAssignment();
}

// Get assignment (just prints club name for now)
Vector<Assignment*> Student::getAssignment(Club* c) const {
    cout << "Assignments for club: " << c->getName()<< endl;
    return c->getAssignments();
}

// Getters
string Student::getName() const {
     return name; 
}
string Student::getMail() const {
     return mail; 
}
int Student::getEnrollment() const {
     return Enrollment; 
}
int Student::getGraduationYear() const { 
    return GraduationYear; 
}
float Student::getCGPA() const {
     return cgpa; 
}




Admin::Admin(string n, int e, string m, int gradYear, float g, Club* c, string join)
        : Student(n, e, m, gradYear, g), club(c), joiningDate(join) {}

// Add member
void Admin::addMember(Student* s){
       s->accessJoinClub(club);
}

// Remove member
void Admin::removeMember(int studentId) {
   club->removeMember(studentId);
}

// Add assignment
void Admin::addAssignment( Assignment* a) {
    club->addAssignment(a);
}

// Remove assignment
void Admin::removeAssignment(int assignmentId) {
    club->removeAssignment(assignmentId);
}

// Set a new admin
void Admin::setNewAdmin(Admin* newAdmin) {
    club->setAdmin(newAdmin);
}
