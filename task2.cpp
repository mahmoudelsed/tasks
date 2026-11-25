#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string text = "Hello Everybody";
    ofstream outFile("welcome.txt");
    outFile << text;
    outFile.close();
    ifstream inFile("welcome.txt");
    getline(inFile, text);
    inFile.close();

    int pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one");
    }

    ofstream finalFile("welcome.txt");
    finalFile << text;
    finalFile.close();

    cout << "Final result in file: " << text << endl;
    return 0;
}
