// Date: 2025-09-25 10:23:11
// 
// Problem: E. Xenia and Tree
// Contest: Codeforces - Codeforces Round 199 (Div. 2)
// URL: https://codeforces.com/problemset/problem/342/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200005;
int dis[N], dep[N], f[N][20];
vector<vector<int>> g;
void init(int u, int p){
	f[u][0] = p, dep[u] = dep[p] + 1;
	for(int i = 1; i < 20; i++)
		f[u][i] = f[f[u][i - 1]][i - 1];
	for(auto v : g[u]){
		if(v == p) continue;
		dis[v] = dis[u] + 1;
		init(v, u);
	}
}
int LCA(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
		if(z & 1) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
		if(f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];
	return f[x][0];
}
void solve(){
    int n, q; cin >> n >> q;
    g.assign(n + 1, {});
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    init(1, 0);
	queue<int> que;
	vector<int> vec;
	int B = 150;
    while(q--){
    	int op, u; cin >> op >> u;
    	if(op == 1){
    		vec.push_back(u);
    		dis[u] = 0;
    		que.push(u);
    	}else{
    		int ans = dis[u];
    		for(auto v : vec)
    			ans = min(ans, dep[u] + dep[v] - 2 * dep[LCA(u, v)]);
    		cout << ans << "\n";
    	}
    	if(que.size() == B){
    		vec.clear();
    		while(!que.empty()){
    			auto vertex = que.front();
    			que.pop();
    			for(auto v : g[vertex]){
    				if(dis[v] > dis[vertex] + 1){
    					dis[v] = dis[vertex] + 1;
    					que.push(v);
    				}
    			}
    		}
    	}
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
