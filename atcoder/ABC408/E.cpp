#include <bits/stdc++.h>

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::array<int, 2>>> g(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int ans = (1 << 30) - 1;
    for(int i = 29; i >= 0; i--){
        std::vector<bool> vis(n + 1);
        auto check = [&](auto &&self, int u) -> bool{
            vis[u] = true;
            if(u == n)
                return true;
            for(auto [v, w] : g[u]){
                if(!vis[v]){
                    if((w | ans) == ans && (w >> i & 1) == 0){
                        if(self(self, v))
                            return true;
                    }
                }
            }
            return false;
        };
        if(check(check, 1)) ans ^= 1 << i;
    }
    std::cout << ans << '\n';
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    solve();
}