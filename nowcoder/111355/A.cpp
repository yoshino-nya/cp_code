#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if(n < m) cout << "-1\n";
    else cout << s.substr(0, m) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}