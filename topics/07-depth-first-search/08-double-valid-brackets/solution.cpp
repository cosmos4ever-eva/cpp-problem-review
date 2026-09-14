#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> result;
string output;
vector<char> leftBrackets;

int n;
int leftCount = 0;

void DFS(int idx) {
    // 长度达到 n 后必须停止；只有栈为空时才是合法方案。
    if (idx == n) {
        if (leftBrackets.empty()) {
            result.push_back(output);
        }
        return;
    }

    // 按字符顺序依次尝试 '['、']'、'{'、'}'，自然得到字典序。
    if (leftCount < n / 2) {
        output.push_back('[');
        leftBrackets.push_back('[');
        leftCount++;

        DFS(idx + 1);

        leftCount--;
        leftBrackets.pop_back();
        output.pop_back();
    }

    // 右中括号只能匹配栈顶的左中括号。
    if (!leftBrackets.empty() && leftBrackets.back() == '[') {
        output.push_back(']');
        leftBrackets.pop_back();

        DFS(idx + 1);

        leftBrackets.push_back('[');
        output.pop_back();
    }

    if (leftCount < n / 2) {
        output.push_back('{');
        leftBrackets.push_back('{');
        leftCount++;

        DFS(idx + 1);

        leftCount--;
        leftBrackets.pop_back();
        output.pop_back();
    }

    // 右大括号只能匹配栈顶的左大括号。
    if (!leftBrackets.empty() && leftBrackets.back() == '{') {
        output.push_back('}');
        leftBrackets.pop_back();

        DFS(idx + 1);

        leftBrackets.push_back('{');
        output.pop_back();
    }
}

int main() {
    cin >> n;

    DFS(0);

    for (const string& brackets : result) {
        cout << brackets << '\n';
    }

    return 0;
}
