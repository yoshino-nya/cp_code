// Date: 2025-09-29 14:50:11
// Author: wuyi
// 
// Problem: E. Compatible Numbers
// Contest: Codeforces - Codeforces Round 112 (Div. 2)
// URL: https://codeforces.com/problemset/problem/165/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int lmt = (1 << 22) - 1;
    vector<int> dp(lmt + 1);
    for(int i = 1; i <= n; i++) dp[a[i]] = a[i];
    for(int i = 0; i < 22; i++){
    	for(int j = 1; j <= lmt; j++){
    		if(j >> i & 1)
    			if(!dp[j]) dp[j] = dp[j ^ (1 << i)];
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << (dp[a[i] ^ lmt] ? dp[a[i] ^ lmt] : -1) << " \n" [i == n];
    }
    
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}