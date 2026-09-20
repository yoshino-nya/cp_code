#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin() + 1, a.end(), greater<> ());
	LL ans = 0;
	for(int i = 1; i <= n && i <= m; i++){
		ans += 1LL * a[i] * (m - i + 1);
	}
	cout << ans << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}