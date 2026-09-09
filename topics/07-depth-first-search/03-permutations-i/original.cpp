#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> output;
vector<bool> exist;
int n = 0;

void DFS(int idx){
   if(idx == n + 1){
       result.push_back(output);
       return;
   }

   for(int i = 1;i <= n;i++){
       if (exist[i] == true) continue;

       output.push_back(i);
       exist[i] = true;
       idx++;

       DFS(idx);

       output.pop_back();
       exist[i] = false;
       idx--;
   }
}

int main(){
   cin >> n;
   exist.resize(n+1);

   DFS(1);

   for(int i = 0;i < result.size();i++){
       if(i != 0) cout << "\n";
       for(int j = 0;j < result[i].size();j++){
           if(j != 0) cout << " ";
           cout << result[i][j];
       }
   }

   return 0;
}
