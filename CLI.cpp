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
Vector<Student *> students;
Vector<Club *> clubs;
Vector<Assignment *> assignments;
Vector<Submission *> submissions;
Vector<Admin *> admins;

void Signup();

void HomePage(Student *currentStudent = nullptr);

void displayInfo(Student *currentStudent);

void SearchStudent(Student *currentStudent);

void ClubInfo(Student *currentStudent);

void ClubRequests(Student *currentStudent);

void MyClubs(Student *currentStudent);

void ClubSelected(Student *currentStudent, Club *selectedClub);

void viewNotifications(Admin *admin);

void viewAssignmentDetails(Club* selectedClub,Student* currentStudent,Vector<Assignment*> assignments);

void viewSubmissionDetails(Club* selectedClub,Student* currentStudent,Vector<Submission*> submissions);

void MyAssignments(Student *currentStudent, Club *selectedClub);
void AssignmentSelected(Student *currentStudent, Assignment *selectedAssignment, Club *selectedClub);

void editAssignmentDetails(Club* selectedClub,Student* currentStudent,Vector<Assignment*> assignments);
void deleteAssignment(Club* selectedClub, Student* currentStudent, Vector<Assignment*> assignments);
void viewSubmissionDetails(Club* selectedClub, Student* currentStudent, Vector<Assignment*> assignments);
void reviewSubmission(Submission* selectedSubmission, Student* selectedStudent);

int main()
{
    // ==========================
    // Create Students
    // ==========================
    Student *s1 = new Student("John Doe", 1001, "john@example.com", 2022, 3.5, "pass123");
    Student *s2 = new Student("Jennifer Smith", 1002, "jennifer@example.com", 2023, 3.8, "pass321");
    Student *s3 = new Student("Michael Brown", 1003, "michael@example.com", 2024, 3.2, "mike456");
    Student *s4 = new Student("Emily Davis", 1004, "emily@example.com", 2022, 3.9, "emily789");
    Student *s5 = new Student("William Johnson", 1005, "william@example.com", 2025, 3.4, "will987");
    Student *s6 = new Student("Olivia Martinez", 1006, "olivia@example.com", 2023, 3.6, "olivia654");
    Student *s7 = new Student("James Wilson", 1007, "james@example.com", 2024, 3.3, "james321");
    Student *s8 = new Student("Sophia Taylor", 1008, "sophia@example.com", 2022, 3.7, "sophia111");

    // ==========================
    // Create Admins
    // ==========================
    Admin *a1 = new Admin(s1, "2021-01-01");
    Admin *a2 = new Admin(s2, "2020-05-01");
    Admin *a3 = new Admin(s3, "2022-03-15");
    Admin *a4 = new Admin(s4, "2021-09-10");

    // ==========================
    // Create Clubs
    // ==========================
    Club *c1 = new Club("Computer Science Club", "csclub@example.com", a1);
    Club *c2 = new Club("Engineering Club", "engclub@example.com", a2);
    Club *c3 = new Club("Mathematics Club", "mathclub@example.com", a3);
    Club *c4 = new Club("Physics Club", "physicsclub@example.com", a4);

    // ==========================
    // Set Club for Admins
    // ==========================
    a1->setClub(c1);
    a2->setClub(c2);
    a3->setClub(c3);
    a4->setClub(c4);

    // ==========================
    // Push to Global Vectors
    // ==========================
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);
    students.push_back(s4);
    students.push_back(s5);
    students.push_back(s6);
    students.push_back(s7);
    students.push_back(s8);

    admins.push_back(a1);
    admins.push_back(a2);
    admins.push_back(a3);
    admins.push_back(a4);

    clubs.push_back(c1);
    clubs.push_back(c2);
    clubs.push_back(c3);
    clubs.push_back(c4);

    // ==========================
    // Club Membership Requests
    // ==========================
    s5->addClubRequest(c1); // William -> CS Club
    s6->addClubRequest(c2); // Olivia -> Engineering
    s7->addClubRequest(c3); // James -> Math
    s8->addClubRequest(c4); // Sophia -> Physics
    s5->addClubRequest(c2); // William -> Engineering
    s6->addClubRequest(c3); // Olivia -> Math
    s7->addClubRequest(c1); // James -> CS
    s8->addClubRequest(c2); // Sophia -> Engineering

    // ==========================
    // Pre-join some students to clubs
    // ==========================
    c1->addMember(s1); // John already in CS Club
    c2->addMember(s2); // Jennifer already in Engineering
    c3->addMember(s3); // Michael in Math
    c4->addMember(s4); // Emily in Physics

    s1->AddClub(c1);
    s2->AddClub(c2);
    s3->AddClub(c3);
    s4->AddClub(c4);

    // ==========================
    // Assign Notifications
    // ==========================
    a1->setNotifications("Welcome John! You are admin of CS Club.");
    a2->setNotifications("Welcome Jennifer! You are admin of Engineering Club.");
    a3->setNotifications("Welcome Michael! You are admin of Math Club.");
    a4->setNotifications("Welcome Emily! You are admin of Physics Club.");

    // ==========================
    // Assignments (optional examples)
    // ==========================
    Assignment *assign1 = new Assignment("CS101 HW1", "Solve 5 dynamic programming problems", a1,  c1);
    Assignment *assign2 = new Assignment("ENG201 Lab", "Submit CAD design project", a2, c2);
    Assignment *assign3 = new Assignment("MATH301 Quiz", "Integration practice problems", a3,  c3);
    Assignment *assign4 = new Assignment("PHY101 Report", "Write lab report on optics experiment", a4, c4);

    assignments.push_back(assign1);
    assignments.push_back(assign2);
    assignments.push_back(assign3);
    assignments.push_back(assign4);

    c1->addAssignment(assign1);
    c2->addAssignment(assign2);
    c3->addAssignment(assign3);
    c4->addAssignment(assign4);

    assign1->addStudent(s5);
    assign2->addStudent(s6);
    assign3->addStudent(s7);
    assign4->addStudent(s8);
    // ==========================
    // Example Submissions
    // ==========================
    Submission *sub1 = new Submission(s5, assign1, false); // William -> CS HW1 (on time)
    Submission *sub2 = new Submission(s6, assign2, true);  // Olivia -> ENG Lab (late)
    Submission *sub3 = new Submission(s7, assign3, false); // James -> Math Quiz (on time)
    Submission *sub4 = new Submission(s8, assign4, true);  // Sophia -> Physics Report (late)

    submissions.push_back(sub1);
    submissions.push_back(sub2);
    submissions.push_back(sub3);
    submissions.push_back(sub4);

    assign1->addSubmission(sub1);
    assign2->addSubmission(sub2);
    assign3->addSubmission(sub3);
    assign4->addSubmission(sub4);



    Submission* s1sub = new Submission(s1, assign1, false);
    s1sub->addFile("01-10-25_iter1_alice.cpp");
    submissions.push_back(s1sub);
    assign1->addSubmission(s1sub);
    s1->submitAssignment(s1sub);

    
    Submission* s2sub = new Submission(s2, assign1, true);
    s2sub->addFile("01-10-25_iter1_bob.cpp");
    submissions.push_back(s2sub);
    assign1->addSubmission(s2sub);
    s2sub->addFile("01-10-25_iter1_bob.cpp");
    submissions.push_back(s2sub);
    assign1->addSubmission(s2sub);
    s2->submitAssignment(s2sub);

    
    s1sub->addFile("01-10-25_iter2_alice.cpp");
    s1sub->setLate(true); // mark late now

    cout << "Starting Application..." << endl;
    Signup();
    cout << "Thanks for using the application!" << endl;
    return 0;
}

