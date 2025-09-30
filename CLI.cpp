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

void AdminInterface(Admin* Admin);

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
    s2->addClubRequest(c1);

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
        std::cin >> enrollment;
        cout << "Enter Password: ";
        std::cin >> password;
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
            std::cin >> name;
            cout << "Enter Enrollment Number: ";
            std::cin >> enrollment;
            cout << "Enter Mail: ";
            std::cin >> mail;
            cout << "Enter Graduation Year: ";
            std::cin >> gradYear;
            cout << "Enter CGPA: ";
            std::cin >> cgpa;
            cout << "Enter Password: ";
            std::cin >> password;
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
    char ch; std::cin>>ch;
    if(ch=='y'){
        string name, mail, password;
        int  gradYear;
        float cgpa;
        cout << "Enter Name: ";
        std::cin >> name;
        cout << "Enter Mail: ";
        std::cin >> mail;
        cout << "Enter Graduation Year: ";
        std::cin >> gradYear;
        cout << "Enter CGPA: ";
        std::cin >> cgpa;
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
    std::cin >> choice;
    std::cin.ignore();
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
    std::cin >> enrollment;
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
    std::cin >> clubId;
    if(clubId == 0) return;
    if(clubId == -1){
        cout << "All Clubs: " << endl;
        for(int i = 0; i < clubs.size(); i++){
            cout << i+1 << ". " << clubs[i]->getName() << " (Club ID: " << clubs[i]->getClubId() <<" , Admin: "<< clubs[i]->getAdmin()->getStudent()->getName()<< ")" << endl;
        }
        int select = -1;
        cout << "Enter the club number to view details or 0 to return: ";
        std::cin >> select;
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
    cout << "Enter the club number to process or 0 to return: ";
    std::cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > requests.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "1. Join Club\n2. Discard Request\nEnter your option: ";
    int action;
    std::cin >> action;
    if (action == 1) {
        currentStudent->AddClub(requests[choice - 1]);
        requests[choice - 1]->getAdmin()->setNotifications(currentStudent->getName() + " has joined the club " + requests[choice - 1]->getName() + "."); //notify the admin here
        requests[choice - 1]->addMember(currentStudent);
        cout << "Joined club successfully!" << endl;
        currentStudent->removeClubRequest(requests[choice - 1]);   
    } else if (action == 2) {
        // Remove the request from the student's clubRequest vector
        currentStudent->removeClubRequest(requests[choice - 1]);
        requests[choice - 1]->getAdmin()->setNotifications(currentStudent->getName() + "'s request to join the club " + requests[choice - 1]->getName() + " has been discarded."); //notify the admin here
        cout << "Request discarded." << endl;
    } else {
        cout << "Invalid option!" << endl;
    }
    return;
}

void SelectedClubInterface(Student* currentStudent, Club* club);
void ClubSelected(Student* currentStudent, Club* selectedClub);

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
    std::cin >> choice;
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
        cout << "6. Back to Main Menu\n";

        if (selectedClub->getAdmin()->getStudent()->getEnrollment() == currentStudent->getEnrollment()) {
            cout << "===== Admin Tools =====\n";
            cout << "7. Manage Members\n";
            cout << "   a) List Members        (7a)\n";
            cout << "   b) Add Member          (7b)\n";
            cout << "   c) Remove Member       (7c)\n";
            cout << "   d) Assign Admin        (7d)\n";
            cout << "   e) Leave Club           (7e)\n";
            cout << "8. Manage Assignments\n";
            cout << "   a) Create Assignment   (8a)\n";
            cout << "   b) Edit Assignment     (8b)\n";
            cout << "   c) Delete Assignment   (8c)\n";
            cout << "   d) View Submissions    (8d)\n";
        }else{
            cout << "7.Leave Club\n";
            cout<<"the only admin power you have is to leave the club hahaha"<<endl;
        }
        cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == "1") {
            selectedClub->getMembers();
            for(int i=0;i<selectedClub->getMembers().size();i++){
                cout<<i+1<<". "<<selectedClub->getMembers()[i]->getName()<<" (ID: "<<selectedClub->getMembers()[i]->getEnrollment()<<")"<<endl;
            }
            int choice;
            cout << "Enter the member number to view details or 0 to return: ";
            std::cin >> choice;
            if(choice == 0) {ClubSelected(currentStudent, selectedClub);
                return;}
            if(choice < 1 || choice > selectedClub->getMembers().size()){
                cout << "Invalid choice!" << endl;
                ClubSelected(currentStudent, selectedClub);
                return;
            }
            Student* member = selectedClub->getMembers()[choice-1];
            cout << "Member Details:" << endl;  
            
            cout << "Name: " << member->getName() << endl;
            cout<< "Admin: "<< (member->getEnrollment() == selectedClub->getAdmin()->getStudent()->getEnrollment() ? "Yes" : "No") << endl;
            cout << "Enrollment Number: " << member->getEnrollment() << endl;
            cout << "Mail: " << member->getMail() << endl;
            cout << "Graduation Year: " << member->getGraduationYear() << endl;
            cout << "CGPA: " << member->getCGPA() << endl;
            ClubSelected(currentStudent, selectedClub);
            return;

        }
        else if (choice =="2"){
            Admin* admin = selectedClub->getAdmin();
            if(admin == nullptr){
                cout << "No admin assigned!" << endl;
                ClubSelected(currentStudent, selectedClub);
                return;
            }
            Student* adminStudent = admin->getStudent();
            cout << "Admin Details:" << endl;
            cout << "Name: " << adminStudent->getName() << endl;
            cout << "Enrollment Number: " << adminStudent->getEnrollment() << endl;
            cout << "Mail: " << adminStudent->getMail() << endl;
            cout << "Graduation Year: " << adminStudent->getGraduationYear() << endl;
            cout << "CGPA: " << adminStudent->getCGPA() << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        else if (choice == "3"){
            selectedClub->listAssignments();
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        else if (choice == "4"){
            //work here is left
        }
        else if (choice == "5"){}
        else if (choice == "6"){ 
            return;
        }
        else if (choice == "7a"){}
        else if (choice == "7b"){}
        else if (choice == "7c"){}
        else if (choice == "7d"){}
        else if (choice == "7e"){}
        else if (choice == "8a"){}
        else if (choice == "8b"){}
        else if (choice == "8c"){}
        else if (choice == "8d"){}
        else {
            cout << "Invalid choice! Please try again." << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
}
void SelectedClubInterface(Student* currentStudent, Club* club){
    if (currentStudent == nullptr) {
        cout << "No student logged in!" << endl;
        return;
    }
    if (club == nullptr) {
        cout << "No club selected!" << endl;
        return;
    }
    cout << "Welcome to the " << club->getName() << " club interface." << endl;
    int choice;
    do {
        cout << "\n--- " << club->getName() << " Club Menu ---" << endl;
        cout << "1. View Members" << endl;
        cout << "2. View Admin" << endl;
        cout << "3. View Assignments" << endl;
        cout << "4. My Submissions" << endl;
        cout << "5. My Assignments" << endl;
        cout << "6. Admin Work" << endl;
        cout << "7. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: { // View Members
                Vector<Student*> members = club->getMembers();
                if (members.empty()) {
                    cout << "No members in this club." << endl;
                } else {
                    cout << "Club Members:" << endl;
                    for (int i = 0; i < members.size(); ++i) {
                        cout << i + 1 << ". " << members[i]->getName() << " (Enrollment: " << members[i]->getEnrollment() << ")" << endl;
                    }
                }
                break;
            }
            case 2: { // View Admin
                Admin* admin = club->getAdmin();
                if (admin) {
                    Student* adminStudent = admin->getStudent();
                    cout << "Admin: " << adminStudent->getName() << " (Enrollment: " << adminStudent->getEnrollment() << ")" << endl;
                } else {
                    cout << "No admin assigned to this club." << endl;
                }
                break;
            }
            case 3: { // View Assignments
                Vector<Assignment*> clubAssignments = club->getAssignments();
                if (clubAssignments.empty()) {
                    cout << "No assignments for this club." << endl;
                } else {
                    cout << "Assignments:" << endl;
                    for (int i = 0; i < clubAssignments.size(); ++i) {
                        cout << i + 1 << ". " << clubAssignments[i]->getTitle() << endl;
                    }
                }
                break;
            }
            case 4: { // My Submissions
                //Display Submissions 
                cout << "Yet to implement" << endl;
            }
            case 5: { // My Assignments
                //Yet to implement
                cout << "Yet to implement" << endl;
            }
            case 6: { // Admin Work
                Admin* admin = club->getAdmin();
                if (admin && admin->getStudent() == currentStudent) {
                    AdminInterface(admin);
                } else {
                    cout << "Access denied: You are not the admin of this club." << endl;
                }
                break;
            }
            case 7:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    // You can add more club-specific actions here if needed
}

// void AdminInterface(Admin* admin){
//     if (admin == nullptr) {
//         cout << "No admin logged in!" << endl;
//         return;
//     }
//     Club* club = admin->getClub();
//     if (club == nullptr) {
//         cout << "No club assigned to this admin!" << endl;
//         return;
//     }
//     int choice;
//     do {
//         cout << "\n--- Admin Interface for " << club->getName() << " ---" << endl;
//         cout << "1. View Notifications" << endl;
//         cout << "2. View Members" << endl;
//         cout << "3. Add Member" << endl;
//         cout << "4. Remove Member" << endl;
//         cout << "5. Assign Admin" << endl;
//         cout << "6. Assignment Stuff" << endl;
//         cout << "7. Exit Admin Interface" << endl;
//         cout << "----------------------------" << endl;
//         cout << "Enter your choice: ";
//         std::cin >> choice;
//         std::cin.ignore();
//         switch (choice) {
//             case 1: { // View Notifications
//                 Vector<string> notes = admin->getNotifications();
//                 if (notes.empty()) {
//                     cout << "No notifications." << endl;
//                 } else {
//                     cout << "Notifications:" << endl;
//                     for (int i = 0; i < notes.size(); ++i) {
//                         cout << i + 1 << ". " << notes[i] << endl;
//                     }
//                 }
//                 cout << "Do you want to delete all notifications? (y/n): ";
//                 char delAllChoice;
//                 std::cin >> delAllChoice;
//                 if (delAllChoice == 'y') {
//                     admin->removeallnotifications();
//                     cout << "All notifications deleted." << endl;
//                 }
//                 cout << "Do you want to delete any particular notification? (y/n): ";
//                 char delChoice;
//                 std::cin >> delChoice;
//                 if (delChoice == 'y') {
//                     cout << "Enter the notification numbers to delete separated by spaces (end with 0): ";
//                     Vector<int> delIndices;
//                     int delIndex;
//                     while (std::cin >> delIndex && delIndex != 0) {
//                         if (delIndex > 0 && delIndex <= notes.size()) {
//                             delIndices.push_back(delIndex - 1);
//                         } else {
//                             cout << "Invalid notification number: " << delIndex << endl;
//                         }
//                     }
//                     std::cin.clear(); // Clear the fail state
//                     for (int i = delIndices.size() - 1; i >= 0; --i) {
//                         int idx = delIndices[i];
//                         if (idx >= 0 && idx < notes.size()) {
//                             admin->removeNotification(notes[idx]);
//                         }
//                     }
//                     if (!delIndices.empty())
//                         cout << "Selected notifications deleted." << endl;
//                     else
//                         cout << "No valid notifications selected for deletion." << endl;
//                 }
//                 break;
//             }
//             case 2: { // View Members
//                 Vector<Student*> members = club->getMembers();
//                 if (members.empty()) {
//                     cout << "No members in this club." << endl;
//                 } else {
//                     cout << "Club Members:" << endl;
//                     for (int i = 0; i < members.size(); ++i) {
//                         cout << i + 1 << ". " << members[i]->getName() << " (Enrollment: " << members[i]->getEnrollment() << ")" << endl;
//                     }
//                 }
//                 break;
//             }
//             case 3: { // Add Member
//                 cout<<"Enter Enrollment of student to add: ";
//                 int enroll; 
//                 std::cin>>enroll;
//                 bool found = false;
//                 for(int i = 0; i < students.size(); i++){
//                     if(students[i]->getEnrollment() == enroll){
//                         admin->addMember(students[i]);
//                        found = true;
//                        break;
//                     }
//                 }
//                 if (found) {
//                     // Member added successfully
//                     cout << "Student will be added automatically when he accepts the invitation." << endl;
//                 } else {
//                     cout << "Student not found." << endl;
//                 }
//                 break;
//             }
//             case 4: { // Remove Member
//                 cout<<"Enter Enrollment of student to remove: ";
//                 int enroll;
//                 std::cin>>enroll;
//                 admin->removeMember(enroll);
//                 cout << "Student is removed from the Club." << endl;
//                 break;
//             }
//             case 5: { // Assign Admin
//                 cout<<"Enter Enrollment of student to assign as new Admin: ";
//                 int enroll;
//                 std::cin>>enroll;
//                 cout<<"Enter joining date (YYYY-MM-DD): ";
//                 string date;
//                 std::cin>>date;
//                 bool found = false;
//                 if(enroll == admin->getStudent()->getEnrollment()){
//                     cout << "You are already the admin." << endl;
//                     break;
//                 }
//                 Admin* newAdmin = nullptr;
//                 for(int i = 0; i < students.size(); i++){
//                     if(students[i]->getEnrollment() == enroll){
//                         newAdmin = new Admin(students[i], date);
//                         admin->setNewAdmin(newAdmin);
//                         found = true;
//                         cout << students[i]->getName() << " is now the new admin of the club." << endl;
//                         break;
//                     }
//                 }
//                 if (!found) {
//                         cout << "No student found with enrollment " << enroll << endl;
//                 }
//                 break;
//             }
//             case 6: { // Assignment Stuff
//                 cout << "Yet to implement Assignment functionalities." << endl;
//                 break;
//             }
//             case 7:
//                 cout << "Exiting Admin Interface..." << endl;
//                 break;
//             default:
//                 cout << "Invalid choice!" << endl;
//         }
//     } while (choice != 6);
// }





