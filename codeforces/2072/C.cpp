#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n,x;
	cin>>n>>x;
	vector<int>ans;
	int now=0;
	for(int i=0; i<n; i++) {
		if((i|x)==x) ans.push_back(i);
		else break;
		now|=i;
	}
	while(ans.size()==n&&now!=x)
		ans.pop_back();
	if(ans.size()<n){
		while(ans.size()<n)
			ans.push_back(x);
		now|=x;
	}
	assert(now==x);
	for(auto y:ans)
		cout<<y<<' ';
	cout<<'\n';
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

