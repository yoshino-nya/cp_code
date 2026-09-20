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

void ChatGptDeepSeek() // Date: 2025-07-22
{                      // Time: 22:48:56 
    ll l, r;
    cin >> l >> r;
    /*
    所有2 3 5 7的倍数 统计有多少个
    

    */
    auto get = [](ll lmt){
        ll res = lmt;
        res -= lmt / 2 + lmt / 3 + lmt / 5 + lmt / 7;
        res -= lmt / 30 + lmt / 42 + lmt / 70 + lmt / 105;
        res += lmt / 6 + lmt / 10 + lmt / 14 + lmt / 15 + lmt / 21 + lmt / 35;
        res += lmt / 210;
        return res;
    };
    cout << get(r) - get(l - 1) << '\n';
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