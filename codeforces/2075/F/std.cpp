#include <bits/stdc++.h>
using namespace std;
struct apos{
	int a;
	int pos;
	friend bool operator<(apos a,apos b){
		if(a.a!=b.a)return a.a<b.a;
		return a.pos>b.pos;
	}
}ap[500000];
int a[500000],pref[500000],suf[500000];
vector<int> vecd,vecu;
struct seg{
	int l;
	int r;
	int vl;
};
vector<seg>v[500001];
void ins(int lx,int rx,int ly,int ry){
	seg sg;
	sg.l=ly;
	sg.r=ry;
	sg.vl=1;
	v[lx].push_back(sg);
	sg.vl=-1;
	v[rx].push_back(sg);
}
int val[1<<20],lazy[1<<20];
void gen(int t,int dep){
	val[t]=0;
	lazy[t]=0;
	if(dep==0)return;
	gen(t*2+1,dep-1);
	gen(t*2+2,dep-1);
}
void pushdown(int t){
	val[t*2+1]+=lazy[t];
	val[t*2+2]+=lazy[t];
	lazy[t*2+1]+=lazy[t];
	lazy[t*2+2]+=lazy[t];
	lazy[t]=0;
}
void add(int t,int dep,int l,int r,int vl){
	if(l==0&&r==(1<<dep))
	{
		val[t]+=vl;
		lazy[t]+=vl;
		return;
	}
	pushdown(t);
	int x=(1<<(dep-1));
	if(l<x)
	{
		if(r<=x)add(t*2+1,dep-1,l,r,vl);
		else
		{
			add(t*2+1,dep-1,l,x,vl);
			add(t*2+2,dep-1,0,r-x,vl);
		}
	}
	else add(t*2+2,dep-1,l-x,r-x,vl);
	val[t]=max(val[t*2+1],val[t*2+2]);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,j,ans,l,r,mid,lx,rx,ly,ry,tdep;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>ap[i].a;
			ap[i].pos=i;
		}
		sort(ap,ap+n);
		for(i=0;i<n;i++)a[ap[i].pos]=i;
		for(i=0;i<n;i++)pref[i]=a[i];
		for(i=1;i<n;i++)pref[i]=min(pref[i],pref[i-1]);
		for(i=0;i<n;i++)suf[i]=a[i];
		for(i=n-1;i>0;i--)suf[i-1]=max(suf[i-1],suf[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]==pref[i])vecd.push_back(i);
			if(a[i]==suf[i])vecu.push_back(i);
		};
		for(i=0;i<n;i++)
		{
			l=-1;
			r=vecd.size()-1;
			while(r-l>1)
			{
				mid=(l+r+1)/2;
				if(a[vecd[mid]]<=a[i])r=mid;
				else l=mid;
			}
			lx=r;
			l=0;
			r=vecd.size();
			while(r-l>1)
			{
				mid=(l+r)/2;
				if(vecd[mid]<=i)l=mid;
				else r=mid;
			}
			rx=r;
			l=-1;
			r=vecu.size()-1;
			while(r-l>1)
			{
				mid=(l+r+1)/2;
				if(vecu[mid]>=i)r=mid;
				else l=mid;
			}
			ly=r;
			l=0;
			r=vecu.size();
			while(r-l>1)
			{
				mid=(l+r)/2;
				if(a[vecu[mid]]>=a[i])l=mid;
				else r=mid;
			}
			ry=r;
			ins(lx,rx,ly,ry);
		}
		for(tdep=0;(1<<tdep)<vecu.size();tdep++);
		gen(0,tdep);
		ans=0;
		for(i=0;i<vecd.size();i++)
		{
			for(j=0;j<v[i].size();j++)add(0,tdep,v[i][j].l,v[i][j].r,v[i][j].vl);
			ans=max(ans,val[0]);
		}
		for(i=0;i<=vecd.size();i++)v[i].clear();
		vecd.clear();
		vecu.clear();
		cout<<ans<<'\n';
	}
	return 0;
}