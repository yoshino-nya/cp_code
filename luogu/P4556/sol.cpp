#include<bits/stdc++.h>
using namespace std;

constexpr int N = 100005;

vector<vector<int>> g;
int fa[N][20], dep[N];
void dfs(int u, int p)
{
	dep[u] = dep[p] + 1, fa[u][0] = p;
	for(int i = 1; i <= 19; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(auto v : g[u]){
		if(v == p) continue;
		dfs(v, u);
	}
}
int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
		if(z & 1)
			x = fa[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
struct node{
	int l, r, cnt, ans;
};
node tr[N * 50];
#define lson tr[p].l
#define rson tr[p].r
int ttot, rt[N], ans[N];
void push_up(int p)
{
	if(tr[lson].cnt >= tr[rson].cnt)
		tr[p].ans = tr[lson].ans;
	else
		tr[p].ans = tr[rson].ans;
	tr[p].cnt = max(tr[lson].cnt, tr[rson].cnt);
}
void update(int &p, int l, int r, int pos, int v)
{
	if(!p) p = ++ttot;
	if(l == r){
		tr[p].cnt += v;
		tr[p].ans = l;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(tr[p].l, l, mid, pos, v);
	else update(tr[p].r, mid + 1, r, pos, v);
	push_up(p);
}
int merge(int a, int b, int l, int r)
{
	if(!a) return b;
	if(!b) return a;
	if(l == r){
		tr[a].cnt += tr[b].cnt;
		tr[a].ans = tr[a].cnt ? l : 0;
		return a;
	}
	int mid = (l + r) >> 1;
	tr[a].l = merge(tr[a].l, tr[b].l, l, mid);
	tr[a].r = merge(tr[a].r, tr[b].r, mid + 1, r);
	push_up(a);
	return a;
}
void dfs1(int u)
{
	for(auto v : g[u]){
		if(v == fa[u][0]) continue;
		dfs1(v);
		rt[u] = merge(rt[u], rt[v], 1, 100000);
	}
	ans[u] = tr[rt[u]].ans;
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, m; cin >> n >> m;
	g = vector<vector<int>> (n + 1);
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i <= m; i++){
		int x, y, z; cin >> x >> y >> z;
		int LCA = lca(x, y);
		update(rt[x], 1, 100000, z, 1);
		update(rt[y], 1, 100000, z, 1);
		update(rt[LCA], 1, 100000, z, -1);
		update(rt[fa[LCA][0]], 1, 100000, z, -1);
	}
	dfs1(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << "\n";
	return 0;
}