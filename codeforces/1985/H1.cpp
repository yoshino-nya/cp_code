// Author: Zhangwuji
// Date: 2025-02-20
// Time: 21:06:44

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
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int tot=0,sum=0;
    vector<vi>vis(n+1,vi(m+1));
    vector<pii>dir{{0,1},{0,-1},{1,0},{-1,0}};
    auto dfs=[&](auto &&self,int i,int j)->void{
        // cerr<<i<<" "<<j<<'\n';
        vis[i][j]=tot;
        sum++;
        for(auto [dx,dy]:dir){
            int nx=dx+i,ny=dy+j;
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(a[nx][ny]=='#'&&!vis[nx][ny])
                self(self,nx,ny);
        }
    };
    vi cnt(n*m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'&&!vis[i][j]){
                // cerr<<i<<" "<<j<<'\n';
                ++tot,sum=0;
                dfs(dfs,i,j);
                cnt[tot]=sum;
                
            }
        }
    // cerr<<tot<<'\n';
    int ans=0;
    for(int i=1;i<=n;i++){
        int now=m;
        set<int>st;
        if(i-1>=1){
            for(int j=1;j<=m;j++)
                st.insert(vis[i-1][j]);
        }
        if(i+1<=n){
            for(int j=1;j<=m;j++){
                st.insert(vis[i+1][j]);
            }
        }
        for(int j=1;j<=m;j++){
            st.insert(vis[i][j]);
            now-=(a[i][j]=='#');
        }
        for(auto x:st)
            now+=cnt[x];
        cmax(ans,now);
    }
    for(int i=1;i<=m;i++){
        int now=n;
        set<int>st;
        if(i-1>=1){
            for(int j=1;j<=n;j++)
                st.insert(vis[j][i-1]);
        }
        if(i+1<=m){
            for(int j=1;j<=n;j++){
                st.insert(vis[j][i+1]);
            }
        }
        for(int j=1;j<=n;j++){
            st.insert(vis[j][i]);
            now-=(a[j][i]=='#');
        }
        for(auto x:st)
            now+=cnt[x];
        cmax(ans,now);
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