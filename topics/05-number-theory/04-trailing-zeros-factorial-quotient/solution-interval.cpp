#include<iostream>
#include<algorithm>
using namespace std;

int countfactor(int n,int p){
    int cnt = 0;
    while(n % p == 0){
        cnt++;
        n /= p;
    }
    return cnt;
}

int g(int a,int b){
    int count2 = 0;
    int count5 = 0;

    for(int i = b + 1;i <= a;i++){
        count2 += countfactor(i,2);
        count5 += countfactor(i,5);
    }

    return min(count2,count5);
}

int main(){
    int a = 0,b = 0;
    cin >> a >> b;
    cout << g(a,b);
    return 0;
}
