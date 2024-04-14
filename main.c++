#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct for Student
struct Student {
    string name;
    string LRN;
    int age;
    string lastSchoolAttend;
    char sex;
    string schoolYear;
    string preferredStrand;
    string preferredModality;
    string semester; // Added Semester field
    float GWA;
    string contactNumber;
    string birthday;
    bool payee; // true for payee, false for non-payee
};

// Function to handle user registration
void registerUser(string& email, string& password) {
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;
    cout << "Successfully registered. Please login:" << endl;
}

// Function to handle user login
bool loginUser(const string& email, const string& password) {
    string inputEmail, inputPassword;
    cout << "Enter email: ";
    cin >> inputEmail;
    cout << "Enter password: ";
    cin >> inputPassword;

    // Check if the input email and password match the registered email and password
    return (inputEmail == email && inputPassword == password);
}

// Function to register a new student
void registerNewStudent(vector<Student>& students) {
    int numNewStudents;
    cout << "Enter the number of new students: ";
    cin >> numNewStudents;
    cin.ignore();

    for (int i = 0; i < numNewStudents; ++i) {
        Student newStudent;
        cout << "Enter Student Name: ";
        getline(cin, newStudent.name);
        cout << "Enter LRN: ";
        getline(cin, newStudent.LRN);
        cout << "Enter Age: ";
        cin >> newStudent.age;
        cin.ignore();
        cout << "Enter Last School Attended: ";
        getline(cin, newStudent.lastSchoolAttend);
        cout << "Enter Sex (M/F): ";
        cin >> newStudent.sex;
        cin.ignore();
        cout << "Enter School Year: ";
        getline(cin, newStudent.schoolYear);
        cout << "Enter Preferred Strand: ";
        getline(cin, newStudent.preferredStrand);
        cout << "Enter Preferred Modality (Pure online/Blended Learning/Modular): ";
        getline(cin, newStudent.preferredModality);
        cout << "Enter Semester: ";
        getline(cin, newStudent.semester); // Added Semester field
        cout << "Enter GWA: ";
        cin >> newStudent.GWA;
        cin.ignore();
        cout << "Enter Contact Number: ";
        getline(cin, newStudent.contactNumber);
        cout << "Enter Birthday: ";
        getline(cin, newStudent.birthday);

        students.push_back(newStudent);
    }
}

// Function to register an old student
void registerOldStudent(vector<Student>& students) {
    int numOldStudents;
    cout << "Enter the number of old students: ";
    cin >> numOldStudents;
    cin.ignore();

    for (int i = 0; i < numOldStudents; ++i) {
        Student oldStudent;
        cout << "Enter Student Name: ";
        getline(cin, oldStudent.name);
        cout << "Enter LRN: ";
        getline(cin, oldStudent.LRN);
        cout << "Enter Age: ";
        cin >> oldStudent.age;
        cin.ignore();
        cout << "Enter Sex (M/F): ";
        cin >> oldStudent.sex;
        cin.ignore();
        cout << "Enter Last School Year: ";
        getline(cin, oldStudent.schoolYear);
        cout << "Enter Previous Adviser: ";
        getline(cin, oldStudent.lastSchoolAttend);
        cout << "Enter Current Year Level: ";
        getline(cin, oldStudent.preferredStrand);
        cout << "Enter Academic Level: ";
        getline(cin, oldStudent.preferredModality);
        cout << "Enter Preferred Strand: ";
        getline(cin, oldStudent.preferredStrand);
        cout << "Enter Preferred Modality (Pure online/Blended Learning/Modular): ";
        getline(cin, oldStudent.preferredModality);
        cout << "Enter GWA: ";
        cin >> oldStudent.GWA;
        cin.ignore();
        cout << "Enter Contact Number: ";
        getline(cin, oldStudent.contactNumber);

        students.push_back(oldStudent);
    }
}

// Function to display student status
void displayStudentStatus(const Student& student) {
    cout << "Student Name: " << student.name << endl;
    cout << "LRN: " << student.LRN << endl;
    cout << "Age: " << student.age << endl;
    cout << "Last School Attended: " << student.lastSchoolAttend << endl;
    cout << "Sex: " << student.sex << endl;
    cout << "School Year: " << student.schoolYear << endl;
    cout << "Preferred Strand: " << student.preferredStrand << endl;
    cout << "Preferred Modality: " << student.preferredModality << endl;
    cout << "Semester: " << student.semester << endl; // Display Semester
    cout << "GWA: " << student.GWA << endl;
    cout << "Contact Number: " << student.contactNumber << endl;
    cout << "Birthday: " << student.birthday << endl;
    cout << "Payee: " << (student.payee ? "Yes" : "No") << endl;
}

int main() {
    vector<Student> students;
    string userEmail, userPassword;
    bool loggedIn = false;

    cout << "WELCOME TO ENROLLMENT SYSTEM. PLEASE REGISTER TO PROCEED" << endl;
    registerUser(userEmail, userPassword);

    // Login loop
    while (!loggedIn) {
        loggedIn = loginUser(userEmail, userPassword);
        if (!loggedIn) {
            cout << "Invalid email or password. Please try again." << endl;
        }
    }

    cout << "Thank you for logging in. You are now ready to enroll." << endl;
    cout << "Please select:" << endl;
    cout << "1. New Student" << endl;
    cout << "2. Old Student" << endl;

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            registerNewStudent(students);
            break;
        case 2:
            registerOldStudent(students);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    // Display Student Status
    cout << "Student Status:" << endl;
    for (const auto& student : students) {
        displayStudentStatus(student);
        cout << endl;
    }

    // Ask if payee or non-payee
    char payeeChoice;
    cout << "Are you a payee or non-payee? (P/N): ";
    cin >> payeeChoice;

    for (auto& student : students) {
        if (payeeChoice == 'P' || payeeChoice == 'p') {
            student.payee = true;
        } else if (payeeChoice == 'N' || payeeChoice == 'n') {
            student.payee = false;
        }
    }

    // Display Enrollment Confirmation
    cout << "Congratulations! You are now officially enrolled in Eclaro Academy." << endl;
    cout << "Student Status:" << endl;
    for (const auto& student : students) {
        displayStudentStatus(student);
        cout << endl;
    }

    return 0;
}
