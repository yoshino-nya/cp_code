#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
	LL a, b; cin >> a >> b;
	if((a & 1) && (b % 2 == 0)){
		if(b % 4){
			cout << "-1\n";
		}else{
			cout << a * (b / 2) + 2 << '\n';
		}
	}else if((a & 1) && (b & 1)){
		cout << a * b + 1 << '\n';
	}else if(b & 1){
		cout << "-1\n";
	}else{
		cout << a * (b / 2) + 2 << '\n';
	}
}
int main()
{
	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t; while(t--)
	{solve();} return 0;
}