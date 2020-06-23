#include <iostream>
#include <string.h>
using namespace std;
class Stack {
    private:
        char* array;
        int arraySize, top, stat;
        int isEmpty() {
            if (top == -1)
                return 1;
            return 0;
        }
        int isFull() {
            if (top == arraySize)
                return 1;
            return 0;
        }
    public:
        Stack(int length) {
            array = new char[length];
            top = -1;
            arraySize = length;
        }
        char pop(){
            if (!isEmpty()) {
                char temp = array[top];
                top = top - 1;
                return temp;
            }
        }
        void push(char element) {
            if (!isFull()) {
                top = top + 1;
                array[top] = element;
            }
        }
        int status() {
            return isEmpty();
        }
};

int main() {
    string parantheses = "{{{{";
    Stack paranthesesStack(parantheses.length()); // create a stack that can store all the parantheses
    for (int i = 0; i < parantheses.length(); i++) {
        if (parantheses[i] == '{') { // if the character is an opening paranthesis, push it into the stack
            paranthesesStack.push(parantheses[i]);
        }
        else if (parantheses[i] == '}') { // if the character is a closing paranthesis, pop one element from the stack
            char t = paranthesesStack.pop();
            if (t != '{') { // check if the popped element is a matching opening paranthesis. if not the given set of parantheses are not balanced. continue otherwise
                cout << "Mismatch" <<"\n";
                return 0;
            }
        }
    }
    int status = paranthesesStack.status(); // check if the stack is empty
    if (status == 1) // if the stack is empty, the given set of parantheses are balanced
        cout << "Match\n";
    else // otherwise not
        cout << "Mismatch\n";
    return 0;
}

/*
Reverse words in a given string //
Longest Palindrome in a String
If the given input is an Anagram
Find the nth smallest element //
Code for Merge Sort //
Implement Queue using 2 Stacks //
Code for Parenthesis Checker //
*/
