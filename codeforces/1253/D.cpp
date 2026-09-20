#include <bits/stdc++.h>
using namespace std;

int f[200005];
int find(int x){return f[x] == x ? f[x] : f[x] = find(f[x]);}
void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		int fu = find(u), fv = find(v);
		if(fu > fv) swap(fu, fv);
		f[fu] = fv;
	}
	int ans = 0;
	for(int i = 2; i < n; i++){
		int fx = find(f[i - 1]);
		int fy = find(f[i]);
		if(fx > i && fx != fy){
			if(fx > fy) swap(fx, fy);
			f[fx] = fy;
			ans++;
		}
	}
	cout << ans << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	// int t; cin >> t; while(t--)
	{solve();} return 0;
}