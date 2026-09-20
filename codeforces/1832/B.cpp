#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<LL> suf(n + 2);
    suf[n] = a[n];
    for(int i = n - 1; i >= 1; i--){
        suf[i] = suf[i + 1] + a[i];
    }
    LL ans = suf[n - k + 1];
    LL s = 0;
    for(int i = 1; i <= 2 * k; i += 2){
        s += a[i] + a[i + 1];
        int x = k - (i + 1) / 2;
        ans = min(ans, s + suf[n + 1 - x]);
    }
    cout << suf[1] - ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}