void Signup()
{
    int choice;
    cout << "\nWelcome to the Student Club Management System!" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;

    cout << "----------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    cout << "----------------------------" << endl;

    if (choice == 1)
    {
        int enrollment;
        string password;
        cout << "Enter Enrollment Number: ";
        std::cin >> enrollment;
        cout << "Enter Password: ";
        std::cin >> password;
        bool loggedIn = false;
       for (int i = 0; i < students.size(); i++) {
                if (students[i]->login(enrollment, password)) {
                    cout << "Login Successful!" << endl;
                    HomePage(students[i]);
                    loggedIn = true;
                    break;
                }
            }
            if (!loggedIn) {
                cout << "Login Failed! Try again." << endl;
                Signup();
                return;
            }
        return;
    }
    else if (choice == 2)
    {
        try
        {
            string name, mail, password;
            int enrollment, gradYear;
            float cgpa;
            cout << "Enter Name: ";
            cin >> name;
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
            Student *newStudent = new Student(name, enrollment, mail, gradYear, cgpa, password);
            students.push_back(newStudent);
            cout << "Registration Successful!" << endl;
            HomePage(newStudent);
            return;
        }
        catch (exception &e)
        {
            cout << "Registration Failed! Please try again." << endl;
            Signup();
            return;
        }
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "Invalid choice! Please try again." << endl;
        Signup();
        return;
    }
}
void displayInfo(Student *currentStudent)
{
    if (currentStudent == nullptr)
    {
        cout << "No student logged in!" << endl;
        return;
    }
    cout << "Name: " << currentStudent->getName() << endl;
    cout << "Enrollment Number: " << currentStudent->getEnrollment() << endl;
    cout << "Mail: " << currentStudent->getMail() << endl;
    cout << "Graduation Year: " << currentStudent->getGraduationYear() << endl;
    cout << "CGPA: " << currentStudent->getCGPA() << endl;
    cout << "Clubs Joined: ";
    Vector<Club *> StudentClubs = currentStudent->ViewClubs();
    if (StudentClubs.empty())
    {
        cout << "None" << endl;
    }
    cout << "ReEnter New Information?:(y to update / n to return to main menu)" << endl;
    char ch;
    std::cin >> ch;
    if (ch == 'y')
    {
        string name, mail, password;
        int gradYear;
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

void HomePage(Student *currentStudent)
{
    int choice;
    cout << "\nWelcome to the Student Club Management System!" << endl;
    cout << "----------------------------" << endl;
    cout << "1. My Information" << endl;
    cout << "2. Search Student" << endl;
    cout << "3. CLub Info" << endl;
    cout << "4. Club Requests" << endl;
    cout << "5. My Clubs" << endl;
    cout << "6. Logout" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    cout << "----------------------------\n"
         << endl;
    switch (choice)
    {
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

void SearchStudent(Student *currentStudent)
{
    if (currentStudent == nullptr)
    {
        cout << "No student logged in!" << endl;
        return;
    }
    int enrollment;
    cout << "Main menu: 0 \n All Students -1 \n Enter Enrollment Number to search/choice: ";
    std::cin >> enrollment;
    if (enrollment == 0)
        return;
    if (enrollment == -1)
    {
        cout << "All Students: " << endl;
        for (int i = 0; i < students.size(); i++)
        {
            cout << i + 1 << ". " << students[i]->getName() << " (Enrollment: " << students[i]->getEnrollment() << ")" << endl;
        }
        return;
    }
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getEnrollment() == enrollment)
        {
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

void ClubInfo(Student *currentStudent)
{
    if (currentStudent == nullptr)
    {
        cout << "No student logged in!" << endl;
        return;
    }
    int clubId;
    cout << "Main menu: 0 \n All Clubs -1 \n Enter Club ID to search/choice: ";
    std::cin >> clubId;
    if (clubId == 0)
        return;
    if (clubId == -1)
    {
        cout << "All Clubs: " << endl;
        for (int i = 0; i < clubs.size(); i++)
        {
            cout << i + 1 << ". " << clubs[i]->getName() << " (Club ID: " << clubs[i]->getClubId() << " , Admin: " << clubs[i]->getAdmin()->getStudent()->getName() << ")" << endl;
        }
        int select = -1;
        cout << "Enter the club number to view details or 0 to return: ";
        std::cin >> select;
        if (select == 0)
            return;
        if (select < 1 || select > clubs.size())
        {
            cout << "Invalid choice!" << endl;
            return;
        }
        clubs[select - 1]->display();
        return;
    }
    for (int i = 0; i < clubs.size(); i++)
    {
        if (clubs[i]->getClubId() == clubId)
        {
            cout << "Club Found!" << endl;
            clubs[i]->display();
            return;
        }
    }
    cout << "Club Not Found!" << endl;
    return;
}

void ClubRequests(Student *currentStudent)
{
    if (currentStudent == nullptr)
    {
        cout << "No student logged in!" << endl;
        return;
    }
    Vector<Club *> requests = currentStudent->getClubRequest();
    if (requests.empty())
    {
        cout << "No club requests!" << endl;
        return;
    }
    cout << "Club Requests: " << endl;
    for (int i = 0; i < requests.size(); i++)
    {
        cout << i + 1 << ". " << requests[i]->getName() << " (Club ID: " << requests[i]->getClubId() << ")" << endl;
    }
    int choice;
    cout << "Enter the club number to process or 0 to return: ";
    std::cin >> choice;
    if (choice == 0)
        return;
    if (choice < 1 || choice > requests.size())
    {
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "1. Join Club\n2. Discard Request\nEnter your option: ";
    int action;
    std::cin >> action;
    if (action == 1)
    {
        currentStudent->AddClub(requests[choice - 1]);
        requests[choice - 1]->getAdmin()->setNotifications(currentStudent->getName() + " has joined the club " + requests[choice - 1]->getName() + "."); // notify the admin here
        requests[choice - 1]->addMember(currentStudent);
        cout << "Joined club successfully!" << endl;
        currentStudent->removeClubRequest(requests[choice - 1]);
    }
    else if (action == 2)
    {
        // Remove the request from the student's clubRequest vector
        currentStudent->removeClubRequest(requests[choice - 1]);
        requests[choice - 1]->getAdmin()->setNotifications(currentStudent->getName() + "'s request to join the club " + requests[choice - 1]->getName() + " has been discarded."); // notify the admin here
        cout << "Request discarded." << endl;
    }
    else
    {
        cout << "Invalid option!" << endl;
    }
    return;
}

void viewNotifications(Admin *admin)
{
    Vector<string> notes = admin->getNotifications();
    if (notes.empty())
    {
        cout << "No notifications." << endl;
    }
    else
    {
        cout << "Notifications:" << endl;
        for (int i = 0; i < notes.size(); ++i)
        {
            cout << i + 1 << ". " << notes[i] << endl;
        }
    }
    cout << "Options:\n";
    cout << "1. Delete all notifications\n";
    cout << "2. Delete particular notifications\n";
    cout << "3. Return\n";
    cout << "Enter your choice: ";
    int notifChoice;
    std::cin >> notifChoice;
    if (notifChoice == 1)
    {
        admin->removeallnotifications();
        cout << "All notifications deleted." << endl;
        return;
    }
    else if (notifChoice == 2)
    {
        cout << "Enter the notification numbers to delete separated by spaces (end with 0): ";
        Vector<int> delIndices;
        int delIndex;
        while (std::cin >> delIndex && delIndex != 0)
        {
            if (delIndex > 0 && delIndex <= notes.size())
            {
                delIndices.push_back(delIndex - 1);
            }
            else
            {
                cout << "Invalid notification number: " << delIndex << endl;
            }
        }
        std::cin.clear();
        for (int i = delIndices.size() - 1; i >= 0; --i)
        {
            int idx = delIndices[i];
            if (idx >= 0 && idx < notes.size())
            {
                admin->removeNotification(notes[idx]);
            }
        }
        if (!delIndices.empty())
            cout << "Selected notifications deleted." << endl;
        else
            cout << "No valid notifications selected for deletion." << endl;
        return;
    }
    else if (notifChoice == 3)
    {
        return;
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }
}

void MyClubs(Student *currentStudent)
{
    Vector<Club *> studentClubs = currentStudent->ViewClubs(false);
    if (studentClubs.empty())
    {
        cout << "No clubs joined!" << endl;
        return;
    }
    cout << "Joined Clubs: " << endl;
    for (int i = 0; i < studentClubs.size(); i++)
    {
        cout << i + 1 << ". " << studentClubs[i]->getName() << " (Club ID: " << studentClubs[i]->getClubId() << ") , Admin : " << studentClubs[i]->getAdmin()->getStudent()->getName() << endl;
    }
    int choice;
    cout << "Enter the club number to view details or 0 to return: ";
    std::cin >> choice;
    if (choice == 0)
        return;
    if (choice < 1 || choice > studentClubs.size())
    {
        cout << "Invalid choice!" << endl;
        MyClubs(currentStudent);
        return;
    }
    ClubSelected(currentStudent, studentClubs[choice - 1]);
    return;
}

void ClubSelected(Student *currentStudent, Club *selectedClub)
{
    if (currentStudent == nullptr)
    {
        cout << "No student logged in!" << endl;
        return;
    }
    if (selectedClub == nullptr)
    {
        cout << "No club selected!" << endl;
        return;
    }
    string choice;

    cout << "\n===== " << selectedClub->getName() << selectedClub->getClubId() << " =====\n ===== " << selectedClub->getAdmin()->getStudent()->getName() << " =====\n";
    cout << "1. View Members\n";
    cout << "2. View Admin\n";
    cout << "3. View Assignments\n";
    cout << "4. My Assignments\n";
    cout << "5. My Submissions\n";
    cout << "6. Back to Main Menu\n";

    if (selectedClub->getAdmin()->getStudent()->getEnrollment() == currentStudent->getEnrollment())
    {
        cout << "===== Admin Tools =====\n";
        cout << "7. View Notifications:\n";
        cout << "8. Manage Members\n";
        cout << "   a) Add Member          (8a)\n";
        cout << "   b) Remove Member       (8b)\n";
        cout << "   c) Assign Admin        (8c)\n";
        cout << "   d) Leave Club           (8d)\n";
        cout << "9. Manage Assignments\n";
        cout << "   a) Create Assignment   (9a)\n";
        cout << "   b) Edit Assignment     (9b)\n";
        cout << "   c) Delete Assignment   (9c)\n";
        cout << "   d) View Submissions    (9d)\n";
    }
    else
    {
        cout << "===== Admin Tools =====\n";
        cout << "10.Leave Club\n";
        cout << "the only admin power you have is to leave the club hahaha" << endl;
    }
    cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();
    if (choice == "1")
    {   //view memebrs
        selectedClub->getMembers();
        for (int i = 0; i < selectedClub->getMembers().size(); i++)
        {
            cout << i + 1 << ". " << selectedClub->getMembers()[i]->getName() << " (ID: " << selectedClub->getMembers()[i]->getEnrollment() << ")" << endl;
        }
        int choice;
        cout << "Enter the member number to view details or 0 to return: ";
        std::cin >> choice;
        if (choice == 0)
        {
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        if (choice < 1 || choice > selectedClub->getMembers().size())
        {
            cout << "Invalid choice!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        Student *member = selectedClub->getMembers()[choice - 1];
        cout << "Member Details:" << endl;

        cout << "Name: " << member->getName() << endl;
        cout << "Admin: " << (member->getEnrollment() == selectedClub->getAdmin()->getStudent()->getEnrollment() ? "Yes" : "No") << endl;
        cout << "Enrollment Number: " << member->getEnrollment() << endl;
        cout << "Mail: " << member->getMail() << endl;
        cout << "Graduation Year: " << member->getGraduationYear() << endl;
        cout << "CGPA: " << member->getCGPA() << endl;
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "2")
    {   //view admin
        Admin *admin = selectedClub->getAdmin();
        if (admin == nullptr)
        {
            cout << "No admin assigned!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        Student *adminStudent = admin->getStudent();
        cout << "Admin Details:" << endl;
        cout << "Name: " << adminStudent->getName() << endl;
        cout << "Enrollment Number: " << adminStudent->getEnrollment() << endl;
        cout << "Mail: " << adminStudent->getMail() << endl;
        cout << "Graduation Year: " << adminStudent->getGraduationYear() << endl;
        cout << "CGPA: " << adminStudent->getCGPA() << endl;
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "3")
    {   //view assignments
        Vector<Assignment*> assignments = selectedClub->getAssignments();
        if(assignments.empty()){
            cout << "No assignments in this club!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        for (int i = 0; i < assignments.size(); i++){
            cout << i + 1 << ". " << assignments[i]->getTitle() << endl;
        }
        viewAssignmentDetails(selectedClub,currentStudent,assignments);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "4")
    {   //view my assignments
        MyAssignments(currentStudent, selectedClub);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "5")
    {   //view my submissions
        Vector<Submission*> mySubmissions = currentStudent->getSubmissions();
        for (int i = 0; i < mySubmissions.size(); i++){
            if(mySubmissions[i]->getAssignment()->getIssueingClub()->getClubId() != selectedClub->getClubId()) continue;
                cout << i + 1 << ". " << mySubmissions[i]->getAssignment()->getTitle() << endl;
                mySubmissions[i]->display();

        }
        if(mySubmissions.empty()){
            cout << "No submissions made by you in this club!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        // viewSubmissionDetails(selectedClub,currentStudent,mySubmissions);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "6")
    {   //back to main menu
        return;
    }
    else if (choice == "7")
    {   //view notifications
        viewNotifications(selectedClub->getAdmin());
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "8a")
    {   //add member
        cout << "Enter Enrollment of student to add: ";
        int enroll;
        std::cin >> enroll;
        bool found = false;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i]->getEnrollment() == enroll)
            {
                selectedClub->getAdmin()->addMember(students[i]);
                found = true;
                break;
            }
        }
        if (found)
        {
            // Member added successfully
            cout << "Student will be added automatically when he accepts the invitation." << endl;
        }
        else
        {
            cout << "Student not found." << endl;
        }
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "8b")
    {   //remove member
        cout << "Enter Enrollment of student to remove: ";
        int enroll;
        std::cin >> enroll;
        selectedClub->getAdmin()->removeMember(enroll);
        cout << "Student is removed from the Club." << endl;
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "8c")
    {   //assign new admin
        cout << "Enter Enrollment of student to assign as new Admin: ";
        int enroll;
        std::cin >> enroll;
        cout << "Enter joining date (YYYY-MM-DD): ";
        string date;
        std::cin >> date;
        bool found = false;
        if (enroll == selectedClub->getAdmin()->getStudent()->getEnrollment())
        {
            cout << "You are already the admin." << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        Admin *newAdmin = nullptr;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i]->getEnrollment() == enroll)
            {
                newAdmin = new Admin(students[i], date);
                selectedClub->getAdmin()->setNewAdmin(newAdmin);
                found = true;
                cout << students[i]->getName() << " is now the new admin of the club." << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "No student found with enrollment " << enroll << endl;
        }
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "8d")
    {   //leave club
        if (selectedClub->getAdmin()->getStudent()->getEnrollment() == currentStudent->getEnrollment())
        {
            cout << "Admin cannot leave the club. Please assign a new admin before leaving." << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        bool left = currentStudent->leaveClub(selectedClub);
        if (left)
        {
            selectedClub->getAdmin()->setNotifications(currentStudent->getName() + " has left the club " + selectedClub->getName() + "."); // notify the admin here
            selectedClub->removeMember(currentStudent->getEnrollment());
            cout << "You have left the club." << endl;
        }
        else
        {
            cout << "Error leaving the club." << endl;
        }
        return;
    }
    else if (choice == "9a"){
        //create assignment
        string title, description, iteration;
        cout << "Enter Assignment Title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        cout << "Enter Assignment Description: ";
        std::getline(std::cin, description);
        // cout << "Enter Assignment Iteration: ";
        // std::getline(std::cin, iteration);
        string finalDate;
        cout << "Enter Final Date (YYYY-MM-DD): ";
        std::cin >> finalDate;
        Assignment* newAssignment = new Assignment(title, description, selectedClub->getAdmin(), selectedClub, finalDate);
        assignments.push_back(newAssignment);
        selectedClub->addAssignment(newAssignment);
        cout << "Assignment created successfully!" << endl;
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "9b"){
        //edit assignment
        Vector<Assignment*> assignments = selectedClub->getAssignments();
        if(assignments.empty()){
            cout << "No assignments in this club!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        editAssignmentDetails(selectedClub,currentStudent,assignments);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else if (choice == "9c")
    {
        //delete assignment
        Vector<Assignment*> assignments = selectedClub->getAssignments();
        if(assignments.empty()){
            cout << "No assignments in this club!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        deleteAssignment(selectedClub,currentStudent,assignments);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    
    else if (choice == "9d")
    {
        //view submissions
        Vector<Assignment*> assignments = selectedClub->getAssignments();
        // List all assignments in the club
        if(assignments.empty()){
            cout << "No assignments in this club!" << endl;
            ClubSelected(currentStudent, selectedClub);
            return;
        }
        viewSubmissionDetails(selectedClub,currentStudent,assignments);
        ClubSelected(currentStudent, selectedClub);
        return;
    }
    else
    {
        cout << "Invalid choice! Please try again." << endl;
        ClubSelected(currentStudent, selectedClub);
        return;
    }
}

void deleteAssignment(Club* selectedClub, Student* currentStudent, Vector<Assignment*> assignments) {
    // Display header with formatted output
    cout << "\n" << string(50, '=') << endl;
    cout << "         DELETE ASSIGNMENT" << endl;
    cout << string(50, '=') << endl << endl;
    
    // Display all available assignments in a numbered list
    cout << "Choose an assignment to delete:" << endl;
    cout << string(50, '-') << endl;
    for (int i = 0; i < assignments.size(); i++) {
        cout << "  " << (i + 1) << ". " << assignments[i]->getTitle() << endl;
    }
    cout << string(50, '-') << endl;
    cout << "Enter the assignment number to delete or 0 to return: ";
    
    // Get user's assignment choice
    int assignChoice;
    std::cin >> assignChoice;
    
    // Handle return to previous menu
    if (assignChoice == 0) {
        cout << "\nReturning to previous menu..." << endl;
        return;
    }
    else {
        // Validate assignment selection
        if (assignChoice < 1 || assignChoice > assignments.size()) {
            cout << "\n[ERROR] Invalid choice! Please select between 1 and " 
                 << assignments.size() << "." << endl;
            // Recursively call to retry
            deleteAssignment(selectedClub, currentStudent, assignments);
            return;
        }
        
        // Remove the selected assignment from the club's list
        selectedClub->removeAssignment(assignChoice - 1);
        cout << "Assignment deleted successfully!" << endl;
    }
}


void viewSubmissionDetails(Club* selectedClub, Student* currentStudent, Vector<Assignment*> assignments) {
    // Display header with formatted output
        for (int i = 0; i < assignments.size(); i++) {
            cout << i + 1 << ". " << assignments[i]->getTitle() << endl;
        }
        cout << "Enter the assignment number to view student submissions or 0 to return: ";
        int assignChoice;
        std::cin >> assignChoice;
        if (assignChoice == 0) {
            return;
        }
        if (assignChoice < 1 || assignChoice > assignments.size()) {
            cout << "Invalid choice!" << endl;
            viewSubmissionDetails(selectedClub, currentStudent, assignments);
            return;
        }
        Assignment* selectedAssignment = assignments[assignChoice - 1];
        Vector<Student*> assignedStudents = selectedAssignment->getStudents();
        if (assignedStudents.empty()) {
            cout << "No students assigned to this assignment!" << endl;
            viewSubmissionDetails(selectedClub, currentStudent, assignments);
            return;
        }
        cout << "Students assigned to this assignment:" << endl;
        for (int i = 0; i < assignedStudents.size(); i++) {
            cout << i + 1 << ". " << assignedStudents[i]->getName() << " (Enrollment: " << assignedStudents[i]->getEnrollment() << ")" << endl;
        }
        cout << "Enter the student number to view their submissions or 0 to return: ";
        int studentChoice;
        std::cin >> studentChoice;
        if (studentChoice == 0) {
            return;
        }
        if (studentChoice < 1 || studentChoice > assignedStudents.size()) {
            cout << "Invalid choice!" << endl;
            viewSubmissionDetails(selectedClub, currentStudent, assignments);
            return;
        }
        Student* selectedStudent = assignedStudents[studentChoice - 1];
        Vector<Submission*> allSubs = selectedAssignment->getSubmissions();
        Submission* studentSubs = nullptr;
        for (int i = 0; i < allSubs.size(); i++) {
            if (allSubs[i]->getStudent()->getEnrollment() == selectedStudent->getEnrollment()) {
            studentSubs = allSubs[i];
            }
        }
        if (studentSubs == nullptr) {
            cout << "No submissions found for this student!" << endl;
            viewSubmissionDetails(selectedClub, currentStudent, assignments);
            return;
        } 
        studentSubs->display();
        reviewSubmission(studentSubs, selectedStudent);
        viewSubmissionDetails(selectedClub, currentStudent, assignments);
        return;
}

void reviewSubmission(Submission* selectedSubmission, Student* selectedStudent) {
        cout<<"Enter choices:\n0. Return\n1. Add Review Comments\n2. Add Score\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            cout << "\nEnter your review comments: ";
            std::cin.ignore(); // Clear input buffer
            string comments;
            std::getline(std::cin, comments);
            selectedSubmission->setReview(comments);
            cout << "Review comments added successfully!" << endl;
            reviewSubmission(selectedSubmission, selectedStudent);
            return;
        }
        else if (choice == 2) {
            cout << "\nEnter score (0-100): ";
            int score;
            std::cin >> score;
            if(score < 0 || score > 100) {
                cout << "Invalid score! Please enter a score between 0 and 100." << endl;
                reviewSubmission(selectedSubmission, selectedStudent);
                return;
            }
            selectedSubmission->setScore(score);
            cout << "Score added successfully!" << endl;
            reviewSubmission(selectedSubmission, selectedStudent);
            return;
        }
        else if (choice == 0) {
            cout << "Returning to previous menu..." << endl;
            return;
        }
        else {
            cout << "Invalid choice!" << endl;
            reviewSubmission(selectedSubmission, selectedStudent);
            return;
        }   
}

// Function to edit assignment details for a selected club
// Parameters:
//   - selectedClub: pointer to the club whose assignments are being edited
//   - currentStudent: pointer to the student performing the edit
//   - assignments: vector of assignment pointers to choose from
void editAssignmentDetails(Club* selectedClub, Student* currentStudent, Vector<Assignment*> assignments) {
    // Display header with formatted output
    cout << "\n" << string(50, '=') << endl;
    cout << "         EDIT ASSIGNMENT DETAILS" << endl;
    cout << string(50, '=') << endl << endl;
    
    // Display all available assignments in a numbered list
    cout << "Choose an assignment to edit:" << endl;
    cout << string(50, '-') << endl;
    for (int i = 0; i < assignments.size(); i++) {
        cout << "  " << (i + 1) << ". " << assignments[i]->getTitle() << endl;
    }
    cout << string(50, '-') << endl;
    cout << "Enter the assignment number to edit or 0 to return: ";
    
    // Get user's assignment choice
    int assignChoice;
    std::cin >> assignChoice;
    
    // Handle return to previous menu
    if (assignChoice == 0) {
        cout << "\nReturning to previous menu..." << endl;
        return;
    }
    else {
        // Validate assignment selection
        if (assignChoice < 1 || assignChoice > assignments.size()) {
            cout << "\n[ERROR] Invalid choice! Please select between 1 and " 
                 << assignments.size() << "." << endl;
            // Recursively call to retry
            editAssignmentDetails(selectedClub, currentStudent, assignments);
            return;
        }
        
        // Get the selected assignment
        Assignment* selectedAssignment = assignments[assignChoice - 1];
        
        // Display current assignment details
        cout << "\n" << string(50, '=') << endl;
        cout << "Current Assignment Details:" << endl;
        cout << string(50, '-') << endl;
        cout << "  Title: " << selectedAssignment->getTitle() << endl;
        cout << "  Description: " << selectedAssignment->getDescription() << endl;
        cout << "  Final Date: " << selectedAssignment->getFinalDate() << endl;
        cout << string(50, '=') << endl << endl;
        
        // === UPDATE TITLE ===
        string newTitle, newDescription;
        cout << "Enter new title (or press enter to keep current): ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, newTitle);
        if (!newTitle.empty()) {
            selectedAssignment->setTitle(newTitle);
            cout << "  ✓ Title updated!" << endl;
        } else {
            cout << "  → Title unchanged." << endl;
        }
        
        // === UPDATE DESCRIPTION ===
        cout << "\nEnter new description (or press enter to keep current): ";
        std::getline(std::cin, newDescription);
        if (!newDescription.empty()) {
            selectedAssignment->setDescription(newDescription);
            cout << "  ✓ Description updated!" << endl;
        } else {
            cout << "  → Description unchanged." << endl;
        }
        
        // === UPDATE FINAL DATE ===
        cout << "\nEnter new final date (YYYY-MM-DD) (or press enter to keep current): ";
        string newFinalDate;
        std::cin >> newFinalDate;
        if (!newFinalDate.empty()) {
            selectedAssignment->setFinalDate(newFinalDate);
            cout << "  ✓ Final date updated!" << endl;
        } else {
            cout << "  → Final date unchanged." << endl;
        }
        
        // === ADD STUDENTS TO ASSIGNMENT ===
        cout << "\n" << string(50, '-') << endl;
        cout << "Add students to assignment? (y/n): ";
        char ch;
        std::cin >> ch;
        
        if (ch == 'y' || ch == 'Y') {
            cout << "Enter Enrollment Numbers of students to add separated by spaces: ";
            Vector<int> enrollments;
            int enroll;
            
            // Read all enrollment numbers from input
            while (std::cin >> enroll) {
                enrollments.push_back(enroll);
                if (std::cin.peek() == '\n') break; // Break on newline
            }
            std::cin.clear();
            
            // Process each enrollment number
            int addedCount = 0;
            for (int i = 0; i < enrollments.size(); i++) {
                bool found = false;
                
                // Search for student with matching enrollment
                for (int j = 0; j < students.size(); j++) {
                    if (students[j]->getEnrollment() == enrollments[i]) {
                        selectedAssignment->addStudent(students[j]);
                        cout << "  ✓ Added student: " << enrollments[i] << endl;
                        addedCount++;
                        found = true;
                        break;
                    }
                }
                
                // Warn if student not found
                if (!found) {
                    cout << "  ✗ No student found with enrollment " << enrollments[i] << endl;
                }
            }
            cout << "Total students added: " << addedCount << endl;
        } 
        else if (ch == 'n' || ch == 'N') {
            cout << "No students added." << endl;
        } 
        else {
            cout << "Invalid choice! No students added." << endl;
        }
        
        // === REMOVE STUDENTS FROM ASSIGNMENT ===
        cout << "\n" << string(50, '-') << endl;
        cout << "Remove students from assignment? (y/n): ";
        std::cin >> ch;
        
        if (ch == 'y' || ch == 'Y') {
            cout << "Enter Enrollment Numbers of students to remove separated by spaces: ";
            Vector<int> enrollments;
            int enroll;
            
            // Read all enrollment numbers from input
            while (std::cin >> enroll) {
                enrollments.push_back(enroll);
                if (std::cin.peek() == '\n') break; // Break on newline
            }
            std::cin.clear();
            
            // Remove each student by enrollment
            for (int i = 0; i < enrollments.size(); i++) {
                selectedAssignment->removeStudent(enrollments[i]);
                cout << "  ✓ Removed student: " << enrollments[i] << endl;
            }
            cout << "Total students removed: " << enrollments.size() << endl;
        }
        else if (ch == 'n' || ch == 'N') {
            cout << "No students removed." << endl;
        }
        else {
            cout << "Invalid choice! No students removed." << endl;
        }
        
        // === DISPLAY UPDATED ASSIGNMENT DETAILS ===
        cout << "\n" << string(50, '=') << endl;
        cout << "Assignment updated successfully!" << endl;
        cout << string(50, '=') << endl;
        cout << "Assignment ID: " << selectedAssignment->getAssignmentId() << endl;
        cout << "Title: " << selectedAssignment->getTitle() << endl;
        cout << "Description: " << selectedAssignment->getDescription() << endl;
        cout << "Final Date: " << selectedAssignment->getFinalDate() << endl;
        cout << "Number of Students Assigned: " << selectedAssignment->getStudents().size() << endl;
        cout << "Issuing Club ID: " << selectedAssignment->getIssueingClub()->getClubId() << endl;
        cout << string(50, '=') << endl << endl;
    }
    
    // Recursively call to allow editing another assignment
    editAssignmentDetails(selectedClub, currentStudent, assignments);
    return;
}



    void viewAssignmentDetails(Club* selectedClub,Student* currentStudent,Vector<Assignment*> assignments){
        cout << "Enter the assignment number to view details or 0 to return: ";
        int assignChoice;
        std::cin >> assignChoice;
        if (assignChoice == 0){
            return;
        }
        else{
             if (assignChoice < 1 || assignChoice > assignments.size()){
                cout << "Invalid choice!" << endl;
                viewAssignmentDetails(selectedClub,currentStudent,assignments);
                return;
            }
            Assignment* selectedAssignment = assignments[assignChoice - 1];
            selectedAssignment->details();
        }
        viewAssignmentDetails(selectedClub,currentStudent,assignments);
        return;
    }

void viewSubmissionDetails(Club* selectedClub,Student* currentStudent,Vector<Submission*> submissions){
        cout << "Enter the submission number to view details or 0 to return: ";
        int submitChoice;
        std::cin >> submitChoice;
        if (submitChoice == 0){
            return;
        }
        else{
             if (submitChoice < 1 || submitChoice > submissions.size()){
                cout << "Invalid choice!" << endl;
                viewSubmissionDetails(selectedClub,currentStudent,submissions);
                return;
            }
            Submission* selectedSubmission = submissions[submitChoice - 1];
            selectedSubmission->display();
        }
        viewSubmissionDetails(selectedClub,currentStudent,submissions);
        return;
    }

void MyAssignments(Student *currentStudent, Club *selectedClub)
{
    if (currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    if(selectedClub == nullptr){
        cout << "No club selected!" << endl;
        return;
    }
    Vector<Assignment*> assignments = selectedClub->getAssignments();
    Vector<Assignment *> myAssignments;
    for (int i = 0; i < assignments.size(); i++){
        Vector<Student*> assignedStudents = assignments[i]->getStudents();
        for (int j = 0; j < assignedStudents.size(); j++){
            if (assignedStudents[j]->getEnrollment() == currentStudent->getEnrollment()){
                myAssignments.push_back(assignments[i]);
                break;
            }
        }
    }
    if (myAssignments.empty())
    {
        cout << "No assignments assigned to you!" << endl;
        return;
    }
    cout << "My Assignments: " << endl;
    for (int i = 0; i < myAssignments.size(); i++)
    {
        cout << i + 1 << ". " << myAssignments[i]->getTitle() << endl;
    }
    cout << "Enter the assignment number to view details or 0 to return: ";
    int choice;
    std::cin >> choice;
    if (choice == 0){ return;}
    else{
        if (choice < 1 || choice > myAssignments.size()){
            cout << "Invalid choice!" << endl;
            MyAssignments(currentStudent, selectedClub);
            return;
        }
        Assignment* selectedAssignment = myAssignments[choice - 1];
        AssignmentSelected(currentStudent, selectedAssignment, selectedClub);
    }
    return;
}

void AssignmentSelected(Student* currentStudent, Assignment* selectedAssignment, Club* selectedClub){
    if (currentStudent == nullptr){
        cout << "No student logged in!" << endl;
        return;
    }
    if(selectedClub == nullptr){
        cout << "No club selected!" << endl;
        return;
    }
    if(selectedAssignment == nullptr){
        cout << "No assignment selected!" << endl;
        return;
    }
    string choice;
    Submission* existingSubmission = nullptr;
    Vector<Submission*> submissions = selectedAssignment->getSubmissions();
    for(int i = 0; i < submissions.size(); i++){
        if(submissions[i]->getStudent()->getEnrollment() == currentStudent->getEnrollment()){
            existingSubmission = submissions[i];
            break;
        }  
    }
    cout << "\n===== " << selectedAssignment->getTitle() << " =====\n";
    cout << "1. View Details\n";
    cout << "2. My Assignment Status\n";
    cout << "3. All my Submissions\n";
    cout << "4. Submit Assignment\n";
    cout << "5. Back to My Assignments\n";

    cout << "Enter choice: ";
    std::cin >> choice;
    std::cin.ignore();
    if (choice == "1"){
        selectedAssignment->details();
        AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        return;

    }
    else if (choice == "2")
    {
        if (existingSubmission == nullptr){
            cout << "You have not submitted this assignment yet." << endl;
        }
        else{
            existingSubmission->display();
        }
        AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        return;
    }
    else if (choice == "3"){
        // Vector<Submission*> mySubmissions = currentStudent->getSubmissions();
        // Vector<Submission*> filteredSubmissions;
        // for(int i = 0; i < mySubmissions.size(); i++){
        //     if(mySubmissions[i]->getAssignment()->getTitle() == selectedAssignment->getTitle()){
        //         filteredSubmissions.push_back(mySubmissions[i]);
        //     }
        // }
        // if (filteredSubmissions.empty()) {
        //     cout << "No submissions found!" << endl;
        //     AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        //     return;
        // } else {
        //     cout << "My Submissions: " << endl;
        //     for (int i = 0; i < filteredSubmissions.size(); i++) {
        //         cout << i + 1 << ". " << filteredSubmissions[i]->getAssignment()->getTitle() << endl;
        //     }
        // }
        // viewSubmissionDetails(selectedClub,currentStudent,filteredSubmissions);
        // AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        // return;
        if (existingSubmission == nullptr){
            cout << "You have not submitted this assignment yet." << endl;
        }
        else{
            Vector<string> files = existingSubmission->getSubmittedFiles();
            for(int i = 0; i < files.size(); i++){
                size_t found = files[i].find('_');
                if (found != string::npos) {
                    string date = files[i].substr(0, found);
                    string filename = files[i].substr(found+1);
                    cout << i + 1 << ". Date: " << date << ", Filename: " << filename << endl;
                } else {
                    cout << i + 1 << ". " << files[i] << endl;
                }
            }
        }
    }
    else if (choice == "4")
    {
        cout<<"Enter your submission file name : "<<endl;
        string filename;
        std::cin >> filename;
        cout<<"Enter your submission date : "<<endl;
        string date;
        std::cin >> date;
        string iteration = (existingSubmission->getSubmittedFiles().size() == 0) ? "Iteration 1" : "Iteration " + to_string(existingSubmission->getSubmittedFiles().size() + 1);

        string fullFilename = date + "_" + iteration + "_" + filename;
        existingSubmission->addFile(fullFilename);
        cout << "Assignment submitted successfully!" << endl;
        AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        return;
    }
    else if (choice == "5"){
        return;
    }
    else
    {
        cout << "Invalid choice! Please try again." << endl;
        AssignmentSelected(currentStudent,selectedAssignment,selectedClub);
        return;
    }  
    return; 
}








