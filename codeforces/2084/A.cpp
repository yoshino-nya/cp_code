// Date: 2025-04-05
// Time: 22:36:27
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        // n 1 2
        cout << n << " ";
        for (int i = 1; i <= n - 1; i++)
            cout << i << " ";
        cout << '\n';
    }
    else
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