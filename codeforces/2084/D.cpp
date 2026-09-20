// Date: 2025-04-07
// Time: 00:29:22
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cout << i % (n - m * k < k ? k : n / (m + 1)) << " \n"[i + 1 == n];
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