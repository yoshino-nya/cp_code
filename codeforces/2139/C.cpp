#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	LL k, x; cin >> k >> x;
	LL y = (1LL << (k + 1)) - x;
	vector<int> ans;
	while(x != y){
		if(x > y){
			ans.push_back(2);
			x -= y;
			y <<= 1;
		}else{
			ans.push_back(1);
			y -= x;
			x <<= 1;
		}
	}
	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for(auto x : ans)
		cout << x << " ";
	cout << "\n";
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}