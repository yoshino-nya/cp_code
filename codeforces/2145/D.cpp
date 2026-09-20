// Date: 2025-10-09 07:58:23
// Author: wuyi
// 
// Problem: D. Inversion Value of a Permutation
// Contest: Codeforces - Educational Codeforces Round 183 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2145/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int dp[32][1024], ok[32][1024];
void solve(){
    int n, k; cin >> n >> k;
    ok[0][0] = 1;
    for(int i = 0; i <= n; i++){
    	for(int x = 0; x <= n * (n - 1) / 2; x++){
    		for(int y = 1; y + i <= n; y++){
    			if(!ok[i][x]) continue;
    			int add = y * (y - 1) / 2;
    			ok[i + y][x + add] = 1;
    			dp[i + y][x + add] = y;
    		}
    	}
    }
    k = n * (n - 1) / 2 - k;
    if(ok[n][k]){
    	int cur = n, st = k;
    	vector<int> len;
    	while(cur){
    		len.push_back(dp[cur][st]);
    		int tt = dp[cur][st];
    		st -= tt * (tt - 1) / 2;
    		cur -= tt;
    	}
    	int x = n;
    	for(auto l : len){
    		for(int i = x - l + 1; i <= x; i++){
    			cout << i << " ";
    		}
    		x -= l;
    	}
    	cout << "\n";
    }else
    	cout << "0\n";
    for(int i = 0; i <= n; i++)
    	for(int x = 0; x <= n * (n - 1) / 2; x++)
    		dp[i][x] = ok[i][x] = 0;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}