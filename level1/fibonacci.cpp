#include<bits/stdc++.h>
using namespace std;
int main()
{
	double number, third, first, second, testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> number;
		third = 0, first = 0, second = 1;
		for (int i = 0; i < number; i++)
		{
			third = first + second; // adds previous two numbers
			if (third > DBL_MAX) {
				cout << "exceeding limit" << "\n";
				break;
			}
			first = second;
			second = third;
			cout << third << "\t";
		}
		cout << "\n";
	}
	return 0;
}
