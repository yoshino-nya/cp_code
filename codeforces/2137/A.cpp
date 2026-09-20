#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int k, x; cin >> k >> x;
	cout << x * (1 << k) << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}