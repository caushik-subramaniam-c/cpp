#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int number, testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> number;
		number % 2 == 0 ? cout << "Even\n" : cout << "Odd\n"; // check if the number is divisible by 2
	}
	return 0;
}
