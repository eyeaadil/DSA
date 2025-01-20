#include <iostream>
// #include <string>
using namespace std;

int main() {
    // Declare a string to store user input
    string str;
    int a ;
    // Prompt the user to enter a string
    cout << "Enter a string: ";
    // cin >> a;
    getline(cin, str); // Reads the whole line of input, including spaces
    // cout<<a;
    // Loop through each character of the string
    for (char ch : str) {
        // Print each character and its ASCII value
        cout << "Character: " << ch << ", ASCII value: " << int(ch) << endl;
    }

    return 0;
}
