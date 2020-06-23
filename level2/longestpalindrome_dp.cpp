#include <iostream>
using namespace std;
int main() {
    string input;
    int length, i, j, k;
    cin >> input;
    length = input.length();
    bool table[length][length];
    int start = 0, palindrome_length = 0;
    for (i = 0; i < length; i++)
        for (j = 0; j < length; j++)
            table[i][j] = false; // set all the table entries to false
    for (i = 0; i < length; i++)
        table[i][i] = true; // set all the diagonal cells to true, as a single letter is always a palindrome
    for (i = 0; i < length - 1; i++) { // store the starting index and length of palindromes of length 2
        if (input[i] == input[i + 1]) {
            table[i][i + 1] = true; // if two consecutive characters i and i + 1 are same, set the value of cell i,i+1 to true
            start = i;
            palindrome_length = 2;
        }
    }
    for (k = 3; k <= length; k++) { // stores the starting index and length of palindromes of length > 2
        for (i = 0; i < length - k + 1; i++) { // find the starting index of the substring
            j = i + k - 1; // find the ending index of the substring
            if (input[i] == input[j] && table[i + 1][j - 1] == true) { // if the starting index and the ending index of the substring are the same and the substring formed by removing the starting and the ending characters of this substring is also a palindrome, save the current maximum palindromic substring's index and length
                table[i][j] = true;
                start = i;
                palindrome_length = k;
            }
        }
    }
    for (i = start; i < start + palindrome_length; i++) // print the largest palindromic substring using the starting index and the length
        cout << input[i];
    cout << "\n";
    return 0;
}