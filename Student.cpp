#include "Student.h"

// Default constructor
Student::Student() 
    : Student("", 0, "",0,0.0){}

// Parameterized constructor
Student::Student(string n,int e, string m, int gradYear, float g)
    : name(n),Enrollment(e),mail(m),GraduationYear(gradYear),cgpa(g) {}

// Add credentials manually
void Student::AddCredentials() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter your mail: ";
    getline(cin, mail);

    cout << "Enter graduation year: ";
    cin >> GraduationYear;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    cout << "Enter enrollment ID: ";
    cin >> Enrollment;
}

// View credentials
void Student::ViewCredentials() const {
    cout << "Name: " << name << endl;
    cout << "Mail: " << mail << endl;
    cout << "Graduation Year: " << GraduationYear << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Enrollment ID: " << Enrollment << endl;
}

// Join a club
bool Student::accessJoinClub(Club* c) {
    // Access admin from club
    
}



// Leave a club
bool Student::leaveClub(Club* c) {
    Vector<Club*> temp;
    for (int i = 0; i <= Clubs.size() - 1; i++) {
        if (Clubs[i] != c)
            temp.push_back(Clubs[i]);
    }
    Clubs = temp;
    return true;
}

// View clubs
Vector<Club*> Student::ViewClubs() const {
    return Clubs;
}

// Submit assignment
void Student::submitAssignment(Assignment* a, bool late) {
    Submission* s = new Submission(a, late);
    Assignment_Submission.push_back(s);
}

// Get assignment (just prints club name for now)
// void Student::getAssignment(Club* c) const {
//     cout << "Assignments for club: " << c->name << endl;
// }

// Getters
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
bool Admin::addMember(Student* s) {

    club->addMember(s);
    cout << s->getName() << " added to club " << club->getName() << endl;
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
void Admin::setNewAdmin(Student* newAdmin) {
    club->setAdmin(newAdmin);
}
