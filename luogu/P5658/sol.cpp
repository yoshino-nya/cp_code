// Date: 2025-04-01
// Time: 20:39:42
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<ll>> adj(n + 1, vector<ll>());
    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        fa[i] = x;
        adj[x].push_back(i);
    }
    s = " " + s;
    vector<int> stk, lst(n + 1);
    vector<long long> sum(n + 1);

    auto dfs = [&](auto &&self, int u, int pre) -> void
    {
        int tmp = 0;
        if (s[u] == ')')
        {
            if (!stk.empty())
            {
                tmp = stk.back();
                stk.pop_back();
                lst[u] = lst[fa[tmp]] + 1;
            }
        }
        else
            stk.push_back(u);
        sum[u] = sum[pre] + lst[u];
        for (auto v : adj[u])
        {
            if (v == pre)
                continue;
            self(self, v, u);
        }
        if (tmp)
            stk.push_back(tmp);
        else if (!stk.empty())
            stk.pop_back();
    };
    dfs(dfs, 1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans ^= (1LL * i * sum[i]);
    }
    cout << ans << '\n';
}
/*
(()()())
*/

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