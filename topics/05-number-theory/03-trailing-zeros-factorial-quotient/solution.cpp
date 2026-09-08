#include<iostream>
#include<algorithm>
using namespace std;

long long countFactorInFactorial(int n,int p){
    long long cnt = 0;

    while(n > 0){
        n /= p;
        cnt += n;
    }

    return cnt;
}

long long g(int a,int b){
    long long count2 =
        countFactorInFactorial(a,2) - countFactorInFactorial(b,2);

    long long count5 =
        countFactorInFactorial(a,5) - countFactorInFactorial(b,5);

    return min(count2,count5);
}

int main(){
    int a = 0,b = 0;
    cin >> a >> b;
    cout << g(a,b);
    return 0;
}
