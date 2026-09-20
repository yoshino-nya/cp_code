// Date: 2025-09-18 08:31:41
// Author: wuyi
// 
// Problem: E1. Maple and Tree Beauty (Easy Version)
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/E1
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n, k; cin >> n >> k;
    vector<int> dep(n + 1), fa(n + 1), cnt(n + 1), deg(n + 1);
    cnt[0] = 1;
    for(int i = 2; i <= n; i++){
    	cin >> fa[i];
    	dep[i] = dep[fa[i]] + 1;
    	cnt[dep[i]]++;
    	deg[fa[i]]++;
    }
    int mxdep = INT_MAX;
    for(int i = 1; i <= n; i++)
    	if(!deg[i]) mxdep = min(mxdep, dep[i]);
	vector<int> dp(n + 1);
	dp[0] = 1;
	int sum = 0;
    for(int i = 0; i <= mxdep; i++){
    	for(int j = sum; j >= 0; j--){
    		dp[j + cnt[i]] |= dp[j];
    	}
    	sum += cnt[i];
    }
    for(int i = 0; i <= sum; i++){
    	if(dp[i]){
    		if(i <= k && sum - i <= n - k){
    			cout << mxdep + 1 << "\n";
    			return;
    		}
    	}
    }
    cout << mxdep << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}