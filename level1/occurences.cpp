#include<iostream>
using namespace std;

void findOccurences(long long int *array1, long long int *array2, int length1, int length2)
{
	bool flag = false;
	for (int i = 0; i < length2; i++)
	{
		cout << array2[i] << " => ";
		for (int j = 0; j < length1; j++)
		{
			if (array1[j] == array2[i]) // print the index if the element in array2 is also in array1
			{
				cout << j + 1 << "\t";
				flag = true;
			}
		}
		if (flag == false)
			cout << "-";
		flag=false;
		cout << "\n";
	}
}

int main()
{
	int testcase, length1, length2;
	cin >> testcase;
	while (testcase--)
	{
		cin >> length1 >> length2;
		long long int *array1 = new long long int[length1];
		long long int *array2 = new long long int[length2];
		for (int i = 0; i < length1; i++)
		{
			cin >> array1[i];
		}
		for (int i = 0; i < length2; i++)
		{
			cin >> array2[i];
		}
		findOccurences(array1, array2, length1, length2);
		cout << "\n";
	}
	return 0;
}
