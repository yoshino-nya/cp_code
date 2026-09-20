// Date: 2025-09-30 17:21:25
// Author: wuyi
// 
// Problem: G - Sum of Min of XOR
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_g
// Memory Limit: 1024 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL calc(vector<int> &A, int m, int k){
	if(k == 0) return 0LL;
	vector<int> b0, b1;
	for(auto x : A){
		if(x >> (k - 1) & 1) b1.push_back(x);
		else b0.push_back(x);
	}
	if(b0.size() && b1.size()){
		if(m == (1 << k))
			return calc(b0, 1 << (k - 1), k - 1) + calc(b1, 1 << k)
	}
}
void solve(){
    int n, m; cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}