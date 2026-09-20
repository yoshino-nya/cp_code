#include<bits/stdc++.h>
using namespace std;

using LL = long long;
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int p = 0;
    for(int i = 1; i <= n; i++){
        p = max(p, a[i]);
        if(i % 2 == 0)
            a[i] = p;
    }
    LL ans = 0;
    for(int i = 1; i <= n; i += 2){
        p = 0;
        if(i > 1) p = max(p, a[i] - a[i - 1] + 1);
        if(i < n) p = max(p, a[i] - a[i + 1] + 1);
        ans += p;
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}