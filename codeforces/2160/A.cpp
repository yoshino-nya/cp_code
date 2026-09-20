// Date: 2025-10-12 22:35:10
// Author: wuyi
// 
// Problem: A. MEX Partition
// Contest: Codeforces - Codeforces Round 1058 (Div. 2)
// URL: https://codeforces.com/contest/2160/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);

    int mex = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++)
    	if(mex == a[i]) mex++;
    cout << mex << '\n';
    /*
    0 1 2 6 7
    0 1 2 4 5
    0
    0
    */
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}