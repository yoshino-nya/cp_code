// Date: 2025-03-11
// Time: 22:41:51

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int x;
    cin >> x;
    // x+y>=x^y
    // 111
    // 101
    // 010
    for (int i = 30; i >= 1; i--) {
        if (x >> i & 1) {
            int y = (1 << i) - 1;
            int z = x ^ y;
            if ((x != y) && z < x + y && x + z > y && y + z > x) {
                cout << y << '\n';
                return;
            }
        }
    } // 11
    // 01
    // 10
    cout << "-1\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}