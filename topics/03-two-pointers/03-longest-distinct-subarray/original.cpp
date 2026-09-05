#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int left= 0;
    int right = 0;
    unordered_map<int,int> cnt;
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }

    int max_count = 0;
    for(;right < n;right ++){
        cnt[a[right]]++;
        while(cnt[a[right]] > 1){
            cnt[a[left]]--;
            left++;
        }
        max_count = max(max_count, right - left +1);
    }

    cout << max_count;

    return 0;
}
