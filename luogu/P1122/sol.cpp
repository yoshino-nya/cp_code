// Date: 2025-04-01
// Time: 19:00:04
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> dp[i];
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto &&self, int u, int pre)->void
    {
        for (auto v : adj[u])
        {
            if (v == pre)
                continue;
            self(self, v,u);
            if (dp[v] > 0)
                dp[u] += dp[v];
        }
    };
    dfs(dfs,1,0);
    cout<<*max_element(dp.begin()+1,dp.end())<<'\n';
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