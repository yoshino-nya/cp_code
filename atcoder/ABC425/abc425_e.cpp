#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int C[5050][5050], mod;

void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	LL ans = 1, pre = 0;
	for(int i = 1; i <= n; i++){
		pre += a[i];
		ans = ans * C[pre][a[i]] % mod;
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t >> mod;
	for(int i = 0; i <= 5000; i++){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	cerr << C[6][3] << '\n';
	while(t--)
	{solve();} return 0;
}