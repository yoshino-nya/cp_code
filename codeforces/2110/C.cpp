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

// Date: 2025-05-24
// Time: 22:50:09
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi d(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }
    int L = 0, R = 0;
    vi stk;
    vc<pii> p(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1) L++, R++;
        // else if(d[i] == 0) R++;
        else if(d[i] == -1) stk.push_back(i);
        // dbg(L, R, p[i]);
        if(L > p[i].se){
            cout << "-1\n";
            return;
        }
        while(R < p[i].fi && stk.size()){
            R++;
            L++;
            d[stk.back()] = 1;
            stk.pop_back();
        }
        if(R < p[i].fi){
            cout << "-1\n";
            return;
        }
        cmax(L, p[i].fi);
        cmin(R, p[i].se);
        if(L > R){
            cout << "-1\n";
            return;
        }
    }
    int H = 0;
    // dbg(d);
    for(int i = 1; i <= n; i++){
        if(d[i] == -1) d[i] = 0;
        H += d[i];
        if(H < p[i].fi || H > p[i].se){
            cout << "-1\n";
            return;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << d[i] << " \n" [i == n];
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