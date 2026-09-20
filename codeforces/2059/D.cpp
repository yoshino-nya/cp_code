#include <bits/stdc++.h>
using namespace std;

void man()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<vector<int>> g1(n + 1, vector<int>()), g2(n + 1, vector<int>());
    // set<pair<int, int>> e1, e2;
    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    int m1, m2;
    cin >> m1;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        g1[u].push_back(v);
        g1[v].push_back(u);
        cnt[u][v]++;
    }
    cin >> m2;
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        g2[u].push_back(v);
        g2[v].push_back(u);
        cnt[u][v]++;
    }
    vector<bool> vis(n + 1);
    // vector<vector<bool>> viss(n + 1, vector<bool>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (cnt[i][j] == 2)
                vis[i] = true, vis[j] = true;
        }
    }
    priority_queue<array<long long, 3>> q;
    vector<vector<long long>> cost(n + 1, vector<long long>(n + 1, 1000000000000000000));
    cost[s1][s2] = 0;
    q.push({0, s1, s2});
    while (!q.empty())
    {
        auto [d, v1, v2] = q.top();
        // cerr << v1 << " " << v2 << '\n';

        q.pop();
        if (cost[v1][v2] < -d)
            continue;
        for (auto u1 : g1[v1])
        {
            for (auto u2 : g2[v2])
            {
                int x = abs(u1 - u2);
                if (cost[u1][u2] > cost[v1][v2] + x)
                {
                    cost[u1][u2] = cost[v1][v2] + x;
                    q.push({-cost[u1][u2], u1, u2});
                }
            }
        }
    }
    long long ans = 1000000000000000000;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            ans = min(ans, cost[i][i]);
    }
    if (ans == 1000000000000000000)
        cout << "-1\n";
    else
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        man();
    return 0;
}