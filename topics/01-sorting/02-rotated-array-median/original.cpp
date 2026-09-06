#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int n = 0;

int findMin(vector<int> a){
    int mid = 0;
    for(int i = 0;i < n;i ++){
        int l = 0;
        int r = n-1;
        while(l <= r){
            mid = (l+r) / 2;
            if(a[mid] < a[mid-1]) return mid;
            else if(a[mid] > a[n-1]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return mid;
}

int main(){

    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i ++){
        cin >> a[i];
    }

    int min = findMin(a);
    if(n % 2 == 1){
        int mid = (n / 2 + min) % n;
        printf("%.1f", (double)a[mid]);
    }
    else{
        int mid1 = (n / 2 + min - 1) % n;
        int mid2 = (n / 2 + min) % n;
        printf("%.1f",((double)a[mid1]+(double)a[mid2]) / 2);
    }

    return 0;
}
