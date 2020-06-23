#include<iostream>
using namespace std;
int main()
{
	string inputString, revertedString = "";
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> inputString;
		revertedString = "";
		int length = inputString.length();
		for (int i = length - 1; i >= 0; i--)
		{
			revertedString += inputString[i]; // append the characters to a new string from the reverse of the input string one by one
		}
		cout << revertedString << "\n";
	}
}
