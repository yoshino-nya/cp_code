// Date: 2025-09-18 18:58:43
// Author: wuyi
// 
// Problem: C. Smilo and Minecraft
// Contest: Codeforces - Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2113/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> s[i];
    	s[i] = " " + s[i];	
    }
    vector<vector<int>> pre(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
    		pre[i][j] = pre[i][j - 1] + (s[i][j] == 'g');
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
    		pre[i][j] += pre[i - 1][j];
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(s[i][j] != '.') continue;
    		int x1 = max(i - k + 1, 1);
    		int y1 = max(j - k + 1, 1);
    		int x2 = min(i + k - 1, n);
    		int y2 = min(j + k - 1, m);
    		int res = pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
    		ans = max(ans, pre[n][m] - res);
    	}
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}