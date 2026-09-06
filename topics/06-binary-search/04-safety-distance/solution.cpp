#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n = 0,m = 0;
vector<int> c;
vector<int> d;

int finddis(const vector<int>& d,int cite){

    int l = 0,r = m-1,answer = 0,mid = 0;

    while(l <= r){
        mid = l+(r-l)/2;
        if(d[mid] <= cite){
            answer = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return min(cite - d[answer],d[answer+1] - cite);
}

int main(){
    cin >> n >> m;
    c.resize(n);
    d.resize(m);

    for(int i = 0;i < n;i++){
        cin >> c[i];
    }
    for(int i = 0;i < m;i++){
        cin >> d[i];
    }

    sort(d.begin(),d.end());

    int max_dis = 0;
    for(int i = 0;i < n;i ++){
        int dis = 0;

        if(c[i] < d[0]) dis = d[0] - c[i];
        else if(c[i] >= d[m-1]) dis = c[i] - d[m-1];
        else dis = finddis(d,c[i]);

        max_dis = max(max_dis,dis);
    }

    cout << max_dis;
    return 0;
}
