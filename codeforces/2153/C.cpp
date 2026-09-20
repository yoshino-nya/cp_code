// Date: 2025-10-10 23:08:02
// Author: wuyi
// 
// Problem: C. Symmetrical Polygons
// Contest: Codeforces - Codeforces Round 1057 (Div. 2)
// URL: https://codeforces.com/contest/2153/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL get(vector<int> a, int n){
	vector<int> tmp;
	LL ans = 0;
	if(a.size() < 3) return 0LL;
	bool ok = false;
	int e = 0;
	for(int i = 1; i <= n; ){
		int j = i + 1, cnt = 1;
		while(j <= n && a[j] == a[i])
			cnt++, j++;

		ans += 1LL * a[i] * cnt;
		e += cnt;
		if(cnt & 1) tmp.push_back(a[i]), ans -= a[i], e--;
		i = j;
	}
	if(!ans || tmp.empty()) return ans;
	LL res = ans;
	for(int i = (int)tmp.size() - 1; i >= 0; i--){
		// cerr << tmp[i] << " " << ans << '\n';
		if(tmp[i] < ans) res = max(res, ans + tmp[i]);
		if(i && tmp[i] < tmp[i - 1] + ans){
			res = max(ans, ans + tmp[i] + tmp[i - 1]);
			break;
		}
	}
	if(e == 2 && res == ans) return 0LL;
	return res;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    sort(a.begin(), a.end());
    LL ans = get(a, n);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}