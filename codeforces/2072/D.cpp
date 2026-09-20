#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2000;

void solve() {
	int n;
	cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>cnt(n+1,vector<int>(N+1)),tnc(n+1,vector<int>(N+1));
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cnt[i]=cnt[i-1];
		tnc[i]=tnc[i-1];
		for(int j=a[i]+1; j<=N; j++)
			cnt[i][j]++;//前面的比它小的数字
		for(int j=1; j<a[i]; j++)
			tnc[i][j]++;
	}
	auto calc=[&](int i,int j) {
		int res=0;
		res+=tnc[j][a[i]]-tnc[i][a[i]];//[i,j]之间的比a[i]大的数字
		res-=cnt[j][a[i]]-cnt[i][a[i]];
		return res;
	};
	vector<array<int,3>>ans;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			ans.push_back({i,j,calc(i,j)});
		}
	}
	sort(ans.begin(),ans.end(),[](array<int,3>x,array<int,3>y) {
		return x[2]<y[2];
	});
	if(ans.empty()||ans[0][2]>0)
		cout<<"1 1\n";
	else
		cout<<ans[0][0]<<" "<<ans[0][1]<<'\n';
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

