#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 10000;

int main(){
   int n = 0;
   cin >> n;
   int a[MAXN] = {0};
   int dp[MAXN][2];
   for(int i = 0;i < n;i++){
       cin >> a[i];
   }

   dp[0][0] = a[0];
   dp[0][1] = a[0];
   for(int i = 1;i < n;i++){
       dp[i][0] = max(dp[i-1][0]+a[i],a[i]);
       dp[i][1] = max(dp[i-1][1]+a[i],dp[i-1][0]);
   }

   int max_sum = a[0];
   for(int i = 0;i < n;i++){
       if(dp[i][0] > max_sum) max_sum = dp[i][0];
       if(dp[i][1] > max_sum) max_sum = dp[i][1];
   }

   cout << max_sum;
   return 0;
}
