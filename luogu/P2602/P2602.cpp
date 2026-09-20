// Date: 2025-10-11 14:52:12
// Author: wuyi
// 
// Problem: P2602 [ZJOI2010] 数字计数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2602
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[20], dp[20], mi[20];
vector<LL> get(LL lmt){
	LL len = 0, n = lmt;
	vector<LL> ans(10);
	while(lmt) a[++len] = lmt % 10, lmt /= 10;
	for(int i = len; i >= 1; i--){
		for(int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
		for(int j = 0; j < a[i]; j++)
			ans[j] += mi[i - 1];
		n -= a[i] * mi[i - 1], ans[a[i]] += n + 1;
		ans[0] -= mi[i - 1];
	}
	return ans;
}
void solve(){
    LL l, r; cin >> l >> r;
    auto v1 = get(l - 1), v2 = get(r);
    for(int i = 0; i < 10; i++)
    	cout << v2[i] - v1[i] << " \n" [i == 9];
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    mi[0] = 1;
    for(int i = 1; i <= 13; i++){
    	dp[i] = 10 * dp[i - 1] + mi[i - 1];
    	mi[i] = mi[i - 1] * 10;
    }
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}