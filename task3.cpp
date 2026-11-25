#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;
    cin.ignore();

    ofstream outFile("persons.txt");
    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, p.name);
        cout << "Enter age of person " << i + 1 << ": ";
        cin >> p.age;
        cin.ignore();
        outFile << p.name << endl;
        outFile << p.age << endl;
    }
    outFile.close();

    vector<Person> persons;
    ifstream inFile("persons.txt");
    Person temp;
    while (getline(inFile, temp.name)) {
        inFile >> temp.age;
        inFile.ignore();
        persons.push_back(temp);
    }
    inFile.close();

    Person younger = persons[0];
    Person older = persons[0];

    for (int i = 1; i < persons.size(); i++) {
        if (persons[i].age < younger.age)
            younger = persons[i];
        if (persons[i].age > older.age)
            older = persons[i];
    }

    ofstream resultFile("results.txt");
    resultFile << "Younger person: " << younger.name << " - Age: " << younger.age << endl;
    resultFile << "Older person: " << older.name << " - Age: " << older.age << endl;
    resultFile.close();

    cout << "Younger: " << younger.name << " (" << younger.age << ")" << endl;
    cout << "Older: " << older.name << " (" << older.age << ")" << endl;

    return 0;
}
