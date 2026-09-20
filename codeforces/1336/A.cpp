// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 21:25:03
    int n, k;
    cin >> n >> k;
    vector<vi> adj(n + 1, vi());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi dep(n + 1), siz(n + 1);

    dep[1] = 1;
    auto dfs = [&](auto &&self, int u, int pre) -> void
    {
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == pre)
                continue;
            dep[v] = dep[u] + 1;
            self(self, v, u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs, 1, 0);
    vi order(n + 1);
    iota(ALL(order), 1);
    sort(ALL(order), [&](int x, int y)
         { return siz[x] - dep[x] > siz[y] - dep[y]; });
    ll ans = 0;
    for (int i = 1; i <= n - k; i++)
        ans += siz[order[i]] - dep[order[i]];
    cout << ans << '\n';
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