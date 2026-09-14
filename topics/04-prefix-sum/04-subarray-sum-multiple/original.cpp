#include<iostream>
#include<algorithm>
#include<unordered_map>
const int MAXN = 100001;
using namespace std;

long long count_num(long long n){
    return n * (n-1)/2;
}

int main(){
    long long n = 0;
    int k = 0;
    cin >> n >> k;

    long long a[MAXN];
    long long prefix[MAXN];
    unordered_map<long long,long long> remainder;
    remainder[0] = 1;
    prefix[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
        remainder[prefix[i] % k] ++;
    }

    long long cnt = 0;
    for(const auto& item: remainder){
        long long frequency = item.second;
        cnt += count_num(frequency);
    }

    cout << cnt;
    return 0;
}
