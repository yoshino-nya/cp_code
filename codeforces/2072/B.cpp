#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int x=count(s.begin(),s.end(),'_');
	if((n-x)&1){
		cout<<1LL*(n-x)/2*((n-x)/2+1)*x<<'\n';
	}else{
		cout<<1LL*(n-x)/2*(n-x)/2*x<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

