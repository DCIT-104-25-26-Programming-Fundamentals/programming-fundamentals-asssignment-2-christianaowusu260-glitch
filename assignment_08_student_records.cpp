// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }

    double total = 0.0;
    for (double score : student.scores) {
        total += score;
    }
    return total / student.scores.size();
}

Student* findStudentById(vector<Student>& students, int id) {
    for (Student& student : students) {
        if (student.id == id) {
            return &student;
        }
    }
    return nullptr;
}

void addStudent(vector<Student>& students) {
    Student student;

    cout << "Student name: ";
    getline(cin >> ws, student.name);

    cout << "Student ID: ";
    while (!(cin >> student.id)) {
        cout << "Invalid ID. Please enter a whole number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (findStudentById(students, student.id) != nullptr) {
        cout << "A student with that ID already exists.\n";
        return;
    }

    int scoreCount;
    cout << "How many scores? ";
    while (!(cin >> scoreCount) || scoreCount < 0) {
        cout << "Please enter a non-negative whole number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    for (int i = 0; i < scoreCount; ++i) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        while (!(cin >> score)) {
            cout << "Invalid score. Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        student.scores.push_back(score);
    }

    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully.\n";
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << left << setw(25) << "Name" << setw(12) << "ID"
         << setw(30) << "Scores" << "Average\n";
    cout << string(77, '-') << '\n';

    for (const Student& student : students) {
        ostringstream scores;
        for (double score : student.scores) {
            scores << fixed << setprecision(2) << score << ' ';
        }
        if (student.scores.empty()) {
            scores << "No scores";
        }
        cout << left << setw(25) << student.name << setw(12) << student.id
             << setw(30) << scores.str() << fixed << setprecision(2)
             << calculateAverage(student) << '\n';
    }
}

void displayStudentAverage(vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    while (!(cin >> id)) {
        cout << "Invalid ID. Please enter a whole number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Student* student = findStudentById(students, id);
    if (student == nullptr) {
        cout << "Student ID not found.\n";
        return;
    }

    cout << student->name << "'s average score: "
         << fixed << setprecision(2) << calculateAverage(*student) << '\n';
}

void displayMenu() {
    cout << "\n================================\n"
         << "   STUDENT RECORD SYSTEM MENU\n"
         << "================================\n"
         << "1. Add student\n"
         << "2. Display all students\n"
         << "3. Calculate average score\n"
         << "4. Quit\n"
         << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid menu choice. Please enter a number from 1 to 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                displayStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid menu choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}
