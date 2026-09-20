// Date: 2025-10-11 15:36:11
// Author: wuyi
// 
// Problem: P4999 烦人的数学作业
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4999
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 1000000007;
int a[20];
LL dp[20], mi[20];
LL get(LL lmt){
	LL len = 0, n = lmt, ans = 0;
	while(lmt) a[++len] = lmt % 10, lmt /= 10;
	for(int i = len; i >= 1; i--){
		ans = (ans + dp[i - 1] * a[i]) % mod;
		for(int j = 1; j < a[i]; j++) ans = (ans + mi[i - 1] * j) % mod;
		n -= a[i] * mi[i - 1], ans = (ans + a[i] * (n + 1)) % mod;
	}
	return ans;
}
void solve(){
    LL L, R; cin >> L >> R;
    cout << (get(R) - get(L - 1) + mod) % mod << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    mi[0] = 1;
    for(int i = 1; i <= 18; i++){
    	dp[i] = (dp[i - 1] * 10 + mi[i - 1] * 45) % mod;
    	// cerr << dp[i] << " \n" [i == 18];
    	mi[i] = mi[i - 1] * 10 % mod;
    }
    int t; cin >> t; while(t--)
    {solve();} return 0;
}