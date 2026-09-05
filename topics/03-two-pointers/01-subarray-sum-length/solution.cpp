#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long target;
    cin >> n >> target;

    vector<int> numbers(n);
    for (int& number : numbers) {
        cin >> number;
    }

    int left = 0;
    long long sum = 0;
    int minLength = n + 1;
    int maxLength = 0;

    for (int right = 0; right < n; ++right) {
        sum += numbers[right];

        while (sum > target) {
            sum -= numbers[left];
            ++left;
        }

        if (sum == target) {
            int length = right - left + 1;
            minLength = min(minLength, length);
            maxLength = max(maxLength, length);
        }
    }

    if (maxLength == 0) {
        cout << -1 << ' ' << -1 << '\n';
    } else {
        cout << minLength << ' ' << maxLength << '\n';
    }

    return 0;
}
