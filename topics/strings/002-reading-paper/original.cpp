#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int MAXN = 1000;

string transfer(string s) {
    string s_new;
    s_new.push_back(s[0]);

    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        if (s[i] != s[i - 1]) {
            s_new.push_back(s[i]);
        }
    }

    return s_new;
}

int main() {
    int n = 0;
    cin >> n;

    string s[MAXN];
    string s_new[MAXN];
    unordered_map<string, int> cnt;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        s_new[i] = transfer(s[i]);
        ++cnt[s_new[i]];
    }

    string answer;
    int max_count = 0;

    for (int i = 0; i < n; ++i) {
        if (cnt[s_new[i]] > max_count) {
            max_count = cnt[s_new[i]];
            answer = s_new[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (cnt[s_new[i]] == max_count) {
            cout << answer;
            break;
        }
    }

    return 0;
}
