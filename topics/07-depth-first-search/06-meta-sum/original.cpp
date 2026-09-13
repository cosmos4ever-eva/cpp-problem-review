#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

vector<int> a;
set<int> result;
int output;
int n = 0;

void DFS(int idx){
   if(idx == n){
       result.insert(output);
       return;
   }

   output += a[idx];
   DFS(idx + 1);
   output -= a[idx];

   output -= a[idx];
   DFS(idx + 1);
   output += a[idx];
}

int main(){
   cin >> n;
   a.resize(n);
   for(int i = 0;i < n;i++){
       cin >> a[i];
   }

   DFS(0);
   for(int x : result){
       cout << x << "\n";
   }
   return 0;
}
