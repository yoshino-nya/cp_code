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

// Date: 2025-06-02
// Time: 10:17:47
void ChatGptDeepSeek()
{
    int n, w, h;
    cin >> n >> w >> h;
    vc<array<int, 3>> a(n);
    for(int i = 0; i < n; i++){
        a[i][2] = i + 1;
        cin >> a[i][0] >> a[i][1];
    }
    sort(all(a), [](array<int, 3> x, array<int, 3> y){
        return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
    });
    int tot = 0;
    vi f(n + 1), dp(n);
    for(int i = 0; i < n; i++){
        if(a[i][0] <= w || a[i][1] <= h) continue;
        if(a[i][1] > f[tot]){
            dp[i] = ++tot;
            f[tot] = a[i][1];
        }else{
            int idx = lower_bound(f.begin(), f.begin() + tot + 1, a[i][1]) - f.begin();
            f[idx] = a[i][1];
            dp[i] = idx;
        }
    }
    vi ans(tot);
    cout << tot << '\n';
    for(int i = n - 1, j = tot; i >= 0 && j; i--){
        if(dp[i] == j){
            ans[j - 1] = a[i][2];
            j--;
        }
    }
    for(int i = 0; i < tot; i++)
        cout << ans[i] << " \n" [i == tot - 1];
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