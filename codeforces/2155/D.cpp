// Date: 2025-10-13 08:33:04
// Author: wuyi
// 
// Problem: D. Batteries
// Contest: Codeforces - Codeforces Round 1056 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2155/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    for(int i = 1; ; i++){
    	for(int j = 0; j < n;j++){
    		cout << j + 1 << " " << (i + j) % n + 1 << endl;
    		int x; cin >> x;
    		if(x) return;
    	}
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}