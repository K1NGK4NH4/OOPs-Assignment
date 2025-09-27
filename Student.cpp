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
    cout<<"Do you want to join Club??"<<c->getName()<<"y/n?"<<endl;
    char choice;
    cin>>choice;
    return choice == 'y' ? true:false;
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
void Student::submitAssignment(Club* c,Submission* s) {
   Vector<Assignment*> hw = getAssignment(c);
   s->getAssignment();
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
    if(accessJoinClub(club)){
        club->addMember(s);
        cout << s->getName() << " added to club " << club->getName() << endl;
    }else{
        cout << s->getName() << " rejected to join club " << club->getName() << endl;
    }
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
