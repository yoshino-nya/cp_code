// Author: Zhangwuji
// Date: 2025-02-19
// Time: 12:28:38

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
    vi x(n+1),y(n+1),r(n+1);
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i]>>r[i];
    vector<vi>adj(n+1,vi());
    auto calc=[&](int x){
        return 1ll*x*x;
    };
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(calc(x[i]-x[j])+calc(y[i]-y[j])==calc(r[i]+r[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    vi s(n+1,-1);
    for(int i=1;i<=n;i++){
        if(s[i]!=-1) continue;
        bool ok=true;
        int x=0,y=0;
        auto dfs=[&](auto &&self,int u)->void{
            if(s[u]) x++;
            else y++;
            // cerr<<u<<'\n';
            for(auto v:adj[u]){
                if(s[v]!=-1){
                    if(s[v]==s[u]) ok=false;
                    continue;
                }
                s[v]=s[u]^1;
                self(self,v);
            }
        };
        s[i]=0;
        dfs(dfs,i);
        if(ok&&x!=y){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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