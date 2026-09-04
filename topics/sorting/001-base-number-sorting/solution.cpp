#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Number {
    int base;
    string text;
    long long value;
};

int charToDigit(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

long long convertToDecimal(int base, const string& text) {
    long long value = 0;
    for (char c : text) {
        value = value * base + charToDigit(c);
    }
    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Number> numbers;
    numbers.reserve(n);

    for (int i = 0; i < n; ++i) {
        int base;
        string text;
        cin >> base >> text;
        numbers.push_back({base, text, convertToDecimal(base, text)});
    }

    stable_sort(numbers.begin(), numbers.end(),
                [](const Number& lhs, const Number& rhs) {
                    return lhs.value < rhs.value;
                });

    for (const Number& number : numbers) {
        cout << number.base << ' ' << number.text << '\n';
    }

    return 0;
}
