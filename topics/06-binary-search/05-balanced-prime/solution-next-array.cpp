#include<iostream>
#include<vector>
using namespace std;

const int MAX_QUERY = 10000000;
const int SIEVE_LIMIT = 10001000;

vector<int> getPrime(int n){
    vector<int> primes;
    vector<int> isPrime(n+1,true);

    for(int i = 2;i <= n;i ++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2;j <= n / i;j ++){
                isPrime[i * j] = false;
            }
        }
    }
    return primes;
}

vector<int> getNextBalancedPrime(const vector<int>& primes){
    vector<int> nextBalancedPrime(MAX_QUERY + 1);
    int lastBalancedPrime = 0;

    for(int i = 1;i < primes.size() - 1;i++){
        if(primes[i] * 2 == primes[i-1] + primes[i+1]){
            for(int j = lastBalancedPrime + 1;
                j <= primes[i] && j <= MAX_QUERY;
                j++){
                nextBalancedPrime[j] = primes[i];
            }
            lastBalancedPrime = primes[i];
        }
    }

    return nextBalancedPrime;
}

int main(){
    int T = 0;
    cin >> T;

    vector<int> primes = getPrime(SIEVE_LIMIT);
    vector<int> nextBalancedPrime = getNextBalancedPrime(primes);

    for(int i = 0;i < T;i++){
        int N = 0;
        cin >> N;

        if(i != 0) cout << "\n";

        if(nextBalancedPrime[N] == N){
            cout << "Yes";
        }
        else{
            cout << "No" << " " << nextBalancedPrime[N];
        }
    }

    return 0;
}
