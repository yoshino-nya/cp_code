// Date: 2025-03-01
// Time: 20:00:20

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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