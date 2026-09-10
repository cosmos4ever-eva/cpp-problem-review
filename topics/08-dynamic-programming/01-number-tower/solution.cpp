#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 101;

int a[MAXN][MAXN] = {0};
int dp[MAXN][MAXN] = {0};

int main(){
   int n = 0;
   cin >> n;

   for(int i = 1;i <= n;i ++){
       for(int j = 1;j <= i;j ++){
           cin >> a[i][j];
       }
   }

   for(int i = 1;i <= n;i ++){
       dp[n][i] = a[n][i];
   } 

   for(int i = n-1;i >= 1;i--){
       for(int j = 1;j <= i;j ++){
           dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + a[i][j];
       }
   }

   cout << dp[1][1];
   return 0;      
}
