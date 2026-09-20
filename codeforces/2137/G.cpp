// Date: 2025-09-18 18:03:23
// Author: wuyi
// 
// Problem: G. Cry Me a River
// Contest: Codeforces - Codeforces Round 1047 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2137/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 200005;
int dp[N][2], vis[N];
vector< vector<int> > g;
void dfs(int u, int s){
	if(dp[u][s]) return;
	dp[u][s] = 1;
	for(auto v : g[u]){
		if(s == 0){
			dfs(v, 1);
		}else{
			vis[v]--;
			if(!vis[v]) dfs(v, 0);
		}
	}
}
void solve(){
    int n, m, q; cin >> n >> m >> q;
    g.assign(n + 1, {});
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[v].push_back(u);
    	vis[u]++;
    }

    while(q--){
    	int op, u; cin >> op >> u;
    	if(op == 1)
    		dfs(u, 0), dfs(u, 1);
    	else
    		cout << (dp[u][0] ? "NO" : "YES") << "\n";
    }
    for(int i = 1; i <= n; i++){
    	dp[i][1] = dp[i][0] = vis[i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}