// Date: 2025-10-10 16:50:00
// Author: wuyi
// 
// Problem: C. Tree Diameter
// Contest: Codeforces - Forethought Future Cup - Elimination Round
// URL: https://codeforces.com/problemset/problem/1146/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    int d = 0;
    for(int k = 0; (1 << k) <= n; k++){
    	vector<int> s1, s2;
    	for(int i = 1; i <= n; i++){
    		if(i >> k & 1) s1.push_back(i);
    		else s2.push_back(i);
		}
		cout << s1.size() << " " << s2.size() << " ";
		for(auto x : s1) cout << x << " ";
		for(auto x : s2) cout << x << " ";
		cout << endl;
		int x; cin >> x;
		d = max(d, x);
    }
    cout << "-1 " << " " << d << endl;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}