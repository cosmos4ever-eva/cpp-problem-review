#include<iostream>
#include<string>
using namespace std;
const int MAXN = 100;

int main(){
   string s;
   cin >> s;
   bool dp[MAXN][MAXN];
   int max_len = 1;
   for(int i = 0;i < s.size();i++){
       dp[i][i] = true;
       if(s[i] == s[i+1]) {
           dp[i][i+1] = true;
           max_len = 2;
       }
   }

   for(int len = 3;len <= s.size();len ++){
       for(int i = 0;i < s.size() - len + 1;i++){
           if(s[i] == s[i + len - 1] && dp[i+1][i + len - 2] == true) {
               dp[i][i + len - 1] = true;
               if(len > max_len) max_len = len;
           }
       }
   }
  
   cout << max_len;
   return 0;
}
