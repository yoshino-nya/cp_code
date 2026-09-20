// Date: 2025-03-22
// Time: 20:00:57
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        for (int i = 1; i <= n / 2; i++)
            cout << "-";
        cout << "=";
        for (int i = 1; i <= n / 2; i++)
            cout << "-";
    }else{
        for (int i = 1; i < n / 2; i++)
            cout << "-";
        cout << "==";
        for (int i = 1; i < n / 2; i++)
            cout << "-";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}