#include<iostream>
using namespace std;
void merge(int* array, int* leftArray, int* rightArray, int leftLength, int rightLength) {
    int i = 0, j = 0, k = 0;
    while (i < leftLength && j < rightLength) { // do till left array or the right array is fully traversed
        if (leftArray[i] <= rightArray[j])
            array[k++] = leftArray[i++]; // copy the element of left array in main array if it is less than right array element
        else
            array[k++] = rightArray[j++]; // otherwise the right array element
    }
    while (i < leftLength)
        array[k++] = leftArray[i++]; // copy the remaining elements in the left array if any to the main array
    while (j < rightLength)
        array[k++] = rightArray[j++]; // copy the remaining elements in the right array if any to the main array
}
void mergeSort(int* array, int length) {
    if (length <= 1) 
        return; // don't divide if the array has only one element
    int mid = length / 2; // find the mid element to divide the array
    int* leftArray = new int[mid];
    int* rightArray = new int[length - mid];
    for (int i = 0; i < length; i++) {
        if (i < mid)
            leftArray[i] = array[i]; // copy the first half to the left array
        else
            rightArray[i - mid] = array[i]; // copy the next half to the right array
    }
    mergeSort(leftArray, mid); // recurse on the left half of the array
    mergeSort(rightArray, length - mid); // recurse on the right half of the array
    merge(array, leftArray, rightArray, mid, length - mid); // merge the left and the right array and sort them while merging
}
int main() {
    int array[] = {5, 3, 1, 4, 2, 8, 10, 7, 9, 6};
    int length = sizeof(array)/sizeof(array[0]);
    cout << "Before Sort:\n";
    for(int i = 0; i < length; i++)
        cout << array[i] << "\t";
    mergeSort(array, length);
    cout << "\nAfter Sort:\n";
    for(int i = 0; i < length; i++)
        cout << array[i] << "\t";
    cout << "\n";
    return 0;
}