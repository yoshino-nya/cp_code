// Date: 2025-09-29 10:04:37
// Author: wuyi
// 
// Problem: F. Nezuko in the Clearing
// Contest: Codeforces - Codeforces Round 1054 (Div. 3)
// URL: https://codeforces.com/contest/2149/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int h, d; cin >> h >> d;
    int lo = -1, hi = d + 1;

    auto check = [&](int r){
    	int s = d / (r + 1);
    	int rem = d % (r + 1);
    	return 1LL * s * (s + 1) / 2 * (r + 1 - rem) + 1LL * (s + 1) * (s + 2) / 2 * rem < h + r;
    };
    while(lo < hi - 1){
    	int mid = (lo + hi) >> 1;
    	if(check(mid)) hi = mid;
    	else lo = mid;
    }
    cout << d + hi << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}