#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
   if(b == 0) return a;
   else return gcd(b,a % b);
}

int main(){
   int a = 0,b = 0;
   cin >> a >> b;

   cout << gcd(a,b);
   return 0;
}
