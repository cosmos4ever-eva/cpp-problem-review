#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrime(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2; j <= n / i; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    return primes;
}

long long countOne(long long prime, int cnt) {
    long long total = 1;
    for (int i = 0; i < cnt; i++) {
        total = total * prime + 1;
    }
    return total;
}

long long countSum(int n) {
    vector<int> primes = getPrime(static_cast<int>(sqrt(n)));
    long long sum = 1;
    int remaining = n;

    for (int prime : primes) {
        int cnt = 0;
        while (remaining % prime == 0) {
            cnt++;
            remaining /= prime;
        }
        if (cnt > 0) {
            sum *= countOne(prime, cnt);
        }
    }

    if (remaining > 1) {
        sum *= remaining + 1LL;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << countSum(n);
    return 0;
}
