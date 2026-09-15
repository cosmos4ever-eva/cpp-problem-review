#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
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

int count_one(int prime,int cnt){
    int total = 1;
    for(int i = 0;i < cnt;i++){
        total = (total * prime) + 1;
    }
    return total;
}

int countsum(int n){
    vector<int> primes = getPrime(sqrt(n));
    int sum = 1,div = n;

    for(int i = 0;i < primes.size();i++){
        int cnt = 0;
        while(div % primes[i] == 0){
            cnt++;
            div /= primes[i];
        }
        if(cnt) sum *= count_one(primes[i],cnt);
    }

    if(div > 1) sum *= (div + 1);

    return sum;
}

int main(){
    int n = 0;
    cin >> n;
    cout << countsum(n);
    return 0;
}
