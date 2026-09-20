#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	int n; cin >> n;
	vector<int> x(n);
	vector<int> vec;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < n; i++){
		int t; cin >> t;
		vec.push_back(x[i] - t);
		vec.push_back(x[i] + t);
	}
	sort(vec.begin(), vec.end());
	int mn = *min_element(vec.begin(), vec.end());
	int mx = *max_element(vec.begin(), vec.end());
	cout << (mx + mn) / 2 ;
	if((mx - mn) & 1) cout << ".5";
	cout << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}