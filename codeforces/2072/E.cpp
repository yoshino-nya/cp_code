#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int k;
	cin>>k;
	if(!k){
		cout<<"0\n";
		return;
	}
	int X=1,Y=1;
	vector<pair<int,int>>ans;
	auto work=[&](int cnt){
		int sum=1;
		int x=2;
		ans.push_back({X,++Y});
		ans.push_back({X,++Y});
		while(sum+x<cnt){
			sum+=x;
			x++;
			ans.push_back({X,++Y});
		}
		++X,Y+=2;
		return sum;
	};
	int now=0;
	while(now<k){
		now+=work(k-now);
	}
	cout<<ans.size()<<'\n';
	for(auto it:ans)
		cout<<it.first<<" "<<it.second<<'\n';
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

