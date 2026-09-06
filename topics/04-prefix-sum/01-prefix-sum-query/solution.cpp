#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        prefix[i] = prefix[i - 1] + value;
    }

    int queryCount;
    cin >> queryCount;

    while (queryCount--) {
        int m;
        cin >> m;
        cout << prefix[m] << '\n';
    }

    return 0;
}
