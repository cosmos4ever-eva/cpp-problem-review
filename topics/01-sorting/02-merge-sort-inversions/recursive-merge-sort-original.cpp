#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int n = 0;

void merge(int l1,int r1,int l2,int r2){
    int L=l1,R=l2;
    int i=0;

    vector<int> tmp(r2-l1+1);

    while(L<=r1 && R<=r2){
        if(a[L]<=a[R])
            tmp[i++]=a[L++];
        else
            tmp[i++]=a[R++];
    }

    while(L<=r1)
        tmp[i++]=a[L++];

    while(R<=r2)
        tmp[i++]=a[R++];

    for(int k=l1;k<=r2;k++)
        a[k]=tmp[k-l1];
}

void mergesort(int l,int r){
    if(l >= r) return;
    int mid = l + (r - l) / 2;
    mergesort(l,mid);
    mergesort(mid + 1,r);

    merge(l,mid,mid+1,r);
}

int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    mergesort(0,n-1);

    for(int i = 0;i < n;i++){
        if (i != 0) cout << " ";
        cout << a[i];
    }

    return 0;
}
