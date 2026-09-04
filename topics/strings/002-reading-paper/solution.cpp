#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string compressRuns(const string& word) {
    string compressed;
    compressed.reserve(word.size());

    for (char c : word) {
        if (compressed.empty() || compressed.back() != c) {
            compressed.push_back(c);
        }
    }

    return compressed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> compressedWords;
    compressedWords.reserve(n);

    unordered_map<string, int> frequency;
    frequency.reserve(n);

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        string compressed = compressRuns(word);
        compressedWords.push_back(compressed);
        ++frequency[compressed];
    }

    string answer;
    int maxCount = 0;

    for (const string& word : compressedWords) {
        if (frequency[word] > maxCount) {
            maxCount = frequency[word];
            answer = word;
        }
    }

    cout << answer << '\n';
    return 0;
}
