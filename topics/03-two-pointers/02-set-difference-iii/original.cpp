#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000;

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<int> s1(n);
    vector<int> s2(m);
    vector<int> s_new;

    for (int i = 0; i < n; ++i) {
        cin >> s1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> s2[i];
    }

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (s1[i] < s2[j]) {
            s_new.push_back(s1[i]);
            ++i;
        } else if (s1[i] == s2[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    while (i < n) {
        s_new.push_back(s1[i++]);
    }

    if (!s_new.empty()) {
        for (int i = 0; i < static_cast<int>(s_new.size()); ++i) {
            if (i != 0) {
                cout << ' ';
            }
            cout << s_new[i];
        }
    }

    return 0;
}
