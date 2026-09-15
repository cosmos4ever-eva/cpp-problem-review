#include<iostream>
using namespace std;

int main(){
    int a= 0,b= 0;
    long long ans = 1;
    cin >> a >> b;
    while(b > 0){
        if(b % 2 == 1) ans *= a;
        a *= a;
        b /= 2;
    }

    cout << ans;
    return 0;
}
