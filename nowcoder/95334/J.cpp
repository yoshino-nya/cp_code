// Author: Zhangwuji
// Date: 2025-01-23
// Time: 14:10:44

#define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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
    int n,h,m;
    cin>>n>>h>>m;
    vector<set<string>>st(3);
    for(int i=1;i<=n;i++){
        string id;
        int year,month,day;
        char x;
        string time;
        cin>>id>>year>>x>>month>>x>>day>>time;
        if(year!=h||month!=m)
            continue;
        if(time>="07:00:00"&&time<="09:00:00")
            st[0].insert(id);
        else if(time>="18:00:00"&&time<="20:00:00")
            st[0].insert(id);
        else if(time>="11:00:00"&&time<="13:00:00")
            st[1].insert(id);
        else if(time>="22:00:00"||time<="01:00:00")
            st[2].insert(id);
    }
    cout<<sz(st[0])<<" "<<sz(st[1])<<" "<<sz(st[2])<<'\n';
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