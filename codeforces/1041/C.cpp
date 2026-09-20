/*
工作日持续m分钟
有n杯咖啡 第i杯只能在第ai分钟喝
喝两杯咖啡的时间间隔需要大于等于d分钟
问最少需要多少天能喝完这n杯咖啡
需要输出具体方案

好像固定的
因为每一天都是相对独立的
就看这一天能不能尽量多喝
可以就喝 不行就再开一天
*/
// Author: Zhangwuji
// Date: 2025-02-16
// Time: 20:10:11

// #define YUANSHEN
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
    int n,m,d;
    cin>>n>>m>>d;
    d++;
    vector<pii>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(ALL(a));
    dbg(a);
    set<pii>st;
    st.insert({a[1].fi,a[1].se});
    vi ans(n+1);
    ans[a[1].se]=1;
    int tot=1;
    for(int i=2;i<=n;i++){
        dbg(st);
        if(st.begin()->fi>a[i].fi-d){
            ans[a[i].se]=++tot;
            st.insert({a[i].fi,a[i].se});
        }else{
            // auto [x,y]=*st.lower_bound({a[i].fi-d,0});
            //哦哦是这里 上一行写错了 因为咱们这里是需要找第一个比a[i].fi-d小的数字。。。

            auto [x,y]=*prev(st.upper_bound({a[i].fi-d+1,0}));
            //注意这里得改成a[i].fi-d+1。。。 多注意，不然真的不好找出来如果看不了样例
            ans[a[i].se]=ans[y];
            st.erase({x,y});
            st.insert({a[i].fi,a[i].se});
        }
    }
    cout<<tot<<'\n';
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" \n"[i==n];
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