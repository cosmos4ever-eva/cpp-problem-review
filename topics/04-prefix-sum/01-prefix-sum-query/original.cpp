#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> sum(n);
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        if(i == 0) sum[i] = a[0];
        else sum[i] = sum[i-1] + a[i];
    }

    int k = 0;
    cin >> k;
    for(int i = 0;i < k;i ++){
        int m = 0;
        cin >> m;
        if(i != 0) cout << "\n";
        cout << sum[m-1];
    }

    return 0;
}
