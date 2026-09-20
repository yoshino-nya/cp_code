// Date: 2025-03-23
// Time: 13:35:56
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int a, x, y;
    cin >> x >> y >> a;
    a++;
    a %= (x + y);
    if (a == 0)
    {
        cout << "YES\n";
    }
    else if (a <= x)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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