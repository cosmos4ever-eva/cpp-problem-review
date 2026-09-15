#include <vector>
using namespace std;

void mergeRange(vector<int>& values, int left, int mid, int right) {
    int leftPointer = left;
    int rightPointer = mid + 1;
    int index = 0;
    vector<int> temp(right - left + 1);

    while (leftPointer <= mid && rightPointer <= right) {
        if (values[leftPointer] <= values[rightPointer]) {
            temp[index++] = values[leftPointer++];
        } else {
            temp[index++] = values[rightPointer++];
        }
    }

    while (leftPointer <= mid) {
        temp[index++] = values[leftPointer++];
    }
    while (rightPointer <= right) {
        temp[index++] = values[rightPointer++];
    }

    for (int k = left; k <= right; k++) {
        values[k] = temp[k - left];
    }
}

void recursiveMergeSort(vector<int>& values, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    recursiveMergeSort(values, left, mid);
    recursiveMergeSort(values, mid + 1, right);
    mergeRange(values, left, mid, right);
}
