// Date: 2025-10-11 14:41:19
// Author: wuyi
// 
// Problem: D. Not Alone
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr LL inf = 1e18;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    LL ans = inf;
    for(int _ = 1; _ <= 4; _++){
    	vector<LL> dp(n + 1, inf);
    	dp[0] = 0;
    	for(int i = 2; i <= n; i++){
    		dp[i] = dp[i - 2] + abs(a[i] - a[i - 1]);
    		if(i >= 3)
    			dp[i] = min(dp[i], dp[i - 3] + max({a[i], a[i - 1], a[i - 2]}) - 
    			min({a[i], a[i - 1], a[i - 2]}));
    	}
    	ans = min(ans, dp[n]);
    	a.push_back(a[1]);
    	a.erase(a.begin() + 1);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}