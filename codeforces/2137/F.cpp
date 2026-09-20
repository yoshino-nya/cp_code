#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 400005;
// int b[N];
// int lowbit(int x){return (x) & (-x);}
// void add(int i, int x)
// {
// 	while(i < N){
// 		b[i] += x;
// 		i += lowbit(i);
// 	}
// }
// int query(int i)
// {
// 	int res = 0;
// 	while(i){
// 		res += b[i];
// 		i -= lowbit(i);
// 	}
// 	return res;
// }
int f[N][20];
void solve()
{
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f[i][0] = a[i];
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	/*
	找最后面一个大于等于b[i]的下标
	那么L可以取 [1, idx]，R可以取[i, n]
	*/
	for(int k = 1; (1 << k) <= n; k++)
		for(int i = 1; i + (1 << k) <= n + 1; i++)
			f[i][k] = max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
	auto query = [&](int l, int r){
		int k = __lg(r - l + 1);
		return max(f[l][k], f[r - (1 << k) + 1][k]);
	};
	// cerr << query(2, 3) << '\n';
	LL ans = 0;
	for(int i = 1; i <= n; i++){
		int lo = 0, hi = i;
		while(lo < hi - 1){
			int mid = (lo + hi) >> 1;
			if(query(mid, i - 1) >= max(a[i], b[i])) lo = mid;
			else hi = mid;
		}
		if(a[i] == b[i]) lo = i;
		// cerr << lo << '\n';
		ans += 1LL * lo * (n - i + 1);
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
/*
6
7 1 12 10 5 8
9 2 4 3 6 5

5 + 4 + 9 + 8 + 5
*/