// Date: 2025-09-18 23:11:16
// Author: wuyi
// 
// Problem: E. Compressed Tree
// Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1901/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 500005;
LL dp[N];
int a[N];
vector< vector<int> > g;
void dfs(int u, int p){
	dp[u] = a[u];
	for(auto v : g[u]){
		if(v == p) continue;
		dfs(v, u);
		if(dp[v] > 0) dp[u] += dp[v];
	}
	dp[u] = max(0LL, dp[u]);
}
void solve(){
    /*
    compress 的过程一定是一直删叶子，然后最后会剩下两个点是吧。
    首先也可能是只剩下一个点，也可能0个点
    
    不对啊，呃
    前面删点只能删叶子节点
    所以是不是删完仍是一棵树
    
    test3的9是咋来的。。。
    哦哦，compress的过程不一定能删点的
    必须满足叶子节点的父节点只有一个子节点才可以删
    
    所以每个子树的贡献是独立的吧
    根节点只留一个子树可以不需要根节点，否则必须要。
    
    呃，不对，如果是一条链，这样答案必然是两个端点
    然后也可能是一棵树，但需要满足每个点的度都不为2
    那咋搞，也可能本来不满足，但我们把它弄得满足。。。
    */
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    g.assign(n + 1, {});
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, 0);
    cout << *max_element(dp + 1, dp + n + 1) << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}