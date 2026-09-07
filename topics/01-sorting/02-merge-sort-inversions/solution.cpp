#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n = 8;

int mergecount(vector<int>& a,vector<int>& tmp,int l,int r,int mid){
    int i = l,j = mid + 1,k = l,cnt = 0;

    while(i <= mid && j <= r){
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else{
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while(i <= mid){
        tmp[k++] = a[i++];
    }
    while(j <= r){
        tmp[k++] = a[j++];
    }

    for(int k = l;k <= r;k ++){
        a[k] = tmp[k];
    }

    return cnt;
}

int mergesort(vector<int>& a){
    vector<int> tmp(8);
    int cnt = 0;

    for(int size = 1;size < 8;size *=2){
        for(int l = 0;l < 8 - size;l += 2 * size){
            int mid = min(l + size - 1,n - 1);
            int r = min(l + 2 * size - 1,n - 1);
            cnt += mergecount(a,tmp,l,r,mid);
        }

        for(int i = 0;i < 8;i ++){
            if(i != 0) cout << " ";
            cout << tmp[i];
        }
        cout << "\n";
    }

    return cnt;
}

int main(){
    vector<int> a(8);
    for(int i = 0;i < 8;i ++){
        cin >> a[i];
    }

    int sum = mergesort(a);
    cout << sum;

    return 0;
}
