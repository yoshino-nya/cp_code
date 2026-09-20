// Date: 2025-10-06 22:40:11
// Author: wuyi
// 
// Problem: B. Deck of Cards
// Contest: Codeforces - Educational Codeforces Round 183 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2145/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int len = k, A = 0, B = 0, C = 0;
    for(int i = 0; i < k; i++){
    	if(s[i] == '2') len++;
    	else if(s[i] == '0') A++;
    	else B++;
    }
    C = k - A - B;
    if(k == n){
    	cout << string(n, '-') << '\n';
    	return;
    }
    string ans(n, '?');
    for(int i = 0; i < A; i++) ans[i] = '-';
    for(int i = 1; i <= B; i++) ans[n - i] = '-';
    for(int i = A + C; i < n - B - C; i++) ans[i] = '+';
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}