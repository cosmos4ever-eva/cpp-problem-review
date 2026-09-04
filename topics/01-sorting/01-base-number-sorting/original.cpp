#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int b = 0;
    string s;
    int id = 0;
    long long value = 0;

    Node(int _b, string _s, int _id, long long _value) {
        b = _b;
        s = _s;
        id = _id;
        value = _value;
    }
};

int getdigit(char c) {
    if (c <= '9') return c - '0';
    return c - 'A' + 10;
}

long long transfer(int b, string s) {
    long long sum = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        sum = sum * b + getdigit(s[i]);
    }
    return sum;
}

bool cmp(Node a, Node b) {
    if (a.value != b.value) return a.value < b.value;
    return a.id < b.id;
}

int main() {
    int n = 0;
    int b = 0;
    string s;
    vector<Node> v;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> b >> s;
        long long value = transfer(b, s);
        v.push_back(Node(b, s, i, value));
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout << v[i].b << " " << v[i].s;
        if (i != n - 1) printf("\n");
    }
    return 0;
}
