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

// Date: 2025-06-06
// Time: 08:05:35
void ChatGptDeepSeek()
{
    int n, q;
    cin >> n >> q;
    vi b(n + 1), l(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        l[i] = b[i];
    }
    vc<array<int, 3>> op(q);
    for(int i = q - 1; i >= 0; i--){
        cin >> op[i][0] >> op[i][1] >> op[i][2];
    }
    for(auto [x, y, z] : op){
        cmax(l[x], l[z]);
        cmax(l[y], l[z]);
        if(z != x && z != y)
            l[z] = 0;
    }
    vi c(l);
    for(int i = q - 1; i >= 0; i--){
        auto [x, y, z] = op[i];
        c[z] = min(c[x], c[y]);
    }
    if(b != c){
        cout << "-1\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        cout << (l[i] ? l[i] : 1) << " \n" [ i == n];
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