#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<vector<pair<int, LL>>> g;
vector<LL> dis;
vector<bool> vis;
vector<LL> v(64);
void insert(LL x)
{
    for(int i = 63; i >= 0; i--){
        if(x >> i & 1){
            if(!v[i]){
                v[i] = x;
                return;
            }
            x ^= v[i];
        }
    }
}
void dfs(int u)
{
    vis[u] = true;
    for(auto [v, w] : g[u]){
        if(!vis[v]){
            dis[v] = dis[u] ^ w;
            dfs(v);
        }
        else insert(dis[u] ^ dis[v] ^ w);
    }
}
void solve()
{
    int n, m; cin >> n >> m;
    g = vector<vector<pair<int, LL>>> (n + 1);
    dis = vector<LL> (n + 1);
    vis = vector<bool> (n + 1);
    for(int i = 1; i <= m; i++){
        int s, t; LL d;
        cin >> s >> t >> d;
        g[s].push_back({t, d});
        g[t].push_back({s, d});
    }
    dfs(1);
    LL ans = dis[n];
    for(int i = 63; i >= 0; i--)
        if((ans ^ v[i]) > ans)
            ans ^= v[i];
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}