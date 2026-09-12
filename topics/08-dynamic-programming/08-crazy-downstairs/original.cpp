#include<iostream>
#include<algorithm>
#include<cstring>
const int MAXN = 10001;
using namespace std;

int main(){
   int n,k,b;
   cin >> n >> k >> b;
   bool a[MAXN];
   memset(a,true,sizeof(a));

   for(int i = 1;i <= b;i++){
       int m = 0;
       cin >> m;
       a[m] = false;
   }

   int dp[MAXN];
   memset(dp,0,sizeof(dp));
   dp[0] = 1;

   for(int i = 1;i <= n;i++){
       if(a[i] == false) dp[i] = 0;
       else{
           for(int j = 1;j <= k;j++){
               if(j > i) break;
               dp[i] = (dp[i] + dp[i-j]) % (int)(1e9 + 7);
           }
       }
   }

   cout << dp[n];
   return 0;

}
