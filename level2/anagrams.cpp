#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string string1 = "";
    string string2 = "";
    cin >> string1 >> string2;
    if (string1.length() != string2.length()) {
        cout << "The given strings are 'not anagrams' of each other" << "\n"; // the given strings are not anagrams if their lengths vary
        return 0;
    }
    int hash1[26];
    int hash2[26];
    for (int i = 0; i < 26; i++) {
        hash1[i] = 0;
        hash2[i] = 0;
    }
    for (int i = 0; i < string1.length(); i++)
        hash1[string1[i] - 97] += 1; // in string1, store every character's frequency in the array1 at index string1[i] - 97
    for (int i = 0; i < string2.length(); i++)
        hash2[string2[i] - 97] += 1; // in string1, store every character's frequency in the array2 at the index string2[i] - 97
    for (int  i = 0;i < 26; i++)
        if (hash1[i] == hash2[i]) // if frequencies of all the characters are the same, then the strings are anagrams
            continue;
        else
        {
            cout << "The given strings are 'not anagrams' of each other" << "\n"; // otherwise not
            return 0;
        }
    cout << "The given strings are 'anagrams' of each other" << "\n";
    return 0;
}