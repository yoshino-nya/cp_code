#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    vector<int> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(a[2] < a[0] + a[1]) cout << a[2] - a[0] << "\n";
    else cout << a[1] << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}