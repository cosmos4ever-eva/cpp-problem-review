#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int a = 0;
    cin >> a;
    double l = -100.0,r = 100.0;
    double EPS = 1e-6;
    double mid = 0;

    while(r - l > EPS){
        mid = (l+r)/2;
        if(mid * mid * mid + mid * mid + mid > a) r = mid ;
        else l = mid;
    }

    printf("%.2f",mid);
    return 0;

}
