#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int cnt[200005];
// mt19937_64 rng(time(NULL));
// LL rnd(LL l, LL r){
// 	uniform_int_distribution<LL> dis(l, r);
// 	return dis(rng);
// }
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		// a[i] = rnd(0, n);
		// cerr << a[i] << " \n"[i == n];
	}
	int mex = 0;
	for(int _ = 1; _ <= k; _++){
		// for(int i = 0; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++)
			cnt[a[i]]++;

		for(int i = 0; i <= n; i++)
			if(!cnt[i]){
				mex = i;
				break;
			}
		int y = 0;
		for(int i = n; i >= 1; i--){
			if(a[i] == mex - 1) y++;
		}
		// cerr << y << " " << mex << '\n';
		if(y + mex - 1 == n && y > 1){
			// cout << "cnt: " << _ << " ";
			for(int i = 0; i <= n; i++) cnt[i] = 0;
			LL sum = accumulate(a.begin() + 1, a.end(), 0LL);
	
			if((k - _) % 2 == 0) sum += y;
			// cout << "1 : ";
			cout << sum << '\n';
			return;
		}
		// 大于 mex 的，变成 mex
		// 小于 mex 的，如果数量多，会变为 mex
		// 如果数量是1，则不会变
		for(int i = 1; i <= n; i++){
			if(a[i] < mex && cnt[a[i]] > 1) a[i] = mex;
			if(a[i] > mex) a[i] = mex;
		}
		int x = 0;
		cnt[0] = 0;
		for(int i = 1; i <= n; i++){
			cnt[i] = 0;
			if(a[i] == 0) x++;
			// if(a[i] == mex - 1) y++;
			// cerr << a[i] << " \n" [i == n];
		}
		if(x == n){
			// cout << "cnt: " << _ << " ";
			// cout << "2 : ";

			if((k - _) & 1){
				cout << n << '\n';
			}else
				cout << "0\n";
			return;
		}
		if(mex == n){
			// cout << "3 : ";
			// cout << "cnt: " << _ << " ";
			//0 1 2 
			cout << 1LL * n * (n - 1) / 2 << '\n';
			return;
		}

	}
	cout << accumulate(a.begin() + 1, a.end(), 0LL) << '\n';
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}
/*
2 4
0 2

0 1
0 1

*/