#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > result;
vector<int> temp;
int n;

void DFS(int idx) {
    if (idx == n + 1) {
        result.push_back(temp);
        return;
    }
    temp.push_back(idx);
    DFS(idx + 1);
    temp.pop_back();
    DFS(idx + 1);
}

bool cmp(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

int main() {
    scanf("%d", &n);
    DFS(1);
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            printf("%d", result[i][j]);
            if (j + 1 < result[i].size()) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
