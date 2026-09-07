#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
    int a;
    int b;
};

bool cmp(Node a, Node b){
    return a.a < b.a;
}

int main(){
    int N = 0;
    cin >> N;
    vector<Node> cows(N);
    for(int i = 0;i < N;i ++){
        int a = 0;
        int b = 0;
        cin >> cows[i].a >> cows[i].b;
    }

    sort(cows.begin(),cows.end(),cmp);

    vector<int> suffix_min(N);
    suffix_min[N-1] = cows[N-1].b;
    for(int i = N-2;i >= 0;i--){
        suffix_min[i] = min(suffix_min[i+1],cows[i].b);
    }

    int prefix_max = cows[0].b;
    int cnt = 0;
    if(suffix_min[0] < suffix_min[1]) cnt++;
    for(int i = 1;i < N;i ++){
        prefix_max = max(prefix_max,cows[i].b);
        if(cows[i].b == prefix_max && cows[i].b == suffix_min[i]) cnt++;
    }

    cout << cnt;
    return 0;
}
