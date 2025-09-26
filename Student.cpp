#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int ind;

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i <= ind; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    Vector(int cap = 2) {
        capacity = cap;
        arr = new T[capacity];
        ind = -1;
    }

    void push_back(T x) {
        for (int i = 0; i <= ind; i++)
            if (arr[i] == x) return; 

        if (ind + 1 == capacity)
            resize();
        arr[++ind] = x;
    }

    void pop(T x) {
        if (ind == -1) {
            cout << "Empty list!" << endl;
            return;
        }
        bool found = false;
        for (int i = 0; i <= ind; i++) {
            if (arr[i] == x) {
                found = true;
                for (int j = i; j < ind; j++)
                    arr[j] = arr[j + 1];
                ind--;
                break;
            }
        }
        if (!found)
            cout << "Element not found!" << endl;
    }

    bool empty() { return ind == -1; }
    int size() { return ind + 1; }

    void display() {
        if (empty()) {
            cout << "No elements to show" << endl;
            return;
        }
        for (int i = 0; i <= ind; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    const T& operator[](int index) const { return arr[index]; }

};

class Assignment {
public:
    string title;
    Assignment(string t) : title(t) {}
};

class Submission {
public:
    Assignment* assignment;
    bool late;
    Submission(Assignment* a, bool l) : assignment(a), late(l) {}
};

class Club {
public:
    string name;
    Club(string n) : name(n) {}
};

class Person {
protected:
    string name;
    int id;
    string password;

public:
    Person(string n = "", int i = 0, string p = "") : name(n), id(i), password(p) {}

    bool login(int inputId, const string& inputPassword) const {
        return (inputId == id && inputPassword == password);
    }

    void requireLogin(int inputId, const string& inputPassword) const {
        if (login(inputId, inputPassword))
            cout << "Login successful for " << name << endl;
        else
            cout << "Login failed for " << name << endl;
    }

    virtual void display() const {
        cout << "Name: " << name << ", Enrollment ID: " << id << endl;
    }

    string getName() const { return name; }
    int getID() const { return id; }
};

class Student : public Person {
private:
    string mail;
    int GraduationYear;
    float cgpa;
    Vector<Club*> Clubs;
    Vector<Submission*> Assignment_Submission;

public:
    // Default constructor 
    Student() : Person("", 0, ""), mail(""), GraduationYear(0), cgpa(0.0f) {}
    //Constructor when you pass the value
    Student(string n, string m, int gradYear, float g, int i = 0, string p = "")
        : Person(n, i, p), mail(m), GraduationYear(gradYear), cgpa(g) {}
    
    //Adding credentials mannually
    void AddCredentials() {
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
        cin >> id;
    }

    // viewing credentails
    void ViewCredentials() {
        cout << "Name: " << name << endl;
        cout << "Mail: " << mail << endl;
        cout << "Graduation Year: " << GraduationYear << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Enrollment ID: " << id << endl;
    }
    //Joining a club
    bool joinClubs(Club* c) {
        Clubs.push_back(c);
        return true;
    }

    //Leaving a club
    bool leaveClub(Club* c) {
        Vector<Club*> temp;
        for (int i = 0; i <= Clubs.size() - 1; i++) {
            if (Clubs[i] != c)
                temp.push_back(Clubs[i]);
        }
        Clubs = temp;
        return true;
    }

    //View all your Clubs
    Vector<Club*> ViewClubs() const {
        return Clubs;
    }

    //Submit Assignment of specific Club
    void submitAssignment(Assignment* a, bool late) {
        Submission* s = new Submission(a, late);
        Assignment_Submission.push_back(s);
    }

    //Get an specific assignment
    void getAssignment(Club* c) const {
        cout << "Assignments for club: " << c->name << endl;
    }

    int getEnrollment() const { return id; }
    int getGraduationYear() const { return GraduationYear; }
    float getCGPA() const { return cgpa; }
};

int main() {
    // Example usage
    Student s1;
    s1.AddCredentials();

    Club c1("Drama");
    Assignment a1("Play Script");

    s1.joinClubs(&c1);
    s1.submitAssignment(&a1, false);

    s1.getAssignment(&c1);
    s1.ViewCredentials();

    return 0;
}
