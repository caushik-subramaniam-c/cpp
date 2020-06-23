#include<iostream>
using namespace std;
int main()
{
	long long int number, testcase, sum = 0;
	cin >> testcase;
	while (testcase--)
	{
		cin >> number;
		number = number < 0 ? -1 * number : number;
		sum = 0;
		while (number)
		{
			sum += number % 10; // get the last digit and add it to the sum
			number /= 10;
		}
		cout << sum << "\n";
	}
}
