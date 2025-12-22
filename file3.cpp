#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

/* Student records using map */
map<int, string> students;

/* Queue for audio lessons */
queue<string> audioQueue;

/* Priority queue for difficulty */
priority_queue<int> difficultyQueue;

void addStudent() {
    int id;
    string name;

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student name (single word): ";
    cin >> name;

    students[id] = name;
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cout << "Student List:\n";
    map<int, string>::iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
}

void enqueueAudio() {
    string lesson;
    cout << "Enter lesson name (single word): ";
    cin >> lesson;

    audioQueue.push(lesson);
    cout << "Audio lesson added.\n";
}

void playAudio() {
    if (audioQueue.empty()) {
        cout << "No audio available.\n";
        return;
    }

    cout << "Playing audio: " << audioQueue.front() << endl;
    audioQueue.pop();
}

void addDifficulty() {
    int level;
    cout << "Enter difficulty level: ";
    cin >> level;

    difficultyQueue.push(level);
    cout << "Difficulty added.\n";
}

void sortStudents() {
    if (students.empty()) {
        cout << "No students to sort.\n";
        return;
    }

    vector<string> names;
    map<int, string>::iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        names.push_back(it->second);
    }

    sort(names.begin(), names.end()); // Introsort

    cout << "Sorted Students (Introsort):\n";
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Accessible Learning Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Add Audio Lesson\n";
        cout << "4. Play Audio Lesson\n";
        cout << "5. Add Difficulty Level\n";
        cout << "6. Sort Students (Introsort)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: enqueueAudio(); break;
            case 4: playAudio(); break;
            case 5: addDifficulty(); break;
            case 6: sortStudents(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
