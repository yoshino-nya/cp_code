// Author: Zhangwuji
// Date: 2025-01-09
// Time: 00:31:48

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
    int n, m, L;
    cin >> n >> m >> L;
    vector<pii> hurdles(n + 1);
    vector<pii> powers(m);
    for (int i = 1; i <= n; i++)
        cin >> hurdles[i].fi >> hurdles[i].se;
    for (int i = 0; i < m; i++)
        cin >> powers[i].fi >> powers[i].se;
    reverse(all(powers));
    priority_queue<int> pq;
    ll len = 1,ans=0;
    for (int i = 1; i <= n; i++) {
        auto [l, r] = hurdles[i];

        while (!powers.empty() && powers.back().fi < l) {
            pq.push(powers.back().se);
            powers.pop_back();
        }
        while(len<=r-l+1&&!pq.empty()){
            len+=pq.top();
            pq.pop();
            ans++;
        }
        // cerr<<len<<" "<<r-l+1<<'\n';

        if(len<=r-l+1){
            cout<<"-1\n";
            return;
        }
    }
    cout<<ans<<'\n';
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