#include <bits/stdc++.h>
using namespace std;

int dp[200005][3];
void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 2; j++)
			dp[i][j] = n;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= 2; x++)
			dp[i][a[i]] = min(dp[i][a[i]], dp[i - 1][x]);
		dp[i][a[i]] = min(dp[i][a[i]], dp[i - 1][0] + 1);

		for (int x = 0; x <= a[i] && x <= 1; x++) {
			for (int y = 0; y < a[i - x]; y++) {
				dp[i][a[i] - x] = min(dp[i][a[i] - x], dp[i - x][y]);
				// if (i == 7 && dp[n][0] == 3)
				// 	cerr << x << " " << y << '\n';
			}
		}

		for (int x = 0; x <= a[i] && x <= 1; x++) {
			for (int y = 0; y <= 2; y++)
				dp[i][a[i] - x] = min(dp[i][a[i] - x], dp[i - x - 1][y] + 1);
		}
		// for (int x = 0; x <= 2; x++)
		// 	cerr << dp[i][x] << " \n" [x == 2];
	}
	cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	// int t; cin >> t; while(t--)
	{solve();} return 0;
}