#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 17;

vector<int> numbers;
int currentOr = 0;
int selectedCount = 0;
int minCount = INF;
int n, target;

void DFS(int idx) {
    if (currentOr == target) {
        minCount = min(minCount, selectedCount);
        return;
    }

    if (idx == n || selectedCount >= minCount) {
        return;
    }

    // 选择当前数字。按位或不能直接逆运算，所以先保存旧值。
    int oldOr = currentOr;
    currentOr |= numbers[idx];
    selectedCount++;

    DFS(idx + 1);

    currentOr = oldOr;
    selectedCount--;

    // 不选择当前数字。
    DFS(idx + 1);
}

int main() {
    int k;
    cin >> n >> k;

    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    target = (1 << k) - 1;
    DFS(0);

    cout << (minCount == INF ? -1 : minCount) << '\n';
    return 0;
}
