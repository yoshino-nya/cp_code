// Date: 2025-02-24
// Time: 21:38:19

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    long long m;
    cin>>x>>m;
    long long ans=0;
    for(int i=1;i<=min(m,1LL*x-1);i++){
        if((i^x)%i==0)
            ans++;
    }
    if(m<x){
        cout<<ans<<'\n';
    }else{
        ans+=m/x-1;
        if(((m/x*x)^x)<=m) ans++;
        if(((m/x*x+x)^x)<=m) ans++;
        cout<<ans<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}