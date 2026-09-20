#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += max(1, a[i]);
    cout << sum << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}