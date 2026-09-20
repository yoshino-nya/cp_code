// Date: 2025-09-18 17:19:26
// Author: wuyi
// 
// Problem: E2. Maple and Tree Beauty (Hard Version)
// Contest: Codeforces - Codeforces Round 1048 (Div. 2)
// URL: https://codeforces.com/contest/2139/problem/E2
// Memory Limit: 1024 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
bitset<200005> dp;
void solve(){
    int n, k; cin >> n >> k;
    vector<int> p(n + 1), dep(n + 1), cnt(n + 1), deg(n + 1);
    cnt[0] = 1;
    for(int i = 2; i <= n; i++){
    	cin >> p[i];
    	dep[i] = dep[p[i]] + 1;
    	cnt[dep[i]]++;
    	deg[p[i]]++;
    }
    int mxdep = INT_MAX;
    for(int i = 1; i <= n; i++)
    	if(!deg[i]) mxdep = min(mxdep, dep[i]);
    dp.reset();
    vector<int> items(cnt.begin(), cnt.begin() + mxdep + 1);
    sort(items.begin(), items.end());
    vector<int> v;
    for(int i = 0; i < items.size();){
    	int j = i + 1;
    	while(j < items.size() && items[i] == items[j]) j++;
    	int t = j - i;
    	for(int x = 1; x <= t; x <<= 1){
    		v.push_back(x * items[i]);
    		t -= x;
    	}
    	if(t) v.push_back(t * items[i]);
    	i = j;
    }
    int sum = 0;
    dp[0] = 1;
    for(auto x : v){
    	dp |= dp << x;
    	sum += x;
	}
	for(int i = 0; i <= sum; i++){
		if(dp[i] && i <= k && sum - i <= n - k){
			cout << mxdep + 1 << "\n";
			return;
		}
	}
	cout << mxdep << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}