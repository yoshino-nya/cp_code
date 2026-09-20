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

// Date: 2025-05-27
// Time: 15:07:58
constexpr int N = int(1e5);
ll dp[N + 1], c[5], d[5];

void ChatGptDeepSeek()
{
    int q;
    cin >> c[1] >> c[2] >> c[3] >> c[4] >> q;
    dp[0] = 1;
    for(int i = 1; i <= 4; i++){
        for(int j = c[i]; j <= N; j++)
            dp[j] += dp[j - c[i]];
    }
    while(q--){
        for(int i = 1; i <= 4; i++)
            cin >> d[i];
        int s;
        cin >> s;
        ll ans = dp[s];
        for(int mask = 1; mask <= 15; mask++){
            ll x = 0;
            for(int j = 0; j < 4; j++){
                if(mask >> j & 1) x += c[j + 1] * (d[j + 1] + 1);
            }
            if(x > s) continue;
            if(__builtin_popcount(mask) & 1) ans -= dp[s - x];
            else ans += dp[s - x];
        }
        cout << ans << '\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}