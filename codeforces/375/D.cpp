// Date: 2025-09-30 08:25:46
// Author: wuyi
// 
// Problem: D. Tree and Queries
// Contest: Codeforces - Codeforces Round 221 (Div. 1)
// URL: https://codeforces.com/problemset/problem/375/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 100005;
int c[N], dfn[N], siz[N], cntd, rnk[N];
int pos[N], cnt[N], freq[N], ans[N];
vector<vector<int>> g;
void dfs(int u, int p){
	dfn[u] = ++cntd, siz[u] = 1, rnk[cntd] = u;
	for(auto v : g[u]){
		if(v == p) continue;
		dfs(v, u);
		siz[u] += siz[v];
	}
}
struct node{
	int l, r, k, idx;
};
node Q[N];
void solve(){
    int n, m; cin >> n >> m;
    int si = sqrt(n);
    g.assign(n + 1, {});
    for(int i = 1; i <= n; i++){
    	cin >> c[i];
    	pos[i] = i / si;
    }
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 0; i < m; i++){
    	int v, k; cin >> v >> k;
    	Q[i].l = dfn[v], Q[i].r = Q[i].l + siz[v] - 1;
    	Q[i].k = k, Q[i].idx = i;
    }
    sort(Q, Q + m, [&](node x, node y){
    	return pos[x.l] == pos[y.l] ? pos[x.r] < pos[y.r] : pos[x.l] < pos[y.l];
    });
    auto add = [&](int i){
    	cnt[c[rnk[i]]]++, freq[cnt[c[rnk[i]]]]++;
    };
    auto del = [&](int i){
    	freq[cnt[c[rnk[i]]]]--, cnt[c[rnk[i]]]--;
    };
    int L = 1, R = 0;
    for(int _ = 0; _ < m; _++){
    	auto [l, r, k, idx] = Q[_];
    	while(L > l) add(--L);
    	while(L < l) del(L++);
    	while(R > r) del(R--);
    	while(R < r) add(++R);
    	ans[idx] = freq[k];
    }
    for(int i = 0; i < m; i++)
    	cout << ans[i] << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}