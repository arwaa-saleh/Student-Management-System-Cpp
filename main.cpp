#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    Student(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    void display() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | GPA: " << gpa << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            students.push_back(Student(id, name, gpa));

            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (auto &s : students) {
                    s.display();
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            cout << "Enter Student ID: ";
            cin >> searchId;

            bool found = false;

            for (auto &s : students) {
                if (s.getId() == searchId) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student Not Found.\n";
            }
        }

    } while (choice != 4);

    cout << "Goodbye!\n";

    return 0;
}
