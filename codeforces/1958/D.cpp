#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	auto calc = [](vector<int> &vec){
		LL sum = 2 * accumulate(vec.begin(), vec.end(), 0LL);
		if(vec.size() % 2 == 0) return sum;
		LL res = sum;
		for(int i = 0; i < vec.size(); i += 2)
			res = min(res, sum - vec[i]);
		return res;
	};
	for(int i = 1; i <= n; ){
		if(a[i]){
			int j = i + 1;
			vector<int> vec{a[i]};
			while(j <= n && a[j])
				vec.push_back(a[j++]);
			ans += calc(vec);
			i = j;
		}else i++;
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