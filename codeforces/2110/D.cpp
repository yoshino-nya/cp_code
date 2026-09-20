// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-24
// Time: 23:15:52
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vi b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    vc<vc<pii>> g(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    auto check = [&](int mx) -> bool{
        vi f(n + 1, -1);
        f[1] = 0;
        for(int i = 1; i <= n; i++){
            if(f[i] == -1) continue;
            f[i] = min(mx, f[i] + b[i]);
            for(auto [v, w] : g[i]){
                if(f[i] >= w)
                    cmax(f[v], f[i]);
            }
        }
        return f[n] >= 0;
    };
    int lo = 0, hi = INF + 1;
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        if(check(mid))
            hi = mid;
        else lo = mid;
    }
    if(hi == INF + 1) hi = -1;
    cout << hi << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}