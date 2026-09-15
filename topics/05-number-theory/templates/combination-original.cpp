#include<iostream>
using namespace std;

int main(){
    int n = 0,m = 0;
    cin >> n >> m;
    long long total = 1;

    for(int i = 1;i <= m;i++){
        total = total * (n - m + i) / i;
    }

    cout << total;
    return 0;
}
