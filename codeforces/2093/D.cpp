#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n,q;
char ch;

int dfs1(int sz,int val,int x,int y)
{
    if(x==1&&y==1) return val;
    int tt=sz/2;
    if(x>sz/2&&y>sz/2)
        return dfs1(sz>>1,val+(sz*sz/4),x-tt,y-tt);
    else if(x>sz/2)
        return dfs1(sz>>1,val+2*(sz*sz/4),x-tt,y);
    else if(y>sz/2)
        return dfs1(sz>>1,val+3*(sz*sz/4),x,y-tt);
    return dfs1(sz>>1,val,x,y);
}

pair<int,int>dfs2(int sz,int val,int x,int y,int find_val)
{
    if(val==find_val) return make_pair(x,y);
    int tt=sz*sz/4;
    if(find_val>=3*tt+val)
        return dfs2(sz>>1,val+3*tt,x,y+sz/2,find_val);
    else if(find_val>=2*tt+val)
        return dfs2(sz>>1,val+2*tt,x+sz/2,y,find_val);
    else if(find_val>=tt+val)
        return dfs2(sz>>1,val+tt,x+sz/2,y+sz/2,find_val);
    return dfs2(sz>>1,val,x,y,find_val);
}

void solve()
{
    cin>>n>>q;
    while(q--){
        cin>>ch>>ch;
        if(ch=='>'){
            int x,y;
            cin>>x>>y;
            assert(dfs1(1LL<<n,1,x,y)<=(1LL<<(2*n)));
            cout<<dfs1(1LL<<n,1,x,y)<<'\n';
        }
        else{
            int d;
            cin>>d;
            auto [l,r]=dfs2(1LL<<n,1,1,1,d);
            assert(l<=(1<<n)&&r<=(1<<n));
            assert(dfs1(1LL<<n,1,l,r)==d);
            cout<<l<<" "<<r<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}