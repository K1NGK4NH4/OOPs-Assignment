// void SelectedClubInterface(Student* currentStudent, Club* club){
//     if (currentStudent == nullptr) {
//         cout << "No student logged in!" << endl;
//         return;
//     }
//     if (club == nullptr) {
//         cout << "No club selected!" << endl;
//         return;
//     }
//     cout << "Welcome to the " << club->getName() << " club interface." << endl;
//     int choice;
//     do {
//         cout << "\n--- " << club->getName() << " Club Menu ---" << endl;
//         cout << "1. View Members" << endl;
//         cout << "2. View Admin" << endl;
//         cout << "3. View Assignments" << endl;
//         cout << "4. My Submissions" << endl;
//         cout << "5. My Assignments" << endl;
//         cout << "6. Admin Work" << endl;
//         cout << "7. Return to Main Menu" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         cin.ignore();
//         switch (choice) {
//             case 1: { // View Members
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
//             case 2: { // View Admin
//                 Admin* admin = club->getAdmin();
//                 if (admin) {
//                     Student* adminStudent = admin->getStudent();
//                     cout << "Admin: " << adminStudent->getName() << " (Enrollment: " << adminStudent->getEnrollment() << ")" << endl;
//                 } else {
//                     cout << "No admin assigned to this club." << endl;
//                 }
//                 break;
//             }
//             case 3: { // View Assignments
//                 Vector<Assignment*> clubAssignments = club->getAssignments();
//                 if (clubAssignments.empty()) {
//                     cout << "No assignments for this club." << endl;
//                 } else {
//                     cout << "Assignments:" << endl;
//                     for (int i = 0; i < clubAssignments.size(); ++i) {
//                         cout << i + 1 << ". " << clubAssignments[i]->getTitle() << endl;
//                     }
//                 }
//                 break;
//             }
//             case 4: { // My Submissions
//                 //Display Submissions 
//                 cout << "Yet to implement" << endl;
//             }
//             case 5: { // My Assignments
//                 //Yet to implement
//                 cout << "Yet to implement" << endl;
//             }
//             case 6: { // Admin Work
//                 Admin* admin = club->getAdmin();
//                 if (admin && admin->getStudent() == currentStudent) {
//                     AdminInterface(admin);
//                 } else {
//                     cout << "Access denied: You are not the admin of this club." << endl;
//                 }
//                 break;
//             }
//             case 7:
//                 cout << "Returning to main menu..." << endl;
//                 break;
//             default:
//                 cout << "Invalid choice!" << endl;
//         }
//     } while (choice != 7);

//     // You can add more club-specific actions here if needed
// }

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


// Student *s1 = new Student("John Doe", 123456, "johndoe@example.com", 2022, 3.5, "123");

//     Student *s2 = new Student("Jennifer", 654321, "Feeffer@example.com", 2023, 3.8, "321");
//     Admin *a1 = new Admin(s1, "2021-01-01");
//     Admin *a2 = new Admin(s2, "2020-05-01");
//     Club *c1 = new Club("Computer Science Club", "csclub@example.com", a1);
//     Club *c2 = new Club("Engineering Club", "engclub@example.com", a2);
//     a1->setClub(c1);
//     a2->setClub(c2);

//     clubs.push_back(c1);
//     clubs.push_back(c2);
//     students.push_back(s1);
//     students.push_back(s2);
//     admins.push_back(a1);
//     admins.push_back(a2);
//     // Test: Student s2 requests to join Club c1
//     s2->addClubRequest(c1);