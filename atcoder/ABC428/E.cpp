#include <bits/stdc++.h>
using namespace std;

using LL = long long;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    function<vector<int>(int)> get = [&](int s) {
        vector<int> dis(n + 1, n + 1);
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            auto u = q.front(); q.pop();
            // cerr << u << "\n";
            for(auto v : g[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis;
    };
    int u1 = 1, u2 = 1;
    vector<int> d1 = get(1);
    for(int i = 1; i <= n; i++)
        if(d1[i] >= d1[u1]) u1 = i;
    vector<int> d2 = get(u1);
    for(int i = 1; i <= n; i++)
        if(d2[i] >= d2[u2]) u2 = i;
    if(u1 > u2) swap(u1, u2);
    d1 = get(u1), d2 = get(u2);
    for(int i = 1; i <= n; i++)
        cout << (d1[i] > d2[i] ? u1 : u2) << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}