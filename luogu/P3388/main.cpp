#include <bits/stdc++.h>
using namespace std;

// Date: 2025-09-08
// Time: 11:26:49
constexpr int N = 20005;
int dfn[N], low[N], cut[N], dcnt;
vector< vector<int> > g;
vector<int> ans;
void tarjan(int u, int p)
{
    dfn[u] = low[u] = ++dcnt;
    int child = 0;
    for(auto v : g[u]){
        if(!dfn[v]){
            tarjan(v);
            if(p && low[v] >= dfn[u])
                cut[u] = 1;
            low[u] = min(low[u], low[v]);
        }else if(v != p)
            low[u] = min(low[u], dfn[v]);
    }
    if(!p && child >= 2)
        cut[u] = 1;
}
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    g = vector< vector<int> > (n + 1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; i++)
        if(cut[i]) ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto u : ans)
        cout << u << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}