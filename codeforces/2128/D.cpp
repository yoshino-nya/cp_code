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

void ChatGptDeepSeek() // Date: 2025-07-27
{                      // Time: 23:40:03 
    /*
    max(p_{i}, p_{i + 1}) > p_{i + 2}
    if p[i] < p[i + 1]
        then p[i + 1] > p[i + 2]
    */
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += 1LL * i * (n - i + 1);
    for(int i = 1; i < n; i++){
        if(a[i] < a[i + 1])
            ans -= 1LL * i * (n - i);
    }
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
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}