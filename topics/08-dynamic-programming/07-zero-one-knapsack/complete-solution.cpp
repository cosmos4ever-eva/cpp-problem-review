#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
const int MAXN = 101;
const int MAXV = 1001;
using namespace std;

int main(){
   int n = 0;
   int v = 0;
   cin >> n >> v;
   int w[MAXN],c[MAXN];
   for(int i = 1;i <= n;i++){
       cin >> w[i];
   }
   for(int i = 1;i <= n;i++){
       cin >> c[i];
   }

   int dp[MAXN][MAXV];
   memset(dp,0,sizeof(dp));

   for(int i = 0;i <= v;i++){
       for(int j = 1;j <= n;j++){
           if(i < w[j]) dp[j][i] = dp[j-1][i];
           else dp[j][i] = max(dp[j-1][i],dp[j][i-w[j]] + c[j]);
       }
   }

   cout << dp[n][v];
   return 0;

}
