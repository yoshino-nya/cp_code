#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e5) + 5;
int siz[N], dep[N], fa[N], son[N], dfn[N], top[N], seg[N];

struct edge {
    int u, v;
    string s;
};
struct ques{
    int l, r, idx;
    string s;
};
int trie[N * 10][26], cnt[N * 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> t(n + 1);
    vector<edge> Edge(n);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        Edge[i] = {u, v, s};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs1 = [&](auto &&self, int u, int pre) -> void {
        fa[u] = pre, siz[u] = 1, dep[u] = dep[pre] + 1;
        for (auto v : g[u]) {
            if (v == pre) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(siz[v] > siz[son[u]])
                son[u] = v;
        }
    };
    dfs1(dfs1, 1, 0);
    {
        int tot = 0;
        auto dfs2 = [&](auto &&self, int u, int pre) -> void{
            dfn[u] = ++tot, seg[tot] = u;
            if(son[pre] == u) top[u] = top[pre];
            else top[u] = u;
            if(son[u]) self(self, son[u], u);
            for(auto v : g[u]){
                if(v == pre || v == son[u]) continue;
                self(self, v, u);
            }
        };
        dfs2(dfs2, 1, 0);
    }
    for(int i = 1; i < n; i++){
        auto [u, v, s] = Edge[i];
        if(dep[u] > dep[v]) swap(u, v);
        t[v] = s;
    }
    int q;
    cin >> q;
    vector<ques> Q;
    for(int k = 0; k < q; k++){
        int u, v;
        string s;
        cin >> u >> v >> s;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            Q.push_back({dfn[top[u]], dfn[u], k, s});
            u = fa[top[u]];
        }
        if(u != v){
            if(dep[u] > dep[v]) swap(u, v);
            Q.push_back({dfn[u] + 1, dfn[v], k, s});
        }
    }
    ranges::sort(Q, [](ques x, ques y){
        return x.l < y.l;
    });
    auto cmp = [](ques x, ques y){
        return x.r > y.r;
    };
    priority_queue<ques, vector<ques>, decltype(cmp)> pq(cmp);
    vector<int> ans(q);
    auto query = [&](string s){
        int cur = 0;
        for(auto x : s){
            if(trie[cur][x - 'a'] == 0) return 0;
            cur = trie[cur][x - 'a'];
        }
        return cnt[cur];
    };
    int tot = 0;
    auto Insert = [&](string s){
        int cur = 0;
        for(auto x : s){
            if(trie[cur][x - 'a'] == 0){
                trie[cur][x - 'a'] = ++tot;
            }
            cur = trie[cur][x - 'a'];
            cnt[cur]++;
        }
    };
    for(int i = 2, j = 0; i <= n; i++){
        while(j < Q.size() && Q[j].l == i){
            // cerr << j << " \n";
            ans[Q[j].idx] -= query(Q[j].s);
            pq.push(Q[j++]);
        }
        Insert(t[seg[i]]);
        while(!pq.empty() && pq.top().r == i){
            auto [l, r, idx, s] = pq.top();
            // cerr << l << "  " << r << '\n';
            pq.pop();
            ans[idx] += query(s);
        }
    }
    // cerr << "query: " << query("ab") << '\n';
    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}