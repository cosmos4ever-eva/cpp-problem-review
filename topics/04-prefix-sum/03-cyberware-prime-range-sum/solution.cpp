#include<iostream>
#include<vector>
using namespace std;

vector<int> getPrime(int n){
    vector<int> primes;
    vector<int> isPrime(n+1,true);

    for(int i = 2;i <= n;i ++){
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2; j <= n/i ; j ++){
                isPrime[i * j] = false;
            }
        }
    }
    return primes;
}

vector<long long> getPrefixPrime(const vector<int>& primes){
    vector<long long> prefix_primes(10000001);
    long long sum = 2;
    prefix_primes[2] = 2;
    for(int i = 1;i < primes.size();i++){
        for(int j = primes[i-1];j < primes[i];j ++){
            prefix_primes[j] = sum;
        }
        sum += primes[i];
    }
    for(int j = primes[primes.size()-1];j <= 10000000;j++){
        prefix_primes[j] = sum;
    }

    return prefix_primes;
}

int main(){
    int q = 0;
    cin >> q;
    vector<int> primes = getPrime(10000000);
    vector<long long> prefix_primes = getPrefixPrime(primes);

    for(int i = 0;i < q;i++){
        int L = 0;
        int R = 0;
        cin >> L >> R;

        if(i != 0) cout << "\n";
        cout << prefix_primes[R] - prefix_primes[L-1];
    }

    return 0;
}
