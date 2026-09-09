#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> output;
int n = 0,k = 1;

void DFS(int idx,int k){
   if(k == 0){
       result.push_back(output);
       return;
   }
   if(idx == n + 1){
       return;
   }

   output.push_back(idx);
   DFS(idx + 1,k - 1);
   output.pop_back();

   DFS(idx + 1,k);
}

int main(){
   cin >> n >> k;

   DFS(1,k);

   for(int i = 0;i < result.size();i++){
       if(i != 0) cout << "\n";
       for(int j = 0;j < result[i].size();j++){
           if(j != 0) cout << " ";
           cout << result[i][j];
       }
   }

   return 0;
}
