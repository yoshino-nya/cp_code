// Author: Zhangwuji
// Date: 2025-01-21
// Time: 16:36:34

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
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
    int n;
    cin >> n;
    vector<vi> a(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j + 1] = s[j] - '0';
    }
    vector<array<int, 4>> ans;
    queue<pii>q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j])
                q.push({i,j});
        }
    }
    auto find=[&](int x,int y,int s,int t){
        
    };
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            auto [x,y]=q.front();
            q.pop();
            find(x,y,i,j);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cerr << a[i][j] << " \n"[j == n];
    cout << sz(ans) << '\n';
    for (auto& x : ans) {
        for (auto& y : x)
            cout << y << " ";
        cout << '\n';
    }
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
        solve();
    return 0;
}