// Date: 2025-10-06 22:50:58
// Author: wuyi
// 
// Problem: C. Monocarp's String
// Contest: Codeforces - Educational Codeforces Round 183 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2145/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 4e5 + 5;

int vis[N << 2];
void solve(){
    // A : x, B : y
    // A : x + k + z, B : y + k
    // x - y, x - y + z
    int n; cin >> n;
    string s; cin >> s;
    int z = 0;
    int A = 0, B = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'a') A++;
    	else B++;
    }
    if(A == B){
    	cout << "0\n";
    	return;
    }
    z = A - B;
    // A = B = 0;
    int ans = INT_MAX;
    for(int i = n - 1; i >= 0; i--){
    	vis[A - B + N] = i;
    	if(s[i] == 'a') A--;
    	else B--;
    	// assert(A - B + z + N > )
    	if(vis[A - B + z + N]){
    		ans = min(vis[A - B + z + N] - i + 1, ans);
    	}
    }
    A = 0, B = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == 'a') A++;
    	else B++;
    	vis[A - B + N] = 0;
    }
    if(ans >= n) ans = -1;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}