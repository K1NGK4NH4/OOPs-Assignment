#include "Club.h"
#include "Student.h"
#include "Assignment.h"

// Constructor
Club::Club( const string& n, const string& m, Admin* a) : name(n), mail(m), admin(a) {
    static int ClubidCounter = 1;
    clubId = ClubidCounter++;
    members = Vector<Student*>();
    assignments = Vector<Assignment*>();
    members.push_back(a->getStudent());
    }

// Destructor
Club::~Club() {
    cout << "Club deleted" << endl;
}

// Getters
int Club::getClubId() const {
    return clubId;
}

string Club::getName() const {
    return name;
}

string Club::getMail() const {
    return mail;
}

Vector<Assignment*> Club::getAssignments() const {
    return assignments;
}

Vector<Student*> Club::getMembers() const {
    return members;
}

Admin* Club::getAdmin() const {
    return admin;
}

// Setters
void Club::setName(const string& n) {
    name = n;
}

void Club::setMail(const string& m) {
    mail = m;
}

void Club::setAdmin(Admin* a) {
    if (a) {
        a->setClub(this);
        admin = a;
    }
}

// Member management
void Club::addMember(Student* s) {
    for (int i = 0; i < members.size(); ++i) {
        if (members[i] == s) {
            return;
        }
    }
    members.push_back(s);
}

void Club::removeMember(int studentId) {
    Vector<Student*> temp;
    bool found = false;
    for (int i = 0; i < members.size(); ++i) {
        if (members[i]->getEnrollment() != studentId) {
            temp.push_back(members[i]);
        } else {
            found = true;
        }
    }
    members = temp;
    if (!found) {
        cout << "Member with ID " << studentId << " not found." << endl;
    }
}

// Assignment management
void Club::addAssignment(Assignment* a) {
    assignments.push_back(a);
}

void Club::removeAssignment(int assignmentId) {
    Vector<Assignment*> temp;
    bool found = false;
    for (int i = 0; i < assignments.size(); ++i) {
        if (assignments[i]->getAssignmentId() != assignmentId) {
            temp.push_back(assignments[i]);
        } else {
            found = true;
        }
    }
    assignments = temp;
    if (!found) {
        cout << "Assignment with ID " << assignmentId << " not found." << endl;
    }
}

// Listing
void Club::listAssignments() const {
    if (assignments.empty()) {
        cout << "No assignments available." << endl;
        return;
    }
    for (int i = 0; i < assignments.size(); ++i) {
        assignments[i]->details();
        cout << endl;
    }
}

void Club::listMembers() const {
    if (members.empty()) {
        cout << "No members in the club." << endl;
        return;
    }
    for (int i = 0; i < members.size(); ++i) {
        cout<<members[i]->getName()<<" (ID: "<<members[i]->getEnrollment()<<")"<< ", ";
    }
    cout << endl;
}

// Display club info
void Club::display() const {
    cout << "Club ID: " << clubId << endl;
    cout << "Name: " << name << endl;
    cout << "Mail: " << mail << endl;
    if (admin) {
        cout << "Admin: " << admin->getStudent()->getName()
             << " (ID: " << admin->getStudent()->getEnrollment() << ")" << endl;
    } else {
        cout << "Admin: None" << endl;
    }
    cout << "Number of Members: " << members.size() << endl;
    cout<< "Members: ";
    listMembers();
    cout << "Number of Assignments: " << assignments.size() << endl;
}

