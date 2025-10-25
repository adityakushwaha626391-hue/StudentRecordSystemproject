#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int age;
    string course;
};

class StudentRecordSystem {
private:
    map<int, Student> studentData; // rollNo → Student

public:
    void addStudent() {
        Student s;
        cout << "\nEnter Roll No: ";
        cin >> s.rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Enter Age: ";
        cin >> s.age;
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, s.course);

        studentData[s.rollNo] = s;
        cout << "✅ Student added successfully!\n";
    }

    void displayAll() {
        if (studentData.empty()) {
            cout << "⚠️ No records found!\n";
            return;
        }

        cout << "\n--- Student Records ---\n";
        for (auto &p : studentData) {
            Student s = p.second;
            cout << "Roll No: " << s.rollNo
                 << ", Name: " << s.name
                 << ", Age: " << s.age
                 << ", Course: " << s.course << endl;
        }
    }

    void searchStudent() {
        int roll;
        cout << "\nEnter Roll No to search: ";
        cin >> roll;

        auto it = studentData.find(roll);
        if (it != studentData.end()) {
            Student s = it->second;
            cout << "✅ Record Found!\n";
            cout << "Roll No: " << s.rollNo
                 << ", Name: " << s.name
                 << ", Age: " << s.age
                 << ", Course: " << s.course << endl;
        } else {
            cout << "❌ No student found with that roll number.\n";
        }
    }

    void deleteStudent() {
        int roll;
        cout << "\nEnter Roll No to delete: ";
        cin >> roll;

        if (studentData.erase(roll)) {
            cout << "🗑️ Student deleted successfully!\n";
        } else {
            cout << "❌ Record not found!\n";
        }
    }
};

int main() {
    StudentRecordSystem system;
    int choice;

    do {
        cout << "\n========= Student Record System =========";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addStudent(); break;
            case 2: system.displayAll(); break;
            case 3: system.searchStudent(); break;
            case 4: system.deleteStudent(); break;
            case 5: cout << "👋 Exiting...\n"; break;
            default: cout << "⚠️ Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
