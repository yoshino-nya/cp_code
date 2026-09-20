#include <iostream>
#include <vector>
#include <cmath>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<int> sz(n + 1);
    long long res = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        long long pairs = 0, triples = 0, sum = 0;
        sz[u] = 1;
        for (int v : g[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        for (int v : g[u])
        {
            if (v == p)
            {
                triples += pairs * (n - sz[u]);
                pairs += sum * (n - sz[u]);
                sum += n - sz[u];
            }
            else
            {
                triples += pairs * sz[v];
                pairs += sum * sz[v];
                sum += sz[v];
            }
        }
        if (int(sqrt(a[u])) != sqrt(a[u]))
            return;
        res += pairs + triples;
    };
    dfs(dfs, 1, -1);
    std::cout << res << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
        solve();
}