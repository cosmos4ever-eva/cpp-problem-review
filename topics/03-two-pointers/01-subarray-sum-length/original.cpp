#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;
int a[MAXN] = {0};

int num(int left, int right) {
    return right - left + 1;
}

int main() {
    int n = 0;
    int x = 0;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    int max_count = 0;
    int les_count = n;
    bool found = false;

    for (; right < n; ++right) {
        sum += a[right];

        while (sum > x) {
            sum -= a[left];
            ++left;
        }

        if (sum == x) {
            if (num(left, right) > max_count) {
                max_count = num(left, right);
            }
            if (num(left, right) < les_count) {
                les_count = num(left, right);
            }
            found = true;
        }
    }

    if (!found) {
        cout << -1 << ' ' << -1;
    } else {
        cout << les_count << ' ' << max_count;
    }

    return 0;
}
