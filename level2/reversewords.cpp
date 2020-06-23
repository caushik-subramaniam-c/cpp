#include <iostream>
using namespace std;
string strrev(string s) {
    string reverse = "";
    for (int i = s.length(); i >= 0; i--) {
        reverse = reverse + s[i];
    }
    return reverse;
}
int main() {
    string s = "if the stack is empty, the given set of parantheses are balanced";
    string word = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' || (i == s.length() - 1))
            word = word + s[i];
        if (i == (s.length() - 1) || s[i] == ' ') {
            cout << strrev(word) << " ";
            word = "";
        }
    }
    cout << "\n";
    return 0;
}