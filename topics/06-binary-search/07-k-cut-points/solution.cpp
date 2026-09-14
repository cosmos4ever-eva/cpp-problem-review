#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canCut(
    const vector<int>& cutPositions,
    int cutCount,
    int totalLength,
    int minimumLength
) {
    int selectedCount = 0;
    int lastPosition = 0;

    // 每次选择当前位置最靠左的可用切口，为后续各段保留最多空间。
    for (int position : cutPositions) {
        if (position - lastPosition >= minimumLength) {
            lastPosition = position;
            selectedCount++;

            // 只需选择 cutCount 个切口，保留第 cutCount 个切口的位置。
            if (selectedCount == cutCount) {
                break;
            }
        }
    }

    // 选够切口后，最后一个切口到木条终点也必须满足最短长度。
    return selectedCount == cutCount &&
           totalLength - lastPosition >= minimumLength;
}

int main() {
    int n, k, totalLength;
    cin >> n >> k >> totalLength;

    vector<int> cutPositions(n);
    for (int i = 0; i < n; i++) {
        cin >> cutPositions[i];
    }

    sort(cutPositions.begin(), cutPositions.end());

    int left = 1;
    int right = totalLength / (k + 1);
    int answer = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (canCut(cutPositions, k, totalLength, middle)) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << answer;
    return 0;
}
