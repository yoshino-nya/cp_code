#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int a, b; cin >> a >> b;
	if(a > b) swap(a, b);
	int c = lcm(a, b);
	if(a == b) cout << "0\n";
	else if(b == c) cout << "1\n";
	else cout << "2\n";
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}