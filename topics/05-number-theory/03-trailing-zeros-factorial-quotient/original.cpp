#include<iostream>
#include<vector>
using namespace std;

int g(int a,int b){
    int cnt = 0;
    for(int i = b + 1;i <= a;i ++){
        if(i % 5 == 0) cnt++;
    }
    return cnt;
}

int main(){
    int a = 0,b = 0;
    cin >> a >> b;
    cout << g(a,b);
}
