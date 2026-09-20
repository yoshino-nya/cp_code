#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 100000;
int f[N + 1][21], dep[N + 1], dfn[N + 1], siz[N + 1];
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1), g1(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int tot = 0;
    auto dfs0 = [&](auto &&self, int u, int pre) -> void {
        dfn[u] = ++tot;
        for(int i = 1; i <= 20; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for(auto v : g[u]){
            if(v == pre) continue;
            f[v][0] = u;
            dep[v] = dep[u] + 1;
            self(self, v, u);
        }
    };
    dfs0(dfs0, 1, 0);
    
    auto lca = [&](int x, int y) -> int {
        if(dep[x] > dep[y]) swap(x, y);
        for(int i = 0, z = dep[y] - dep[x]; z; i++, z >>= 1){
            if(z & 1)
                y = f[y][i];
        }
        if(x == y) return x;
        for(int i = 20; i >= 0 && (x != y); i--){
            if(f[x][i] != f[y][i]){
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };
    auto add = [&](int x, int y) -> void {
        g1[x].push_back(y);
        g1[y].push_back(x);
    };
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<int> p(k);
        for(int i = 0; i < k; i++){
            cin >> p[i];
            siz[p[i]] = 1;
        }
        for(auto u : p){
            if(siz[f[u][0]]){
                cout << "-1\n";
                for(auto x : p)
                    siz[x] = 0;
                break;
            }
        }
        if(!siz[p.back()]) continue;
        sort(p.begin(), p.end(), [&](int x, int y){
            return dfn[x] < dfn[y];
        });
        vector<int> stk;
        if(p[0] != 1) stk.push_back(1);
        for(auto x : p){
            if(stk.empty()){
                stk.push_back(x);
                continue;
            }
            int LCA = lca(x, stk.back());
            while(stk.size() > 1 && (dep[LCA] < dep[stk[stk.size() - 2]])){
                add(stk.back(), stk[stk.size() - 2]);
                stk.pop_back();
            }
            if(dep[LCA] < dep[stk.back()]){
                add(LCA, stk.back());
                stk.pop_back();
            }
            if(stk.empty() || (stk.back() != LCA)){
                stk.push_back(LCA);
            }
            stk.push_back(x);
        }
        for(int i = 0; i + 1 < stk.size(); i++)
            add(stk[i], stk[i + 1]);
        int ans = 0;
        auto dfs2 = [&](auto &&self, int u, int pre) -> void {
            if(siz[u]){
                for(auto v : g1[u]){
                    if(v == pre) continue;
                    self(self, v, u);
                    if(siz[v]){
                        siz[v] = 0;
                        ans++;
                    }
                }
            }else{
                for(auto v : g1[u]){
                    if(v == pre) continue;
                    self(self, v, u);
                    siz[u] += siz[v];
                    siz[v] = 0;
                }
                if(siz[u] > 1){
                    ans++;
                    siz[u] = 0;
                }
            }
            g1[u].clear();
        };
        dfs2(dfs2, 1, 0);
        siz[1] = 0;
        cout << ans << '\n';
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T; while(T--)
    {solve();} return 0;
}