#include <algorithm>
#include <vector>
using namespace std;

int smallestIndex(int a[], int n) {
    int index = 0,max_index = a[0];
    vector<int> min_index(n);
    min_index[n-1] = a[n-1];
    for(int i = n - 2;i >= 0;i--){
        min_index[i] = min(a[i],min_index[i+1]);
    }

    for(int i = 0;i < n-1;i ++){
        max_index = max(max_index,a[i]);
        if(max_index <= min_index[i+1]) {
            return i;
        }
    }

    return n-1;
}
