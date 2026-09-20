// Date: 2025-09-19 00:26:56
// Author: wuyi
// 
// Problem: D. Vertical Paths
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1675/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<vector<int>> g;
constexpr int N = 200005;
int dep[N];
vector<vector<int>> ans;
void dfs1(int u, int p, int f){
	if(f)
		ans.push_back(vector<int>());
	ans[ans.size() - 1].push_back(u);
	int z = 0;
	for(auto v : g[u]){
		if(v == p) continue;
		dfs1(v, u, z);
		z = 1;
	}
}
void solve(){
    int n; cin >> n;
    g.assign(n + 1, {});
    ans.clear();
    int root = 0;
    for(int i = 1; i <= n; i++){
    	int p; cin >> p;
    	if(i == p) root = i;
    	else g[p].push_back(i);
    }
    dep[root] = 1;
    dfs1(root, 0, 1);
    cout << ans.size() << "\n";
    for(auto v : ans){
    	cout << v.size() << "\n";
    	for(auto x : v)
    		cout << x << " ";
    	cout << "\n";
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}