#include<bits/stdc++.h>
using namespace std;

int n, m;
constexpr int N = int(1e4) + 10;
int head[N], nxt[10 * N], to[10 * N], from[10 * N], totEdge = 1;
int dfn[N], low[N], tot;
int scc[N], sz[N], sc;
bool in_stack[N];
vector<int> stk;
void addEdge(int u, int v)
{
    nxt[totEdge] = head[u];
    head[u] = totEdge;
    to[totEdge] = v;
    from[totEdge] = u;
    totEdge++;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++tot;
    // cerr << u << " " << dfn[u] << '\n';
    in_stack[u] = true, stk.push_back(u);
    // cerr << "u : " << u << '\n';
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        // cerr << "v : " << v << '\n';
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(in_stack[v]){
            // cerr << dfn[v] << '\n';
            low[u] = min(low[u], dfn[v]);
        }
    }
    // cerr << u << " " << low[u] << " " << dfn[u] << '\n';
    if(low[u] == dfn[u]){
        ++sc;
        while(stk.size()){
            auto x = stk.back();
            stk.pop_back();
            sz[sc]++, scc[x] = sc;
            in_stack[x] = false;
            if(x == u) break;
        }

    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    vector<int> d(sc + 1);
    for(int i = 1; i < totEdge; i++){
        int u = from[i], v = to[i];
        // cerr << scc[u] << '\n';
        if(scc[u] != scc[v])
            d[scc[u]]++;
    }
    int ans = 0;
    for(int i = 1; i <= sc; i++){
        if(d[i] == 0){
            if(ans){
                ans = 0;
                break;
            }else ans = sz[i];
        }
    }
    cout << ans << '\n';
    return 0;
}