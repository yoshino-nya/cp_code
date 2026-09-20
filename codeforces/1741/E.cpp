#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(i + a[i] <= n)
			dp[i + a[i]] |= dp[i - 1];
		if(i - a[i] >= 1)
			dp[i] |= dp[i - a[i] - 1];
	}
	cout << (dp[n] ? "YES\n" : "NO\n");
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}