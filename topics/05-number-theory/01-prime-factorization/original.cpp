#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> getPrime(int n){
    vector<int> primes;
    vector<bool> isPrime(n+1,true);

    for(int i = 2;i <= n;i ++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = 2; j <= n/i;j ++){
                isPrime[i*j] = false;
                break;
            }
        }
    }
    return primes;
}

void factorize(int n,vector<int> primes){
    bool isFirst = true;
    int div = n;
    for(int i = 0;i < primes.size();i ++){
        if(div % primes[i] == 0){
            int cnt = 0;
            while(div % primes[i] == 0){
                div /= primes[i];
                cnt++;
            }
            if(!isFirst) cout << "\n";
            else isFirst = false;
            cout << primes[i] << " " << cnt;
        }
    }
}

int main(){
    int n = 0;
    cin >> n;

    vector<int> primes = getPrime(n);
    factorize(n,primes);

    return 0;
}
