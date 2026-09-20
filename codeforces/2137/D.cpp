#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1, -1);
	vector< vector<int> > b(n + 1);
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		b[x].push_back(i);
	}
	int tot = 0;
	for(int i = 1; i <= n; i++){
		if(int(b[i].size()) % i){
			cout << "-1\n";
			return;
		}
		for(int j = 0; j < b[i].size(); j++){
			if(j % i == 0) ++tot;
			a[b[i][j]] = tot;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << a[i] << " \n" [i == n];
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}