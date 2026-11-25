#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
 string line;
 ifstream readfile("fruit.txt");
 cout <<"fruits in file:" <<end1;
 while (getline(readfile, line)) {
cout << line << end1;
readfile.close();
ofstream writefile("fruit.txt", ios::app);
writefile << "fresh fruits" << end1;
writefile.close();
cout << "fresh fruits added successfully!" << end1;
    return 0;
{
