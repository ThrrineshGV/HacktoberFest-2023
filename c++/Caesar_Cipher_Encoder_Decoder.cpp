#include <iostream>
#include <string>

using namespace std;

void decode(){
    string in_str;
    cout << "Enter the string to decode: ";
    cin.ignore(); // Clear the newline left from previous input
    getline(cin, in_str);  // Use getline to accept spaces

    bool isKey = false;
    char check;
    cout << "
