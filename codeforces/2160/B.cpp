// Date: 2025-10-12 22:54:49
// Author: wuyi
// 
// Problem: B. Distinct Elements
// Contest: Codeforces - Codeforces Round 1058 (Div. 2)
// URL: https://codeforces.com/contest/2160/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    vector<LL> b(n + 1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<int> a(n + 1);
    int tot = 0;
    for(int i = 1; i <= n; i++){
    	if(b[i] == b[i - 1] + i){
    		a[i] = ++tot;
    	}else{
    		LL s = b[i] - b[i - 1];
    		a[i] = a[i - s];
    	}
    	
    }
    for(int i = 1; i <= n; i++)
    	cout << a[i] << " \n" [i == n];
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}