// Date: 2025-09-11 09:30:02
// Author: wuyi
// 
// Problem: P1505 [国家集训队] 旅游
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1505
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<vector<pair<int, int>>> g;
constexpr int N = 200005;
int n;
int dfn[N], siz[N], dep[N], fa[N], son[N], top[N], cntd;
struct tree{
	int min, max, sum, lazy;
	tree(){min = 1000, max = -1000, sum = 0, lazy = 0;}
};
tree seg[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
tree merge(const tree &x, const tree &y){
	tree z;
	z.max = max(x.max, y.max);
	z.min = min(x.min, y.min);
	z.sum = x.sum + y.sum;
	return z;
}
void rev(int p){
	seg[p].lazy ^= 1;
	int x = seg[p].min;
	seg[p].min = -seg[p].max;
	seg[p].max = -x;
	seg[p].sum = -seg[p].sum;
}
void push_down(int p){
	if(seg[p].lazy){
		rev(ls), rev(rs);
		seg[p].lazy = 0;
	}
}
void change(int p, int l, int r, int i, int x){
	if(l == r){
		seg[p].min = seg[p].max = seg[p].sum = x;
		return;
	}
	push_down(p);
	if(i <= mi) change(ls, l, mi, i, x);
	else change(rs, mi + 1, r, i, x);
	seg[p] = merge(seg[ls], seg[rs]);
}
void dfs1(int u, int p){
	siz[u] = 1, dep[u] = dep[p] + 1, fa[u] = p;
	for(auto [v, w] : g[u]){
		if(v == p) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u){
	dfn[u] = ++cntd;
	top[u] = son[fa[u]] == u ? top[fa[u]] : u;
	if(son[u]) dfs2(son[u]);
	for(auto [v, w] : g[u]){
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v);
	}
}
void rev(int p, int l, int r, int lx, int rx){
	if(l >= lx && r <= rx){
		rev(p);
		return;
	}
	push_down(p);
	if(lx <= mi) rev(ls, l, mi, lx, rx);
	if(rx > mi) rev(rs, mi + 1, r, lx, rx);
	seg[p] = merge(seg[ls], seg[rs]);
}
tree query(int p, int l, int r, int lx, int rx){
	assert(lx <= rx);
	// cerr << lx << " " << rx << "\n";
	// cerr << l << " " << r << " " << lx << " " << rx << " " << seg[p].sum << "\n";
	if(l >= lx && r <= rx) return seg[p];
	tree res;
	push_down(p);
	if(lx <= mi) res = merge(res, query(ls, l, mi, lx, rx));
	if(rx > mi) res = merge(res, query(rs, mi + 1, r, lx, rx));
	return res;
}
tree lca(int x, int y){
	tree res;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res = merge(res, query(1, 1, n, dfn[top[x]], dfn[x]));
		// cerr << res.sum << " " << dfn[top[x]] << " " << dfn[x] << " \n";
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(dfn[x] + 1 <= dfn[y])
		res = merge(res, query(1, 1, n, dfn[x] + 1, dfn[y]));
	return res;
}
void work(int x, int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		rev(1, 1, n, dfn[top[x]], dfn[x]);
		// cerr << res.sum << " " << dfn[top[x]] << " " << dfn[x] << " \n";
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(dfn[x] + 1 <= dfn[y])
		rev(1, 1, n, dfn[x] + 1, dfn[y]);
}
void solve(){
    cin >> n;
    g = vector< vector< pair<int, int> > > (n + 1);
	vector<array<int, 3>> edge(n - 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v, w; cin >> u >> v >> w;
    	++u, ++v;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    	edge[i] = {u, v, w};
    }

    dfs1(1, 0), dfs2(1);
    for(auto &[u, v, w] : edge){
    	if(dep[u] > dep[v]) swap(u, v);
    	change(1, 1, n, dfn[v], w);
    }
    int q; cin >> q;
    while(q--){
    	string op; cin >> op;
    	// cerr << op << " \n";
    	if(op == "C"){
    		int i, w; cin >> i >> w; --i;
    		auto [u, v, _] = edge[i];
    		change(1, 1, n, dfn[v], w);
    	}else if(op == "N"){
    		int u, v; cin >> u >> v;
    		++u, ++v;
    		work(u, v);
    	}else{
    		int u, v; cin >> u >> v;
    		++u, ++v;
    		tree res = lca(u, v);
    		if(op == "SUM") cout << res.sum << "\n";
    		else if(op == "MAX") cout << res.max << "\n";
    		else cout << res.min << "\n";
    	}
    }
}
int main(){
	// freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}