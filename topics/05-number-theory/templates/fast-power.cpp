#include <iostream>
using namespace std;

long long fastPower(long long base, long long exponent) {
    long long answer = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            answer *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return answer;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << fastPower(a, b);
    return 0;
}
