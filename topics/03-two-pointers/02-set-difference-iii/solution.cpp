#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> firstSet(n);
    vector<int> secondSet(m);
    vector<int> difference;
    difference.reserve(n);

    for (int& value : firstSet) {
        cin >> value;
    }
    for (int& value : secondSet) {
        cin >> value;
    }

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (firstSet[i] < secondSet[j]) {
            difference.push_back(firstSet[i]);
            ++i;
        } else if (firstSet[i] == secondSet[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    while (i < n) {
        difference.push_back(firstSet[i]);
        ++i;
    }

    if (!difference.empty()) {
        for (int index = 0; index < static_cast<int>(difference.size()); ++index) {
            if (index > 0) {
                cout << ' ';
            }
            cout << difference[index];
        }
    }

    return 0;
}
