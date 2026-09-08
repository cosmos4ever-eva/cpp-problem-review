#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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

vector<int> getNeighborPrime(const vector<int>& primes){
    vector<int> neighborprimes;

    for(int i = 1;i < primes.size() - 1;i++){
        if(primes[i] - primes[i-1] == primes[i+1] - primes[i]){
            neighborprimes.push_back(primes[i]);
        }
    }
    return neighborprimes;
}

int main(){
    int T = 0;
    cin >> T;
    vector<int> N(T);
    vector<int> primes = getPrime(10001000);
    vector<int> neighborprimes = getNeighborPrime(primes);

    for(int i = 0;i < T;i++){
        cin >> N[i];
        if(i != 0) cout << "\n";

        auto it = lower_bound(neighborprimes.begin(),neighborprimes.end(),N[i]);
        if(it != neighborprimes.end() && *it == N[i]){
            cout << "Yes";
        }
        else if(it != neighborprimes.end()){
            cout << "No" << " " << *it;
        }
    }

    return 0;
}
