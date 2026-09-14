#include <iostream>
using namespace std;

const int MAXN = 1001;

int n;
long long k;
long long prefix[MAXN];

// 返回重复数组中前 count 个元素的和，而不是下标 0...count 的和。
long long getPrefix(long long count) {
    long long completeBlocks = count / n;
    int remainingCount = count % n;
    return completeBlocks * prefix[n] + prefix[remainingCount];
}

int main() {
    cin >> n >> k;

    long long l, r;
    cin >> l >> r;

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        long long value;
        cin >> value;
        prefix[i + 1] = prefix[i] + value;
    }

    // 原数组下标从 0 开始，因此闭区间 [l, r] 含有 r - l + 1 个位置。
    cout << getPrefix(r + 1) - getPrefix(l);
    return 0;
}
