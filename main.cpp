
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    return 0;
}

char valToChar(int v) {
    if (v >= 0 && v <= 9) return v + '0';
    return v - 10 + 'A';
}

int main() {
    int m, n, B;
    if (!(cin >> m >> n >> B)) return 0;
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = m - 1;
    int len2 = n - 1;
    int L = max(len1, len2);

    // Pad with leading zeros
    string s1 = string(L - len1, '0') + str1;
    string s2 = string(L - len2, '0') + str2;

    string res = "";
    int carry = 0;
    for (int i = L - 1; i >= 0; --i) {
        int v1 = charToVal(s1[i]);
        int v2 = charToVal(s2[i]);
        int sum = v1 + v2 + carry;
        res += valToChar(sum % B);
        carry = sum / B;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
