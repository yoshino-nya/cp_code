// Date: 2025-03-01
// Time: 21:12:31

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    set<pair<int, int>> edges;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges.insert({ u, v });
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long> cost(n + 1, 1e18);
    vector<vector<long long>> dis(n + 1, vector<long long>(2, 1e18));
    dis[1][0] = 0;
    auto dijkstra = [&]() {
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> pq;
        pq.push({ 0, 1, 0 }); // 距离 编号 状态
        while (!pq.empty()) {
            auto [d, u, rev] = pq.top();
            pq.pop();
            if (d > dis[u][rev])
                continue;
            for (auto v : adj[u]) {
                if (rev) {
                    if (edges.contains({ v, u })) {
                        if (dis[u][rev] + 1 < dis[v][rev]) {
                            dis[v][rev] = dis[u][rev] + 1;
                            pq.push({ dis[v][rev], v, rev });
                        }
                    } else {
                        if (dis[u][rev] + x + 1 < dis[v][rev ^ 1]) {
                            dis[v][rev ^ 1] = dis[u][rev] + x + 1;
                            pq.push({ dis[v][rev ^ 1], v, rev ^ 1 });
                        }
                    }
                } else {
                    if (edges.contains({ u, v })) {
                        if (dis[u][rev] + 1 < dis[v][rev]) {
                            dis[v][rev] = dis[u][rev] + 1;
                            pq.push({ dis[v][rev], v, rev });
                        }
                    } else {
                        if (dis[u][rev] + x + 1 < dis[v][rev ^ 1]) {
                            dis[v][rev ^ 1] = dis[u][rev] + x + 1;
                            pq.push({ dis[v][rev ^ 1], v, rev ^ 1 });
                        }
                    }
                }
            }
        }
    };
    dijkstra();
    cout << min(dis[n][0], dis[n][1]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}