#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<int> a;
int currentor = 0,min_num = 17;
int n = 0,k = 0,len = 0;

void DFS(int idx){
   if(currentor == (1 << k) - 1){
       min_num = min(min_num,len);
       return;
   }
   if(idx == n){
       return;
   }

   int tmp = currentor;
   currentor = currentor | a[idx];
   len++;
   DFS(idx + 1);
   currentor = tmp;
   len--;

   DFS(idx + 1);
}

int main(){
   cin >> n >> k;
   a.resize(n);
   for(int i = 0;i < n;i++){
       cin >> a[i];
   }

   DFS(0);
   if(min_num == 17) cout << -1;
   else cout << min_num;
   return 0;
}
