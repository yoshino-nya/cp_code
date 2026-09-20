// Date: 2025-03-01
// Time: 20:11:45

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6;

int lst[N+1];

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    int ans=n+1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(lst[x]){
            ans=min(ans,i-lst[x]+1);
        }
        lst[x]=i;
    }
    cout<<(ans==n+1?-1:ans)<<'\n';
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