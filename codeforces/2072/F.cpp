#include<bits/stdc++.h>
using namespace std;

int val;
vector<int>dfs(int k)
{
	if(k==1){
		return {0,val};
	}
	vector<int>res(k+1);
	int x=k-(1<<__lg(k));
	if(!x) x=k>>1;
	vector<int>nxt=dfs(x);
	for(int i=1;i<=x;i++)
		res[i]=nxt[i];
	auto it=nxt.rbegin();
	for(int i=k,j=x;i>=k-x+1;i--,j--)
		res[i]=nxt[j];
	return res;
}
void solve()
{
//	vector<vector<char>>a(100,vector<char>(100));
//	for(int i=1;i<=99;i++)
//		for(int j=1;j<=i;j++){
//			if(j==1||j==i) a[i][j]='k';
//			else{
//				if(a[i-1][j-1]==a[i-1][j])
//					a[i][j]='0';
//				else
//					a[i][j]='k';
//			}
//			cout<<a[i][j]<<" \n"[j==i];
//		}
	//every triangle consists of 3 small one ,and the center part are all 0
	//for example,if n=7:
	//size 8 triangle consists of 3 4-size triangle
	//so the problem is to find 3-size trangle
	//*
	//** so k0k k0k 0 k0k
	int k;
	cin>>k>>val;
	vector<int>res=dfs(k);
	for(int i=1;i<=k;i++)
		cout<<res[i]<<" \n"[i==k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

