// Author: Zhangwuji
// Date: 2025-01-01
// Time: 02:34:16

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
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //if now position is "1" check if there is "0" after it
    //if have , we operate on them
    //firstly we only check 1s
    //now it is like { 0 0 0 2 2 0 2 1 2 2 1}
    //if it is 2,we find 1
    //and swap them
    //and repeat the op before
    vector<set<int>>st(3);
    for(int i=1;i<=n;i++){
        st[a[i]].insert(i);
    }
    //先让所有1在0后面了，然后呢？
    //有的2 在1前面 在0前面
    //把2直接放到最后面的1那去
    //然后再看这个位置后面有没有0
    vector<pii>ans;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            if(!st[0].empty()&&*st[0].rbegin()>i){
                int j=*st[0].rbegin();
                swap(a[i],a[j]);
                ans.push_back({i,j});
                st[1].erase(i);
                st[0].erase(j);
                st[1].insert(j);
                st[0].insert(i);
            }
        }
    }
    // cerr<<sz(ans)<<'\n';
    // for(int i=1;i<=n;i++)
    //     cerr<<a[i]<<" \n"[i==n];
    //然后看每一个2
    //他后面如果没有1 那就不可能有0
    //所以直接把他放到后面的1
    //然后如果还有0 再换一次
    for(int i=1;i<=n;i++){
        if(a[i]==2){
            if(!st[1].empty()&&*st[1].rbegin()>i){
                int j=*st[1].rbegin();
                swap(a[i],a[j]);
                ans.push_back({i,j});
                st[2].erase(i);
                st[1].erase(j);
                st[2].insert(j);
                st[1].insert(i);
                // cerr<<i<<" "<<*st[0].rbegin();
                if(!st[0].empty()&&*st[0].rbegin()>i){
                    j=*st[0].rbegin();
                    swap(a[i],a[j]);
                    ans.push_back({i,j});
                    st[1].erase(i);
                    st[0].erase(j);
                    st[1].insert(j);
                    st[0].insert(i);
                }
            }
        }
    }
    cout<<sz(ans)<<'\n';
    // for(int i=1;i<=n;i++)
    //     cerr<<a[i]<<" \n"[i==n];
    for(auto [x,y]:ans)
        cout<<x<<" "<<y<<'\n';
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