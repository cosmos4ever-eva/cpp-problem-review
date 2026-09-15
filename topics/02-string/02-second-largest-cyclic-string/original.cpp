#include<iostream>
#include<string>
using namespace std;

int main(){
   string s;
   cin >> s;
   string firstMax = s,secondMax = "";
   for(int i = 0;i < s.size();i++){
       s.push_back(s[0]);
       s.erase(s.begin());
       if(s > firstMax){
           secondMax = firstMax;
           firstMax = s;
       }
       if(s < firstMax && s > secondMax) secondMax = s;
   }

   cout << secondMax;
   return 0;
}
