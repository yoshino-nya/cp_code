#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-26
{                      // Time: 15:47:16 
    int n;
    cin >> n;
    int sum = (1 << (n + 1)) - 2;
    int x = (1 << n);
    for(int i = 1; i < n / 2; i++)
        x += 1 << i;
    cout << 2 * x - sum << '\n';
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