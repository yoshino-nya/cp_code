// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
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
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

constexpr int mod = 998244353;
ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void ChatGptDeepSeek() // Date: 2025-07-25
{                      // Time: 18:03:59 
    int n, m;
    cin >> n >> m;
    // vector<array<int, 4>> vec(n);
    vector<vector<pii>> vec(m + 1);
    for(int i = 0; i < n; i++){
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        vec[r].push_back({l, p * ksm(q, mod - 2) % mod});
    }
    vector<long long> pre(m + 1), dp(m + 1);
    pre[0] = 1, dp[0] = 1;
    for(int i = 1; i <= m; i++){
        pre[i] = pre[i - 1];
        for(auto [l, p] : vec[i]){
            pre[i] = pre[i] * (1 - p) % mod;
        }
        pre[i] = (pre[i] + mod) % mod;
    }
    auto get = [&](int l, int r){
        return pre[r] * ksm(pre[l - 1], mod - 2) % mod;
    };
    for(int i = 1; i <= m; i++){
        for(auto [l, p] : vec[i]){
            dp[i] = dp[i] + dp[l - 1] * p % mod * get(l, i) % mod * ksm(1 - p, mod - 2) % mod;
            dp[i] = dp[i] % mod;
        }
    }
    dp[m] = (dp[m] + mod) % mod;
    cout << dp[m] << '\n';
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