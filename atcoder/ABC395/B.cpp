// Date: 2025-03-01
// Time: 20:04:50

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<vector<char>>s(n+1,vector<char>(n+1));
    for(int i=1;i<=n;i++){
        int j=n-i+1;
        if(j<i) continue;
        for(int k=i;k<=j;k++)
            for(int l=i;l<=j;l++){
                if(i&1) s[k][l]='#';
                else s[k][l]='.'; 
            }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<s[i][j];
        }
        cout<<'\n';
    }
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