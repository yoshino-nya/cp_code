// Date: 2025-09-19 00:02:15
// Author: wuyi
// 
// Problem: J. Send the Fool Further! (easy)
// Contest: Codeforces - Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL: https://codeforces.com/problemset/problem/802/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<vector<pair<int, int>>> g;
int dp[101];
void dfs(int u, int p){
	// dp[u] = 0;
	for(auto [v, w] : g[u]){
		if(v == p) continue;
		dp[v] = dp[u] + w;
		// cerr << dp[v] << "\n";
		dfs(v, u);
	}
}
void solve(){
    int n; cin >> n;
    g.assign(n, {});
    for(int i = 1; i < n; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    dfs(0, -1);
    int ans = 0;
    for(int i = 0; i < n; i++){
    	// cerr << dp[i] << " \n" [i == n];
    	ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}