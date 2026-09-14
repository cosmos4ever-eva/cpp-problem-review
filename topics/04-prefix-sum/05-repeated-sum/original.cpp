#include<iostream>
#include<algorithm>
#include<unordered_map>
const int MAXN = 1001;
using namespace std;

int k = 0;
long long n = 0;
long long prefix[MAXN];

long long getPrefix(int m){
    return prefix[n] * (m / n) + prefix[m % n];
}

int main(){
    cin >> n >> k;
    int l = 0,r = 0;
    cin >> l >> r;
    int a[MAXN];

    prefix[0] = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
    }

    cout << getPrefix(r+1) - getPrefix(l);
    return 0;
}
