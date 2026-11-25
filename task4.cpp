#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("students.txt");
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        char name[20];
        int id;
        float grade;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Do you want to add more? (y/n): ";
        cin >> choice;
    }

    file.close();
    return 0;
}
