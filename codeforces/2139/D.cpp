#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<pair<int, int>> vec;
	vector<int> stk, L(n + 1), R(n + 1);
	for(int i = 1; i <= n; i++){
		while(!stk.empty() && a[stk.back()] <= a[i])
			stk.pop_back();
		if(!stk.empty()) L[i] = stk.back();
		stk.push_back(i);
	}
	stk.clear();
	for(int i = n; i >= 1; i--){
		while(!stk.empty() && a[stk.back()] >= a[i])
			stk.pop_back();
		if(!stk.empty()) R[i] = stk.back();
		stk.push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(L[i] && R[i])
			vec.push_back({L[i], R[i]});
	}
	sort(vec.begin(), vec.end());
	vector<int> arr(n + 1, n + 1);
	for(auto [l, r] : vec)
		arr[l] = min(arr[l], r);
	for(int i = n - 1; i >= 1; i--)
		arr[i] = min(arr[i], arr[i + 1]);
	while(q--){
		int l, r; cin >> l >> r;
		if(arr[l] <= r) cout << "NO\n";
		else cout << "YES\n";
	}
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}
/*
5 4 6 2
3 2 5 1 4， 3 2 1 5 4， 1 2 3 5 4， 1 2 3 4 5
3 2 5 1 4， 3 2 1 5 4， 3 1 2 5 4， 1 2 3 5 4， 

5 1 4 2 3, 
1 5 4 2 3, 1 4 5 2 3, 1 4 2 5 3, 1 4 2 3 5, 
1 2 4 3 5, 1 2 3 4 5

1 5 4 2 3

*/