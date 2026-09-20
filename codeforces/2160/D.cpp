// Date: 2025-10-12 23:22:17
// Author: wuyi
// 
// Problem: D. MAD Interactive Problem
// Contest: Codeforces - Codeforces Round 1058 (Div. 2)
// URL: https://codeforces.com/contest/2160/problem/d
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    vector<int> s;
    for(int i = 1; i <= 2 * n; i++){
    	s.push_back(i);
		
    	cout << "? " << s.size() << " ";
    	for(auto x : s)
    		cout << x << " ";
    	cout << endl;
    	int res; cin >> res;
    	a[i] = res;
    	if(res) s.pop_back();
    }
    s.clear();
    for(int i = 1; i <= 2 * n; i++)
    	if(a[i]) s.push_back(i);
	assert(s.size() == n);
    for(int i = 1; i <= 2 * n; i++){
    	if(!a[i]){
	    	cout << "? " << n + 1 << " ";
	    	for(auto x : s)
	    		cout << x << " ";
	    	cout << i;
	    	cout << endl;
	    	cin >> a[i];
    	}
    }
    cout << "! ";
    for(int i = 1; i <= 2 * n; i++)
    	cout << a[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}