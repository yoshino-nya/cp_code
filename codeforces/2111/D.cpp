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

// Date: 2025-06-03
// Time: 23:04:32
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vi a(m + 1);
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    sort(ALL(a));
    for(int i = 1, j = 1; i <= n; i += 2, j++){
        vi ans(6);
        for(int k = 0; k < 6; k++)
            ans[k] = (k & 1) ? a[j] : a[m - j + 1];
        for(auto x : ans)
            cout << x << ' ';
        cout << '\n';
        reverse(all(ans));
        if(i + 1 <= n){
            for(auto x : ans)
                cout << x << ' ';
             cout << '\n';
        }
    }
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