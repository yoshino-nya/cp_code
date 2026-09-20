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

// Date: 2025-05-26
// Time: 10:39:15
int dp[1048576];

void ChatGptDeepSeek()
{
    memset(dp, 0x3f, sizeof dp);
    int n, m;
    cin >> n >> m;
    vi a(n + 1), cnt(m);
    vc<vi> pre(n + 1, vi(m));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[--a[i]]++;
        pre[i] = pre[i - 1];
        pre[i][a[i]]++;
    }
    dp[0] = 0;
    for(int i = 0; i < (1 << m); i++){
        int len = 0;
        for(int j = 0; j < m; j++)
            if(i >> j & 1) len += cnt[j];
        for(int j = 0; j < m; j++){
            if((i >> j & 1) == 0){
                dp[i ^ (1 << j)] = min(dp[i ^ (1 << j)], dp[i] + (cnt[j] - (pre[len + cnt[j]][j] - pre[len][j])));
            }
        }
    }
    cout << dp[(1 << m) - 1];
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    // cerr << (1 << 20) ;
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}