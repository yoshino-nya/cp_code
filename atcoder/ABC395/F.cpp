// Date: 2025-03-02
// Time: 11:44:24

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> u(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> u[i] >> d[i];
    long long lo = 0, hi = 2e9 + 1;
    auto check = [&](long long H) {
        long long L = 0, R = H;
        for (int i = 0; i < n; i++) {
            //:之前的区间 [L-X,R+X]
            //:当前的区间 [max(0,H-D),U]
            L = max({L-x,H-d[i],0LL});
            R = min(R + x, 1LL*u[i]);
            if(L>R) return false;
        }
        return true;
    };
    while (lo < hi - 1) {
        long long mid = (lo + hi) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    // cout<<check(2)<<'\n';
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += u[i] + d[i] - lo;
    }
    cout << ans << '\n';
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