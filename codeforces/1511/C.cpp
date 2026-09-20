// Date: 2025-09-18 23:49:58
// Author: wuyi
// 
// Problem: C. Yet Another Card Deck
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1511/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n, q; cin >> n >> q;
    vector<int> idx(51);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	if(!idx[x]) idx[x] = i;
    }
    while(q--){
    	int t; cin >> t;
    	cout << idx[t] << " ";
    	for(int i = 1; i <= 50; i++)
    		if(idx[i] < idx[t]) idx[i]++;
    	idx[t] = 1;
    	
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}