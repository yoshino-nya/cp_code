// Date: 2025-03-25
// Time: 19:09:05
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, cnt = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            ans = max(ans, cnt + 1);
            cnt = 1;
        }
        else
            cnt++;
    }
    ans = max(cnt + 1, ans);
    cout << ans << '\n';
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