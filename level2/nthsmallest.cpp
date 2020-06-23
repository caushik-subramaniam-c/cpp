#include <iostream>
using namespace std;
void merge(int* array, int* leftArray, int* rightArray, int leftLength, int rightLength) {
    int i = 0, j = 0, k = 0;
    while (i < leftLength && j < rightLength) {
        if (leftArray[i] <= rightArray[j])
            array[k++] = leftArray[i++];
        else
            array[k++] = rightArray[j++];
    }
    while (i < leftLength)
        array[k++] = leftArray[i++];
    while (j < rightLength)
        array[k++] = rightArray[j++];
}
void mergeSort(int* array, int length) {
    if (length <= 1)
        return;
    int mid = length / 2;
    int* leftArray = new int[mid];
    int* rightArray = new int[length - mid];
    for (int i = 0; i < length; i++) {
        if (i < mid)
            leftArray[i] = array[i];
        else
            rightArray[i - mid] = array[i];
    }
    mergeSort(leftArray, mid);
    mergeSort(rightArray, length - mid);
    merge(array, leftArray, rightArray, mid, length - mid);
}
int main() {
    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int length = sizeof(array)/sizeof(array[0]);
    int n = 1;
    mergeSort(array, length); // sort the array in ascending order
    cout << array[n - 1] << "\n"; // find the nth element
}