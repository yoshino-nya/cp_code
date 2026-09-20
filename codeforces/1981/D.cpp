// Date: 2025-03-05
// Time: 21:29:08

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>ans{0,1,1};
    for(int i=3;;i+=4){
        ans.push_back(i);
        ans.push_back(i);
        ans.push_back(i+2);
        ans.push_back(i+2);
        ans.push_back(i/2);
        if(ans.size()>n) break;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" \n"[i==n];
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