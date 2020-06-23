#include<bits/stdc++.h>
using namespace std;

int findSecondLargest(long long int* array, int length) {
	int maximum1 = INT_MIN, maximum2 = INT_MIN;
	for (int i = 0; i < length; i++) {
		if (array[i] > maximum1) {
			maximum2 = maximum1;
			maximum1 = array[i];
		}
		else if (array[i] < maximum1){
			if (array[i] > maximum2)
				maximum2 = array[i];
		}
	}
	return maximum2;
}

int main()
{
	int testcase, length;
	cin >> testcase;
	while (testcase--)
	{
		cin >> length;
		if (length <= 1)
		{
			cout << "should be >=1" << "\n";
			continue;
		}
		long long int *array = new long long int[length];
		for (int i = 0; i < length; i++)
		{
			cin >> array[i];
		}
		cout << findSecondLargest(array, length) << "\n";	
	}
	return 0;
}