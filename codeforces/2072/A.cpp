#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n,k,p;
	cin>>n>>k>>p;
	k=abs(k);
	int ans=(k-1)/p+1;
	if(k==0) ans=0;
	cout<<(ans>n?-1:ans)<<'\n'; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
