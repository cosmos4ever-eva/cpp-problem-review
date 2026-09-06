#include<iostream>
#include<vector>
using namespace std;

int n = 0;

int search_chapter(const vector<int>&start, int note){
    int l = 1,r = n;
    int answer = 0;
    while(l <= r){
        int mid = (l+r)/2;
        // 找到最后一个满足 start[mid] <= note 的位置
        if(start[mid] <= note){
            answer = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return answer;
}

int main(){
    int q = 0;
    cin >> n >> q;

    vector<int> start(n+1);
    start[0] = 0;
    start[1] = 1;
    for(int i = 2;i < n+1;i ++){
        cin >> start[i];
    }

    vector<int> notes(q);
    for(int i = 0;i < q;i ++){
        cin >> notes[i];
        if(i != 0) cout << "\n";
        cout << search_chapter(start, notes[i]);
    }
    return 0;
}
