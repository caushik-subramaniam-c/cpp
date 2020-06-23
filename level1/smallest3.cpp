#include<bits/stdc++.h>
using namespace std;

int findThirdSmallest(long long int* array, int length) {
	int minimum1 = INT_MAX, minimum2 = INT_MAX, minimum3 = INT_MAX;
	for (int i = 0; i < length; i++) {
		if (array[i] < minimum1) {
			minimum3 = minimum2;
			minimum2 = minimum1;
			minimum1 = array[i];
		}
		else if (array[i] > minimum1) {
			if (array[i] < minimum2) {
				minimum2 = array[i];
			}
			else if (array[i] > minimum2) {
				if (array[i] < minimum3)
					minimum3 = array[i];
			}
		}
	}
	return minimum3;
}

int main()
{
	int testcase, length;
	cin >> testcase;
	while (testcase--)
	{
		cin >> length;
		if (length < 3) {
			cout << "should be >=3" << "\n";
			continue;
		}
		long long int *array = new long long int[length];
		for (int i = 0; i < length; i++)
		{
			cin >> array[i];
		}
		cout<< findThirdSmallest(array, length) <<"\n";
	}
	return 0;
}