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

constexpr int N = int(1e5);
constexpr int mod = int(1e9) + 7;
int f[N + 1], Inv[N + 1];

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 20:29:41
    int t, k;
    cin >> t >> k;
    vl ans(N + 1, 1);
    // auto work=[&]()
    for (int i = k; i <= N; i++)
        ans[i] = (ans[i - 1] + ans[i - k]) % mod;
    // cerr<<ans[i]<<"\n";
    // 3: RRR WWR RWW 2
    // 4: RRRR WWRR RWWR RRWW WWWW 3+1
    // 5: RRRRR WWRRR RRWWR RWWRR RRRWW 4+2
    for (int i = 1; i <= N; i++)
        ans[i] = (ans[i - 1] + ans[i]) % mod;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << ((ans[r] - ans[l - 1]) % mod + mod) % mod << '\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    f[0] = 1;
    for (int i = 1; i <= N; i++)
        f[i] = 1LL * f[i - 1] * i % mod;
    // for(int i=1;i<=4;i++) cerr<<f[i]<<" \n"[i==4];
    Inv[N] = ksm(f[N], mod - 2);
    // cerr<<Inv[N]<<'\n';
    for (int i = N - 1; i >= 0; i--)
        Inv[i] = 1LL * Inv[i + 1] * (i + 1) % mod;
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}