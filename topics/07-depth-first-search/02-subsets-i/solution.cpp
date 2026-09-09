#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> output;
int n = 0;

void DFS(int start,int depth){
   if(depth == 0){
       result.push_back(output);
       return;
   }

   for(int j = start;j <= n - depth + 1;j++){
       output.push_back(j);
       DFS(j + 1,depth - 1);
       output.pop_back();
   }
}

int main(){
   cin >> n;

   for(int i = 0;i <= n;i++){
       DFS(1,i);
   }

   for(int i = 0;i < result.size();i++){
       if(i != 0) cout << "\n";
       for(int j = 0;j < result[i].size();j++){
           if(j != 0) cout << " ";
           cout << result[i][j];
       }
   }

   return 0;
}
