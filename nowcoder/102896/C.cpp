// Date: 2025-03-02
// Time: 19:17:09

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    unsigned long long xx=0;
    cin>>xx;
    string s=to_string(xx);
    s=s+s;
    unsigned long long x=0;
    for(auto i:s){
        x=x*10+(i-'0');
    }
    assert(x%xx==0);
    cout<<(x/xx)<<'\n';
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