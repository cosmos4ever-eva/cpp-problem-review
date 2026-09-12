#include<iostream>
#include<string>
#include<cstring>
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

   for(int i = 1;i <= n;i++){
       for(int j = 0;j <= v;j++){
           if(w[i] > j) dp[i][j] = dp[i-1][j];
           else dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + c[i]);
       }
   }

   cout << dp[n][v];
   return 0;

}
