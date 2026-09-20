#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int main()
{
	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	memset(dp, 0x3f, sizeof dp);
	int n; cin >> n;
	vector<int> c(n + 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = n;
	for(int i = 1; i <= n; i++) cin >> c[i], dp[i][i] = 1;
	// [l, r] [l + x, r - x]
	dp[0][0] = 0;
	for(int l = n; l >= 1; l--){
		for(int r = l + 1; r <= n; r++){
			for(int d = 0; l + d < r - d && c[l + d] == c[r - d]; d++){
				if(r - d - l - d <= 2) dp[l][r] = 1;
				else dp[l][r] = min(dp[l][r], dp[l + d + 1][r - d - 1]);
			}
			for(int k = l + 1; k <= r; k++)
				dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k][r]);
			// cerr << "l, r : " << l << " " << r << " " << dp[l][r] << '\n';
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}