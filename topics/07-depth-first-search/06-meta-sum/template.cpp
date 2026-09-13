#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> values;
set<int> answers;
int currentValue = 0;

// 二选一 DFS：每层处理 values[idx]，两条分支分别修改累计值。
void DFS(int idx) {
    if (idx == values.size()) {
        answers.insert(currentValue);
        return;
    }

    // 选择一：按照第一种方式贡献当前元素。
    currentValue += values[idx];
    DFS(idx + 1);
    currentValue -= values[idx];  // 恢复到进入本层时的状态

    // 选择二：按照第二种方式贡献当前元素。
    currentValue -= values[idx];
    DFS(idx + 1);
    currentValue += values[idx];  // 恢复到进入本层时的状态
}

int main() {
    int n;
    cin >> n;

    values.resize(n);
    for (int &value : values) {
        cin >> value;
    }

    DFS(0);

    // set 没有下标和 push_back；使用 insert 添加，用循环遍历。
    for (int answer : answers) {
        cout << answer << '\n';
    }

    return 0;
}
