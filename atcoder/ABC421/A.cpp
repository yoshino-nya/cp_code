#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for(int i = 1; i <= n; i++) cin >> s[i];
    int x; string y;
    cin >> x >> y;
    if(s[x] != y) cout << "No\n";
    else cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}