#include <iostream>
using namespace std;
int main() {
    string input;
    cin >> input;
    int n = input.length(), i, j, k;
    string temp_string = "";
    string temp_reverse_string = "";
    string palindrome = "";
    for (i = 0; i < n; i++) { // generate all possible substrings
        for (j = 1; j <= n - i; j++) {
            temp_string = "";
            temp_reverse_string = "";
            for (k = i; k < (i + j) && k < n; k++) {
                temp_string = temp_string + input[k]; // generate a substring
            }
            for (k = (i + j - 1); k >= i; k--) {
                temp_reverse_string = temp_reverse_string + input[k]; // generate its reverse
            }
            if (temp_reverse_string == temp_string && temp_string.length() > palindrome.length()) { //  if the string and its reverse are same
                palindrome = temp_string; // store the string if it is the largest seen so far
            }
        }
    }
    cout << palindrome << "\n"; // print the largest palindromic substring
    return 0;
}