#include<iostream>
using namespace std;
int main()
{
	long long int number, testcase, count = 0;
	cin >> testcase;
	while (testcase--)
	{
		cin >> number;
		count = 0; 
		for (int i = 1; i <= number; i++)
		{
			if (number % i == 0)
				count += 1; // if number is prime, increments exactly twice. once when the number is divided by 1 and the other when it divides itself
		}
		count == 2 ? cout << "Prime\n" : cout << "Composite\n";
	}
	return 0;
}
