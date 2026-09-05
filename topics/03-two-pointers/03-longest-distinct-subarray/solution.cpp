#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int& number : numbers) {
        cin >> number;
    }

    unordered_map<int, int> count;
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < n; ++right) {
        ++count[numbers[right]];

        while (count[numbers[right]] > 1) {
            --count[numbers[left]];
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength;
    return 0;
}
