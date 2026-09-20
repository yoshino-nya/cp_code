// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1 &x, const T2 &y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1 &x, const T2 &y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 11:04:40
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int v, w;
            cin >> v >> w;
            adj[i].push_back({v, w});
        }
    }

    vector<vi> dp(n + 1, vi(m + 1, -INF));
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    for (int i = n - m + 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i][1] = x;
    }
    vector<vi> ndp(dp);

    auto dfs = [&](auto &&self, int u, int pre) -> void
    {
        // cerr << u << '\n';
        ndp[u] = dp[u];
        for (auto [v, w] : adj[u])
        {
            if (v == pre)
                continue;
            self(self, v, u);
            // 知道子结点的cost情况 能怎么样呢？
            // 改一下 dp[i,j]表示节点i 有j 的贡献 的最小的cost
            for (int i = 0; i <= m; i++)
            {
                if (dp[u][i] == -INF)
                    break;
                for (int j = 0; j + i <= m; j++)
                {
                    if (dp[v][j] == -INF)
                        break;
                    ndp[u][i + j] = max(ndp[u][i + j], dp[u][i] + dp[v][j] - w);
                }
            }
            dp[u] = ndp[u];
        }
    };
    dfs(dfs, 1, 0);
    for (int i = m; i >= 0; i--)
    {
        if (dp[1][i] >= 0)
        {
            cout << i << '\n';
            return;
        }
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}