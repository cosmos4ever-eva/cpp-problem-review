#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    long long f[6] = {};

    for (int i = 0; i < n; i++) {
        if (b[i] >= 5 && a[i] != 0) {
            f[b[i] - 5] += 1LL * a[i] * b[i] * (b[i] - 1)
                               * (b[i] - 2) * (b[i] - 3) * (b[i] - 4);
        }
    }

    bool printed = false;
    for (int exponent = 5; exponent >= 0; exponent--) {
        if (f[exponent] != 0) {
            cout << f[exponent] << ' ' << exponent << '\n';
            printed = true;
        }
    }

    if (!printed) {
        cout << "0 0\n";
    }

    return 0;
}
