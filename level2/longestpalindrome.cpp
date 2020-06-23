#include <iostream>
using namespace std;
int main() {
    string input;
    cin >> input;
    int length = input.length(), i, left, right, start, palindrome_length;
    for (i = 1; i < length; i++) { // consider every index as the center and proceed left and right
        left = i;
        right = i + 1; // even length palindromes
        while (left >=0 && right < length && input[left] == input[right]) { // if characters at the left and the right indices are the same
            if ((right - left + 1) > palindrome_length) { // if the substring's length is greater than the previous length, update the start index and length
                start = left;
                palindrome_length = right - left + 1;
            }
            left = left - 1; // proceed further
            right = right + 1;
        }
        left = i - 1;
        right = i + 1; // odd length palindromes
        while (left >=0 && right < length && input[left] == input[right]) { // if the characters at the left and the right indices are the same
            if ((right - left + 1) > palindrome_length) { // if the substring's length is greater than the previous length, update the start index and length
                start = left;
                palindrome_length = right - left + 1;
            }
            left = left - 1; // proceed further
            right = right + 1;
        }
    }
    for (i = start; i < start + palindrome_length; i++) // output substring using the start index and the length
        cout << input[i];
    cout << "\n";
    return 0;
}