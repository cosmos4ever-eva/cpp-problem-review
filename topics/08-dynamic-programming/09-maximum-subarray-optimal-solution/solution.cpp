#include<iostream>
#include<algorithm>
const int MAXN = 10001;
using namespace std;

int main(){
   int n = 0;
   cin >> n;
   int a[MAXN];
   for(int i= 1;i <= n;i++){
       cin >> a[i];
   }

   int dp[MAXN],start[MAXN];
   dp[1] = a[1];
   start[1] = 1;
   int max_sum = a[1],l = 10001,r = 1;
   for(int i = 2;i <= n;i ++){
       dp[i] = max(dp[i-1] + a[i],a[i]);
       if(dp[i-1] >= 0) start[i] = start[i-1];
       else start[i] = i;
       if(dp[i] > max_sum){
           max_sum = dp[i];
       }
   }

   for(int i = 1;i <= n;i++){
       if (dp[i] == max_sum) {
           if(start[i] < l) {
               l = start[i];
               r = i;
           }
       }
   }

   cout << max_sum << " " << l << " " << r;
   return 0;

}
