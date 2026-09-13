#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> numbers;
set<int> result;
int currentSum = 0;

void DFS(int idx) {
    if (idx == numbers.size()) {
        result.insert(currentSum);
        return;
    }

    // 当前数字保留原值。
    currentSum += numbers[idx];
    DFS(idx + 1);
    currentSum -= numbers[idx];

    // 当前数字变为相反数。
    currentSum -= numbers[idx];
    DFS(idx + 1);
    currentSum += numbers[idx];
}

int main() {
    int n;
    cin >> n;

    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    DFS(0);

    for (int sum : result) {
        cout << sum << '\n';
    }

    return 0;
}
