#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>> result;
vector<int> output;
int n = 0;

void DFS(int idx){
    if(idx == n) {
        result.push_back(output);
        return;
    }

    output.push_back(0);
    DFS(idx + 1);
    output.pop_back();

    output.push_back(1);
    DFS(idx + 1);
    output.pop_back();
}

int main(){
    cin >> n;
    DFS(0);

    for(int i = 0;i < result.size();i++){
        if(i != 0) cout << "\n";
        for(int j = 0;j < result[i].size();j++){
            cout << result[i][j];
        }
    }

    return 0;
}
