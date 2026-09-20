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
// Time: 22:43:12
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
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi p(n), q(n), pos1(n), pos2(n), r(n), mx(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        pos1[p[i]] = i;
    }
    for(int i = 0; i < n; i++){
        cin >> q[i];
        pos2[q[i]] = i;
    }
    mx[0] = max(p[0], q[0]);
    for(int i = 1; i < n; i++){
        mx[i] = max(mx[i - 1], max(p[i], q[i]));
    }
    for(int i = 0; i < n; i++){
        int x = 0;
        if(pos1[mx[i]] <= i)
            cmax(x, q[i - pos1[mx[i]]]);
        if(pos2[mx[i]] <= i)
            cmax(x, p[i - pos2[mx[i]]]);
        r[i] = (ksm(2, mx[i]) + ksm(2, x)) % mod;
        cout << r[i] << " \n"[i + 1 == n];
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