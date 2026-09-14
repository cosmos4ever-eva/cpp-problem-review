#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n = 0,k = 0,L = 0;
    cin >> n >> k >> L;

    vector<int> len(n);
    for(int i = 0;i < n;i ++){
        cin >> len[i];
    }

    int l = 1,r = L;
    int mid = 0;
    int answer = 0;
    while(l <= r){
        mid = l + (r - l) / 2;
        int sum = 0;
        int last = 0;
        for(int i = 0;i < n;i++){
            if (len[i] - last >= mid){
                last = len[i];
                sum++;
            }
            if(sum == k) break;
        }

        if(sum == k && ((L - last) >= mid)){
            answer = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << answer;
    return 0;
}
