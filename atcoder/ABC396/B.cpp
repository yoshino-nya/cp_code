// Date: 2025-03-08
// Time: 20:03:23

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin>>q;
    stack<int>stk;
    for(int i=1;i<=100;i++)
        stk.push(0);
    while(q--){
        int op;
        cin>>op;
        if(op&1){
            int x;
            cin>>x;
            stk.push(x);
        }else{
            cout<<stk.top()<<'\n';
            stk.pop();
        }
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