#include <iostream>
#include <string>
#include "Student.h"
#include "Vector.h"
#include "Club.h"
#include "Assignment.h"
#include "Submissions.h"
#include <exception>

using namespace std;

// Global vectors to store all students, clubs, and assignments
Vector<Student*> students;
Vector<Club*> clubs;
Vector<Assignment*> assignments;



void Signup();



void HomePage(Student* currentStudent = nullptr);

void displayInfo(Student* currentStudent);

void SearchStudent(Student* currentStudent);

void ClubInfo(Student* currentStudent);

void ClubRequests(Student* currentStudent);

void MyClubs(Student* currentStudent);


int main(){
    Signup();
    cout<<"Thanks for using the application!"<<endl;
    return 0;
}



void Signup(){ 
    int choice;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 1){
        int enrollment;
        string password;
        cout << "Enter Enrollment Number: ";
        cin >> enrollment;
        cout << "Enter Password: ";
        cin >> password;
        for(int i = 0; i < students.size(); i++){
            if(students[i]->login(enrollment, password)){
                cout << "Login Successful!" << endl;
                HomePage(students[i]);
                return;
            }
        }
        cout << "Login Failed!" << endl;
        Signup();
        return;
    } else if(choice == 2){
        try{
            string name, mail, password;
            int enrollment, gradYear;
            float cgpa;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Enrollment Number: ";
            cin >> enrollment;
            cout << "Enter Mail: ";
            cin >> mail;
            cout << "Enter Graduation Year: ";
            cin >> gradYear;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Password: ";
            cin >> password;
            Student* newStudent = new Student(name, enrollment, mail, gradYear, cgpa, password);
            students.push_back(newStudent);
            cout << "Registration Successful!" << endl;
            HomePage(newStudent);
            return ;
        } catch( exception& e) {
            cout << "Registration Failed! Please try again." << endl;
            Signup();
            return ;
        }
    }
    else if(choice == 3){
        return;
    } else {
        cout << "Invalid choice! Please try again." << endl;
        Signup();
        return ;
    }
}
void displayInfo(Student* currentStudent){
    if(currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    cout << "Name: " << currentStudent->getName() << endl;
    cout << "Enrollment Number: " << currentStudent->getEnrollment() << endl;
    cout << "Mail: " << currentStudent->getMail() << endl;
    cout << "Graduation Year: " << currentStudent->getGraduationYear() << endl;
    cout << "CGPA: " << currentStudent->getCGPA() << endl;
    cout << "Clubs Joined: ";
    Vector<Club*> clubs = currentStudent->ViewClubs();
    if(clubs.empty()){
        cout << "None" << endl;
    } else {
        for(int i = 0; i < clubs.size(); i++){
            cout << clubs[i]->getName() << " ";
        }
        cout << endl;
    }
    cout<<"ReEnter New Information?:(y to update / n to return to main menu)"<<endl;
    char ch; cin>>ch;
    if(ch=='y'){
        string name, mail, password;
        int  gradYear;
        float cgpa;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Mail: ";
        cin >> mail;
        cout << "Enter Graduation Year: ";
        cin >> gradYear;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        currentStudent->setCGPA(cgpa);
        currentStudent->setName(name);
        currentStudent->setMail(mail);
        currentStudent->setGraduationYear(gradYear);
        cout << "Information Updated!" << endl;
    }
    return;
}

void HomePage(Student* currentStudent = nullptr){
    int choice;
    cout << "Welcome to the Student Club Management System!" << endl;
    cout << "1. My Information" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. CLub Info" << endl;    
    cout << "4. Club Requests" << endl;
    cout << "5. My Clubs" << endl;
    cout << "6. Logout" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            displayInfo(currentStudent);
            HomePage(currentStudent);
            break;
        case 2:
            SearchStudent(currentStudent);
            HomePage(currentStudent);
            break;
        case 3:
            ClubInfo(currentStudent);
            HomePage(currentStudent);
            break;
        case 4:
            ClubRequests(currentStudent);
            HomePage(currentStudent);
            break;
        case 5:
            MyClubs(currentStudent);
            HomePage(currentStudent);
            break;
        case 6:
            cout << "Logging out..." << endl;
            Signup();
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            HomePage(currentStudent);
            break;
    }
}

void SearchStudent(Student* currentStudent){
    if(currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    int enrollment;
    cout << "Main menu: 0 \n All Students -1 \n Enter Enrollment Number to search/choice: ";
    cin >> enrollment;
    if(enrollment == 0) return;
    if(enrollment == -1){
        cout << "All Students: " << endl;
        for(int i = 0; i < students.size(); i++){
            cout << i+1 << ". " << students[i]->getName() << " (Enrollment: " << students[i]->getEnrollment() << ")" << endl;
        }
        return;
        }
    for(int i = 0; i < students.size(); i++){
        if(students[i]->getEnrollment() == enrollment){
            cout << "Student Found!" << endl;
            cout << "Name: " << students[i]->getName() << endl;
            cout << "Enrollment Number: " << students[i]->getEnrollment() << endl;
            cout << "Mail: " << students[i]->getMail() << endl;
            cout << "Graduation Year: " << students[i]->getGraduationYear() << endl;
            cout << "CGPA: " << students[i]->getCGPA() << endl;
            return;
        }
    }
    cout << "Student Not Found!" << endl;
    return;
}

void ClubInfo(Student* currentStudent){
    if(currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    int clubId;
    cout << "Main menu: 0 \n All Clubs -1 \n Enter Club ID to search/choice: ";
    cin >> clubId;
    if(clubId == 0) return;
    if(clubId == -1){
        cout << "All Clubs: " << endl;
        for(int i = 0; i < clubs.size(); i++){
            cout << i+1 << ". " << clubs[i]->getName() << " (Club ID: " << clubs[i]->getClubId() <<" , Admin: "<< clubs[i]->getAdmin()->getName()<< ")" << endl;
        }
        int select = -1;
        cout << "Enter the club number to view details or 0 to return: ";
        cin >> select;
        if(select == 0) return;
        if(select < 1 || select > clubs.size()){
            cout << "Invalid choice!" << endl;
            return;
        }
        clubs[select-1]->display();
        return;
    }
    for(int i = 0; i < clubs.size(); i++){
        if(clubs[i]->getClubId() == clubId){
            cout << "Club Found!" << endl;
            clubs[i]->display();
            return;
        }
    }
    cout << "Club Not Found!" << endl;
    return;
}

void ClubRequests(Student* currentStudent){
    if(currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    Vector<Club*> requests = currentStudent->ViewClubs();
    if(requests.empty()){
        cout << "No club requests!" << endl;
        return;
    }
    cout << "Club Requests: " << endl;
    for(int i = 0; i < requests.size(); i++){
        cout << i+1 << ". " << requests[i]->getName() << " (Club ID: " << requests[i]->getClubId() << ")" << endl;
    }
    int choice;
    cout << "Enter the club number to join or 0 to return: ";
    cin >> choice;
    if(choice == 0) return;
    if(choice < 1 || choice > requests.size()){
        cout << "Invalid choice!" << endl;
        return;
    }
    currentStudent->AddClub(requests[choice-1]);
    cout << "Joined club: " << requests[choice-1]->getName() << endl;
    return;
}