// Date: 2025-09-27 20:00:18
// 
// Problem: A - Sigma Cubes
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
    	if(i & 1) sum -= i * i * i;
    	else sum += i * i * i;
    }
    cout << sum << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
