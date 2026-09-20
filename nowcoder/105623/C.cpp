// Date: 2025-03-30
// Time: 20:22:52
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    s = " " + s;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '>')
        {
            if (a[i] <= 0)
                a[i] = 1, ans++;
        }
        else if (s[i] == '<')
        {
            if (a[i] >= 0)
                a[i] = -1, ans++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'Z' && (1LL * a[i] * a[i - 1] <= 0))
        {
            a[i] = a[i - 1];
            ans++;
        }
    }
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