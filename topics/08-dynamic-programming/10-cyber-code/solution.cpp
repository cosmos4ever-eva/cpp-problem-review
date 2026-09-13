#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    // best[x] 表示目前以数值 x 结尾的最长合法子序列长度。
    unordered_map<int, int> best;
    best.reserve(n * 2);

    int max_len = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        // x 只能接在 x - 1 后面；键不存在时 best[x - 1] 的值为 0。
        int current_len = best[x - 1] + 1;
        best[x] = max(best[x], current_len);
        max_len = max(max_len, best[x]);
    }

    cout << max_len;
    return 0;
}
