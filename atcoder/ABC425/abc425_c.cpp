// Date: 2025-09-27 20:07:08
// 
// Problem: C - Rotate and Sum Query
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> pre(n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int op, c, l, r;
    int off = 0;
    while(q--){
    	cin >> op;
    	if(op == 1){
    		cin >> c;
    		off = (off + c) % n;
    	}else{
    		cin >> l >> r;
    		l--, r--;
    		l = (l + off) % n, r = (r + off) % n;
    		if(l <= r) cout << pre[r + 1] - pre[l] << '\n';
    		else cout << pre[n] - pre[l] + pre[r + 1] << '\n';
    	}
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
