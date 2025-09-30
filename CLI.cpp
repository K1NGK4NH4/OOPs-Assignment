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
Vector<Submission*> submissions;
Vector<Admin*> admins;




void Signup();



void HomePage(Student* currentStudent = nullptr);

void displayInfo(Student* currentStudent);

void SearchStudent(Student* currentStudent);

void ClubInfo(Student* currentStudent);

void ClubRequests(Student* currentStudent);

void MyClubs(Student* currentStudent);

void ClubSelected(Student* currentStudent, Club* selectedClub);

int main(){
    Student* s1 = new Student("John Doe", 123456, "johndoe@example.com", 2022, 3.5, "123");
    
    Student* s2 = new Student("Jennifer", 654321, "Feeffer@example.com", 2023, 3.8, "321");
    Admin* a1 = new Admin(s1, "2021-01-01");
    Admin* a2 = new Admin(s2, "2020-05-01");
    Club* c1 = new Club("Computer Science Club", "csclub@example.com", a1);
    Club* c2 = new Club("Engineering Club", "engclub@example.com", a2);
    a1->setClub(c1);
    a2->setClub(c2);

    clubs.push_back(c1);
    clubs.push_back(c2);
    students.push_back(s1);
    students.push_back(s2);
    admins.push_back(a1);
    admins.push_back(a2);
    // Test: Student s2 requests to join Club c1
    s2->accessJoinClub(c1);

    cout<<"Starting Application..."<<endl;
    Signup();
    cout<<"Thanks for using the application!"<<endl;
    return 0;
}



void Signup(){ 
    int choice;
    cout<< "\nWelcome to the Student Club Management System!" << endl;
    cout<< "----------------------------"<<endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    
    cout<< "----------------------------"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    cout<< "----------------------------"<<endl;

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
    Vector<Club*> StudentClubs = currentStudent->ViewClubs();
    if(StudentClubs.empty()){
        cout << "None" << endl;
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

void HomePage(Student* currentStudent ){
    int choice;
    cout << "\nWelcome to the Student Club Management System!" << endl;
    cout<< "----------------------------"<<endl;
    cout << "1. My Information" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. CLub Info" << endl;    
    cout << "4. Club Requests" << endl;
    cout << "5. My Clubs" << endl;
    cout << "6. Logout" << endl;
    cout<< "----------------------------"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    cout<< "----------------------------\n"<<endl;
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
            cout << i+1 << ". " << clubs[i]->getName() << " (Club ID: " << clubs[i]->getClubId() <<" , Admin: "<< clubs[i]->getAdmin()->getStudent()->getName()<< ")" << endl;
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
    Vector<Club*> requests = currentStudent->getClubRequest();
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
    cout << "Joined club successfully!" << endl;
    return;
}

void MyClubs(Student* currentStudent){

    Vector<Club*> studentClubs = currentStudent->ViewClubs(false);
    if(studentClubs.empty()){
        cout << "No clubs joined!" << endl;
        return;
    }
    cout << "Joined Clubs: " << endl;
    for(int i = 0; i < studentClubs.size(); i++){
        cout << i+1 << ". " << studentClubs[i]->getName() << " (Club ID: " << studentClubs[i]->getClubId() << ") , Admin : " <<studentClubs[i]->getAdmin()->getStudent()->getName() << endl;
    }
    int choice;
    cout << "Enter the club number to view details or 0 to return: ";
    cin >> choice;
    if(choice == 0) return;
    if(choice < 1 || choice > studentClubs.size()){
        cout << "Invalid choice!" << endl;
        MyClubs(currentStudent);
        return;
    }
    ClubSelected(currentStudent, studentClubs[choice-1]);
    return;
}


void ClubSelected(Student* currentStudent, Club* selectedClub){
    if(currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    if(selectedClub == nullptr){
        cout << "No club selected!" << endl;
        return;
    }
    string choice;

    cout << "\n===== " << selectedClub->getName() <<selectedClub->getClubId() << " =====\n ===== " << selectedClub->getAdmin()->getStudent()->getName() << " =====\n";
        cout << "\n===== " << selectedClub->getName() << " =====\n";
        cout << "1. View Members\n";
        cout << "2. View Admin\n";
        cout << "3. View Assignments\n";
        cout << "4. My Assignments\n";
        cout << "5. My Submissions\n";
        cout << "6. Back to Clubs\n";

        if (selectedClub->getAdmin()->getStudent()->getEnrollment() == currentStudent->getEnrollment()) {
            cout << "===== Admin Tools =====\n";
            cout << "7. Manage Members\n";
            cout << "   a) List Members        (7a)\n";
            cout << "   b) Add Member          (7b)\n";
            cout << "   c) Remove Member       (7c)\n";
            cout << "   d) Assign Admin        (7d)\n";
            cout << "8. Manage Assignments\n";
            cout << "   a) Create Assignment   (8a)\n";
            cout << "   b) Edit Assignment     (8b)\n";
            cout << "   c) Delete Assignment   (8c)\n";
            cout << "   d) View Submissions    (8d)\n";
        }else{
            cout << "===== Admin Tools =====\n";
            cout << "7.Leave Club\n";
            cout<<"the only admin power you have is to leave the club hahaha"<<endl;
        }
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == "1") {
        }
        else if (choice =="2"){}
        else if (choice == "3"){}
        else if (choice == "4"){}
        else if (choice == "5"){}
        else if (choice == "6"){ }
        
        

    
}