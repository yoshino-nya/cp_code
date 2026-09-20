// Date: 2025-09-29 15:37:20
// Author: wuyi
// 
// Problem: D. Tree Requests
// Contest: Codeforces - Codeforces Round 316 (Div. 2)
// URL: https://codeforces.com/problemset/problem/570/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 500005;
int dep[N], siz[N], dfn[N], cntd, S[N];
int pw2[26];
vector<vector<int>> g;
vector<vector<pair<int, int>>> H;
void dfs(int u, int p){
	dfn[u] = ++cntd, siz[u] = 1, dep[u] = dep[p] + 1;
	H[dep[u]].emplace_back(dfn[u], H[dep[u]].back().second ^ S[u]);
	for(auto v : g[u]){
		dfs(v, u);
		siz[u] += siz[v];
	}
}
void solve(){
	for(int i = 0; i < 26; i++)
		pw2[i] = 1 << i;
    int n, m; cin >> n >> m;
    g.assign(n + 1, {});
    H.assign(n + 1, vector<pair<int, int>> (1, {0, 0}));
    for(int i = 2; i <= n; i++){
    	int p; cin >> p;
    	g[p].push_back(i);
    }
	string s; cin >> s;
	for(int i = 0; i < n; i++){
		S[i + 1] = pw2[s[i] - 'a'];
	}
	dfs(1, 0);
	while(m--){
		int v, h; cin >> v >> h;
		// cerr << H[h].size() << '\n';
		int l = lower_bound(H[h].begin() + 1, H[h].end(), make_pair(dfn[v], -1)) - H[h].begin() - 1;
		int r = lower_bound(H[h].begin() + 1, H[h].end(), make_pair(dfn[v] + siz[v], -1)) - H[h].begin() - 1;
		int x = H[h][r].second ^ H[h][l].second;
		// cerr << l << " " << r << " " << x << "\n";
		if(x == ((x) & (-x))) cout << "Yes\n";
		else cout << "No\n";
	}
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}