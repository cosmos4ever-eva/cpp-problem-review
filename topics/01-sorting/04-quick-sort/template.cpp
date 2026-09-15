#include <algorithm>
#include <vector>
using namespace std;

void quickSort(vector<int>& values, int left, int right) {
    if (left >= right) return;

    int pivot = values[left + (right - left) / 2];
    int i = left - 1;
    int j = right + 1;

    while (i < j) {
        do i++; while (values[i] < pivot);
        do j--; while (values[j] > pivot);
        if (i < j) swap(values[i], values[j]);
    }

    quickSort(values, left, j);
    quickSort(values, j + 1, right);
}
