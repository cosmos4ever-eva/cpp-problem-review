#include<iostream>
#include<vector>
const int MAXN = 100;
using namespace std;

int main(){
   int n = 0;
   cin >> n;
   int a[MAXN] = {0};
   int dp[MAXN] = {0};
   for(int i = 0;i < n;i ++){
       cin >> a[i];
   }

   int max_dp = 1;
   for(int i = 0;i < n;i ++){
       dp[i] = 1;
       for(int j = 0;j < i;j++){
           if(a[j] <= a[i]) dp[i] = max(dp[i],dp[j] + 1);
       }
       if(dp[i] > max_dp) max_dp = dp[i];
   }

   cout << max_dp;
   return 0;
}
