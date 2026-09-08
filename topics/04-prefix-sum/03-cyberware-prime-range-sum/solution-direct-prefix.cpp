#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 10000000;

vector<bool> getPrimeTable(){
    vector<bool> isPrime(MAXN + 1,true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2;i <= MAXN / i;i++){
        if(isPrime[i]){
            for(int j = i * i;j <= MAXN;j += i){
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

vector<long long> getPreSum(const vector<bool>& isPrime){
    vector<long long> preSum(MAXN + 1);

    for(int i = 1;i <= MAXN;i++){
        preSum[i] = preSum[i-1];
        if(isPrime[i]){
            preSum[i] += i;
        }
    }

    return preSum;
}

int main(){
    int q = 0;
    cin >> q;

    vector<bool> isPrime = getPrimeTable();
    vector<long long> preSum = getPreSum(isPrime);

    for(int i = 0;i < q;i++){
        int L = 0;
        int R = 0;
        cin >> L >> R;

        if(i != 0) cout << "\n";
        cout << preSum[R] - preSum[L-1];
    }

    return 0;
}
