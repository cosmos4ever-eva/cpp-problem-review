#include <iostream>
#include <unordered_map>
using namespace std;

long long countPairs(long long frequency) {
    return frequency * (frequency - 1) / 2;
}

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<long long, long long> remainderCount;
    remainderCount[0] = 1;  // 空前缀的余数为 0

    long long prefixSum = 0;
    for (int i = 0; i < n; i++) {
        long long value;
        cin >> value;
        prefixSum += value;

        long long remainder = prefixSum % k;
        if (remainder < 0) {
            remainder += k;
        }
        remainderCount[remainder]++;
    }

    long long answer = 0;
    for (const auto& item : remainderCount) {
        answer += countPairs(item.second);
    }

    cout << answer;
    return 0;
}
