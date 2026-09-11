#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 10001;

int main(){
   int n = 0;
   cin >> n;
   int a[MAXN] = {0};
   int dp[MAXN] = {0};
   int max_dp = 0;
   for(int i = 0;i < n;i ++){
       cin >> a[i];
       if(i == 0) {
           dp[i] = a[i];
           max_dp = a[i];
       }
       else dp[i] = max(a[i],dp[i-1]+a[i]);
       if(dp[i] > max_dp) max_dp = dp[i];
   }

   cout << max_dp;
   return 0;
}
