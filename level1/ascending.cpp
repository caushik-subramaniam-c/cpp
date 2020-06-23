#include<iostream>
using namespace std;
void mergeSort (long long int* finalArray, long long int* left, long long int* right, int leftLength, int rightLength) {
	int i = 0, j = 0, k = 0;
	while (i < leftLength && j < rightLength) {
		if (left[i] <= right[j])
			finalArray[k++] = left[i++]; // copy the left array element to main array if its smaller than the right element
		else
			finalArray[k++] = right[j++]; // copy the right array element otherwise
	}
	while (i < leftLength) // copy the remaining elements from left array to the main array
		finalArray[k++] = left[i++];
	while (j < rightLength) // copy the remaining elements from right array to the main array
		finalArray[k++] = right[j++];
}

void sort(long long int* array, int length) {
	if (length <=1) // don't do anything if the array has only one element
		return;
	int mid = length/2;
	long long int* left = new long long int[mid];
	long long int* right = new long long int[length - mid];
	int i = 0;
	for (i; i < mid; i++) // create a new sub array 'left' with first 'mid' elements
		left[i] = array[i];
	for (i; i < length; i++) // create a new sub array 'right' with first 'length - mid' elements
		right[i - mid] = array[i];
	sort(left, mid); // recurse on the left sub array
	sort(right, length - mid); // recurse on the right sub array
	mergeSort(array, left, right, mid, length - mid); // sort and merge the left and right sub arrays
}

int main()
{
	int testcase, length;
	cin >> testcase;
	while (testcase--)
	{
		cin >> length;
		long long int *array = new long long int[length];
		for (int i = 0; i < length; i++)
		{
			cin >> array[i];
		}
		sort(array, length);
		for (int i = 0; i < length; i++)
		{
			cout << array[i] << "\t";
		}
		cout<<"\n";
	}
	return 0;
}
