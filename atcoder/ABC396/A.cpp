// Date: 2025-03-08
// Time: 20:00:30

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i+1<=n;i++){
        if(a[i]==a[i+1]&&a[i-1]==a[i]){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";

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