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

// Date: 2025-05-31
// Time: 22:53:29
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi dp(5000 + 1, INF), a(n + 1);
    int g = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[a[i]] = 0;
        g = gcd(g, a[i]);
    }
    if(*min_element(ALL(a)) == g){
        cout << n - count(ALL(a), g) << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        // vi ndp(dp);
        for(int j = 1; j <= 5000; j++){
            if(dp[j] != INF)
                cmin(dp[gcd(j, a[i])], dp[j] + 1);
        }
        // dp = ndp;
    }
    cout << dp[g] + n - 1 << '\n';
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