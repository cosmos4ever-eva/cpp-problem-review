#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MAXN = 100001;

int main(){
    int n = 0;
    cin >> n;
    int a[MAXN];
    int dp[MAXN];
    int max_len = 0;
    unordered_map<int,int> best;
    int current_len = 0;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
        current_len = best[a[i]-1] + 1;
        best[a[i]] = max(best[a[i]],current_len);
        if(best[a[i]] > max_len)  max_len = best[a[i]];
    }

    cout << max_len;
    return 0;
}
