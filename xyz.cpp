#include <iostream>
using namespace std;

// Function to convert a given string to uppercase
string toUpperCaseASCII(string str) {
    for (int i = 0; i < str.length(); i++) { 
        // Check if the character is a lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') { 
            // Convert the character to uppercase
            str[i] = str[i] - 32; 
        }
    }
    return str; // Return the modified string
}

int main() {
    string input = "hello"; // Example input
    cout << "Uppercase (Brute Force): " << toUpperCaseASCII(input) << endl;
    return 0;
}