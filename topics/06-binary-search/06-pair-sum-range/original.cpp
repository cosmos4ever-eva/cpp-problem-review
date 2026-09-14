#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N = 0,M = 0;
    cin >> N >> M;

    vector<int> a(N);
    vector<int> b(M);
    for(int i = 0;i < N;i ++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < M;i ++){
        cin >> b[i];
    }
    sort(b.begin(),b.end());

    int L = 0, R = 0;
    cin >> L >> R;

    long long cnt = 0;
    for(int i = 0;i < N;i++){
        auto left = lower_bound(b.begin(),b.end(),L - a[i]);
        auto right = upper_bound(b.begin(),b.end(),R - a[i]);
        cnt += right - left;
    }

    cout << cnt;
    return 0;
}
