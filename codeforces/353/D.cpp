// Date: 2025-03-27
// Time: 10:17:53
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int ans = 0, m = 0;
    for (auto x : s)
    {
        if (x == 'M')
            m++;
        else if (m)
            ans = max(ans + 1, m);
    }
    cout << ans << '\n';
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