// Date: 2025-03-03
// Time: 00:53:33

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l,n;
    cin>>l>>n;
    int mx=0,mn=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mn=max(mn,min(x,l+1-x));
        mx=max(mx,max(x,l+1-x));
    }
    cout<<mn<<" "<<mx<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
