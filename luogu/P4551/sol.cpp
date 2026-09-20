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

void ChatGptDeepSeek() // Date: 2025-04-10
{                      // Time: 19:30:23 
    int n;
    cin>>n;
    vector<vector<pii>>adj(n+1,vector<pii>());
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>s(n+1);
    auto dfs=[&](auto&& self,int u,int pre)->void{
        for(auto [v,w]:adj[u]){
            if(v==pre) continue;
            s[v]=s[u]^w;
            self(self,v,u);
        }
    };
    dfs(dfs,1,0);
    vector<vi>trie(n*31,vi(2));
    int tot=0;
    auto Insert=[&](int Val){
        int cur=0;
        for(int i=30;i>=0;i--){
            int x=Val>>i&1;
            if(!trie[cur][x])
                trie[cur][x]=++tot;
            cur=trie[cur][x];
        }
    };
    auto Find=[&](int Val){
        int cur=0,res=0;
        for(int i=30;i>=0;i--){
            int x=Val>>i&1;
            if(trie[cur][x^1]){
                res|=1<<i;
                cur=trie[cur][x^1];
            }else
                cur=trie[cur][x];
        }
        return res;
    };
    for(int i=1;i<=n;i++)
        Insert(s[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,Find(s[i]));
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
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}