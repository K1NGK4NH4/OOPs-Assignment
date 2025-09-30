#include "Student.h"
#include "Club.h"
#include "Submissions.h"
#include "Assignment.h"

// Default constructor
Student::Student() 
    : Student("", 0, "",0,0.0){}

// Parameterized constructor
Student::Student(string n,int e, string m, int gradYear, float g,string pass)
    : name(n),Enrollment(e),mail(m),GraduationYear(gradYear),cgpa(g),password(pass) {}

Student::Student( Student* other)
    : name(other->name),Enrollment(other->Enrollment),mail(other->mail),
      GraduationYear(other->GraduationYear),cgpa(other->cgpa),password(other->password),
      Clubs(other->Clubs),Assignment_Submission(other->Assignment_Submission),
      clubRequest(other->clubRequest) {}

bool Student::login(int enroll,string pass) {
    // Access admin from club
    if(enroll == Enrollment && pass == password) return true;
    return false;
}

// Join a club
void Student::accessJoinClub(Club* c) {
    // Access admin from club
    // Check if already invited
    for (int i = 0; i < clubRequest.size(); ++i) {
        if (clubRequest[i] == c) return;
    }
    clubRequest.push_back(c);
}
// Add a club
void Student::AddClub(Club* c){
    // Check if already a member
    for (int i = 0; i < Clubs.size(); ++i) {
        if (Clubs[i] == c) return;
    }
       Clubs.push_back(c);
         c->addMember(this);
            clubRequest.pop(c);
}
// Leave a club
bool Student::leaveClub(Club* c) {
    Clubs.pop(c);
    return true;
}

// View clubs
Vector<Club*> Student::ViewClubs(bool display) const {
    if(display)  
        {
        std::cout << "Clubs Joined: ";
    for (size_t i = 0; i < Clubs.size(); i++)
        {
           
            std::cout << Clubs[i]->getName() << ", ";
        }
    }
    std::cout << std::endl;
    return Clubs;
}


// Submit assignment
void Student::submitAssignment(Submission* s) {
}

// Get assignment (just prints club name for now)


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




Admin::Admin(Student* s, string join )
        : student(s),  joiningDate(join) {}

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
Club* Admin:: getClub() const{
         return club; 
    }
void Admin::setClub(Club* c) { 
    club = c;
    student->AddClub(c);
 }
string Admin :: getJoiningDate() const {
         return joiningDate; }