#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<string> result;
string output;
vector<char> left_bracket;
int n = 0,left_num = 0;

void DFS(int idx){
   if(left_num > n/2){
       return;
   }
   if(idx == n && left_bracket.empty()){
       result.push_back(output);
       return;
   }

   output.push_back('[');
   left_bracket.push_back('[');
   left_num++;
   DFS(idx + 1);
   output.pop_back();
   left_bracket.pop_back();
   left_num--;

   if(!left_bracket.empty() && left_bracket.back() == '['){
       output.push_back(']');
       left_bracket.pop_back();
       DFS(idx + 1);
       output.pop_back();
       left_bracket.push_back('[');
   }

   output.push_back('{');
   left_bracket.push_back('{');
   left_num++;
   DFS(idx + 1);
   output.pop_back();
   left_bracket.pop_back();
   left_num--;

   if(!left_bracket.empty() && left_bracket.back() == '{'){
       output.push_back('}');
       left_bracket.pop_back();
       DFS(idx + 1);
       output.pop_back();
       left_bracket.push_back('{');
   }
}

int main(){
   cin >> n;

   DFS(0);
   for(int i = 0;i < result.size();i++){
       cout << result[i] << "\n";
   }
   return 0;
}
