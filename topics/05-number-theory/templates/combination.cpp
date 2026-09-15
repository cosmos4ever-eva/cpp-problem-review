#include <algorithm>
#include <iostream>
using namespace std;

long long combination(int n, int m) {
    if (m < 0 || m > n) return 0;

    m = min(m, n - m);
    long long total = 1;

    for (int i = 1; i <= m; i++) {
        total = total * (n - m + i) / i;
    }
    return total;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << combination(n, m);
    return 0;
}
