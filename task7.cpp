#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    ofstream outFile("names.txt");
    for (string n : names) {
        outFile << n << endl;
    }
    outFile.close();

    vector<string> loadedNames;
    ifstream inFile("names.txt");
    string line;
    while (getline(inFile, line)) {
        loadedNames.push_back(line);
    }
    inFile.close();

    sort(loadedNames.begin(), loadedNames.end());

    ofstream sortedFile("sorted_names.txt");
    for (string n : loadedNames) {
        sortedFile << n << endl;
        cout << n << endl;
    }
    sortedFile.close();

    return 0;
}
