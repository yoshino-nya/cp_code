#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
		cout << n + 1 - p[i] << " \n" [i == n];
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}