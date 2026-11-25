#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("grades.txt");
    outFile << "85\n90\n78\n92\n88\n";
    outFile.close();

    ifstream inFile("grades.txt");
    int grade;
    cout << "Grades in file:" << endl;
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();

    int toDelete;
    cout << "Enter grade to delete: ";
    cin >> toDelete;

    ifstream readFile("grades.txt");
    ofstream tempFile("temp.txt");
    bool found = false;

    while (readFile >> grade) {
        if (grade == toDelete && !found) {
            found = true;
            continue;
        }
        tempFile << grade << endl;
    }
    readFile.close();
    tempFile.close();

    if (found) {
        remove("grades.txt");
        rename("temp.txt", "grades.txt");
        cout << "Grade deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Error: Grade not found." << endl;
    }

    return 0;
}
