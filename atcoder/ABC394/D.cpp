// Author: Zhangwuji
// Date: 2025-02-22
// Time: 20:18:25

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

void solve()
{
    string s;
    cin >> s;
    queue<char> q;
    for (auto x : s)
        q.push(x);
    vector<char> stk;
    while (!q.empty()) {
        stk.push_back(q.front());
        q.pop();
        while (sz(stk) >= 2) {
            char x = stk[sz(stk) - 2], y = stk[sz(stk) - 1];
            // cerr<<x<<" "<<y<<'\n';
            if (x == '(' && y == ')')
                stk.pop_back(), stk.pop_back();
            else if (x == '<' && y == '>')
                stk.pop_back(), stk.pop_back();
            else if (x == '[' && y == ']')
                stk.pop_back(), stk.pop_back();
            else break;
        }
    }
    dbg(stk);
    cout<<(stk.empty()?"Yes\n":"No\n");
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}