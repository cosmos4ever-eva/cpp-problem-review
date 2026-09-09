#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> output;
vector<int> input;
int n = 0,k = 0,sum = 0;

void DFS(int idx){
   if(sum == k) {
       result.push_back(output);
       return;
   }
   if(sum > k || idx == n) return;

   output.push_back(input[idx]);
   sum += input[idx];
   DFS(idx);
   output.pop_back();
   sum -= input[idx];

   DFS(idx + 1);
}

int main(){
   cin >> n >> k;
   for(int i = 0;i < n;i++){
       int x = 0;
       cin >> x;
       input.push_back(x);
   }

   DFS(0);

   cout << result.size();

   return 0;
}
