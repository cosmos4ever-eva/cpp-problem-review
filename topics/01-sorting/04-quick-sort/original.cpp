#include<iostream>
#include<vector>
using namespace std;

vector<int> a;
int n = 0;

void quicksort(vector<int>& a,int l,int r){
    if(l >= r) return ;

    int pivot = a[l + (r - l)/2];
    int i = l - 1,j = r + 1;
    while(i < j){
        do i++ ; while (pivot > a[i]);
        do j-- ; while (pivot < a[j]);
        if(i < j) swap(a[i],a[j]);
    }

    quicksort(a,l,j);
    quicksort(a,j+1,r);
}

int main(){
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    quicksort(a,0,n-1);

    for(int i = 0;i < n;i++){
        if(i != 0) cout << " ";
        cout << a[i];
    }

    return 0;
}
