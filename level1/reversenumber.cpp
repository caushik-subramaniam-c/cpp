#include<iostream>
using namespace std;
int main()
{
	long long int inputNumber, revertedNumber, testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> inputNumber;
		revertedNumber = 0;
		while (inputNumber)
		{
			revertedNumber = revertedNumber * 10 + inputNumber % 10; // get the last digit and add it to the reverse
			inputNumber = inputNumber / 10;
		}
		cout << revertedNumber << "\n";
	}
	return 0;
}
