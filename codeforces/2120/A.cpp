#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    array<int, 3> l, b;
    for(int i = 0; i < 3; i++)
        cin >> l[i] >> b[i];
    if(l[0] == l[2]){
        if(l[0] == b[0] + b[1] + b[2]){
            cout << "YES\n";
            return;
        }
    }
    if(b[0] == b[2]){
        if(b[0] == l[0] + l[1] + l[2]){
            cout << "YES\n";
            return;
        }
    }
    if(b[1] == b[2]){
        if(b[1] + b[0] == l[0] && l[1] + l[2] == l[0]){
            cout << "YES\n";
            return;
        }
    }
    if(l[1] == l[2]){
        if(l[1] + l[0] == b[0] && b[1] + b[2] == b[0]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    solve();
    return 0;
}