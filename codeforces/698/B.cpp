// Author: Zhangwuji
// Date: 2025-02-16
// Time: 20:39:30

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
    int n;
    cin>>n;
    
    vi p(n+1);
    int root=0;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++){
        if(i==p[i]){
            root=i;
            break;
        }
    }
    vi q(p);
    vector<int>vis(n+1);
    int tot=0;
    auto dfs=[&](auto &&self,int u){
        if(vis[u]) return;
        vis[u]=tot;
        if(q[u]==u){
            if(root){
                q[u]=root;
            }else{
                root=u;
            }
            return;
        }
        if(vis[q[u]]){
            if(vis[q[u]]==tot){
                //成环了
                if(root){
                    q[u]=root;
                }else{
                    root=u;
                    q[u]=u;
                }
                return;
            }
        }
        self(self,q[u]);
    };
    for(int i=1;i<=n;i++){
        ++tot;
        dfs(dfs,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=q[i]!=p[i];
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)
        cout<<q[i]<<" \n"[i==n];
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