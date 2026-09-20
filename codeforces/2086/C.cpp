// Date: 2025-04-03
// Time: 23:09:08
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), d(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        r[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // we can only change p[d[i]] to d[i]
        // so we should check d[i]
        // r[p[d[i]]] = 0;
        int x = p[d[i]];
        while (r[x])
        {
            ans++;
            r[x] = 0;
            x = p[x];
        }
        x = d[i];
        while (r[x])
        {
            ans++;
            r[x] = 0;
            x = p[x];
        }
        cout << ans << " \n"[i == n];
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