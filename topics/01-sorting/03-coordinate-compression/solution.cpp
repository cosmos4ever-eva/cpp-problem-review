#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
   int n = 0;
   cin >> n;
   vector<int> a(n);
   for(int i = 0;i < n;i++){
       cin >> a[i];
   }

   vector<int> b = a;
   sort(a.begin(),a.end());
   a.erase(unique(a.begin(),a.end()),a.end());

   unordered_map<int,int> rank;
   rank[a[0]] = 0;
   for(int i = 1;i < a.size();i++){
       rank[a[i]] = rank[a[i-1]] + 1;
   }

   for(int i = 0;i < n;i++){
       if(i != 0) cout << " ";
       cout << rank[b[i]];
   }

   return 0;
}
