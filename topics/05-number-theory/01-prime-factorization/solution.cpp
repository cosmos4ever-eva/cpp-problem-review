#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> getPrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    if (limit >= 0) {
        isPrime[0] = false;
    }
    if (limit >= 1) {
        isPrime[1] = false;
    }

    for (int i = 2; i <= limit / i; ++i) {
        if (isPrime[i]) {
            for (int multiple = i * i; multiple <= limit; multiple += i) {
                isPrime[multiple] = false;
            }
        }
    }

    vector<int> primes;
    for (int value = 2; value <= limit; ++value) {
        if (isPrime[value]) {
            primes.push_back(value);
        }
    }
    return primes;
}

vector<pair<int, int>> factorize(int n, const vector<int>& primes) {
    vector<pair<int, int>> factors;
    int remaining = n;

    for (int prime : primes) {
        if (prime > remaining / prime) {
            break;
        }

        if (remaining % prime == 0) {
            int exponent = 0;
            while (remaining % prime == 0) {
                remaining /= prime;
                ++exponent;
            }
            factors.push_back({prime, exponent});
        }
    }

    if (remaining > 1) {
        factors.push_back({remaining, 1});
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int limit = static_cast<int>(sqrt(n));
    vector<int> primes = getPrimes(limit);
    vector<pair<int, int>> factors = factorize(n, primes);

    for (const pair<int, int>& factor : factors) {
        cout << factor.first << ' ' << factor.second << '\n';
    }

    return 0;
}
