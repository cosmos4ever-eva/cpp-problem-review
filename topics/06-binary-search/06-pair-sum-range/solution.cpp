#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    long long leftLimit, rightLimit;
    cin >> leftLimit >> rightLimit;

    // 只需要对将要进行二分查找的 b 排序。
    sort(b.begin(), b.end());

    long long answer = 0;
    for (long long value : a) {
        // left 指向第一个满足 b[j] >= leftLimit - value 的位置。
        auto left = lower_bound(
            b.begin(), b.end(), leftLimit - value
        );

        // right 指向第一个满足 b[j] > rightLimit - value 的位置。
        auto right = upper_bound(
            b.begin(), b.end(), rightLimit - value
        );

        answer += right - left;
    }

    cout << answer;
    return 0;
}
