#include<iostream>
#include<string>
using namespace std;
const int MAXN = 101;

int main(){
   string s1,s2;
   cin >> s1 >> s2;

   int dp[MAXN][101] = {0};
   int max_len = 0;
   for(int i = 1;i <= s1.size();i++){
       for(int j =1;j <= s2.size();j++){
           if(s2[j-1] == s1[i-1]) dp[i][j] = dp[i-1][j-1] + 1;
           else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
       }
   }

   cout << dp[s1.size()][s2.size()];
   return 0;
}
