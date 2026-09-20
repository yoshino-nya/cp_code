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
// Time: 22:46:00
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vi f(n + 1);
    f[1] = 1, f[2] = 2;
    for(int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    for(int i = 1; i <= m; i++){
        array<int, 3> w;
        for(int j = 0; j < 3; j++)
            cin >> w[j];
        sort(all(w));
        if(w[0] >= f[n] && w[2] >= f[n] + f[n - 1])
            cout << 1;
        else cout << 0;
    }
    cout << '\n';
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