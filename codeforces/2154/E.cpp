#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<LL> pre(n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    LL ans = pre[n];
    for(int i = 1; i <= n; i++){
        int lo = 0, hi = min(i, n - i + 1);
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            int lst = min(1LL * (mid - 1) * k, i - 1LL);
            int cur = min(1LL * mid * k, i - 1LL);
            assert(i + mid <= n);
            LL val = pre[cur] - pre[lst] + a[i + mid];
            if(val <= 1LL * (cur - lst + 1) * a[i])
                lo = mid;
            else hi = mid;
        }
        if(!lo) continue;
        LL idx = min(1LL * lo * k, i - 1LL);
        LL val = pre[idx] + pre[i + lo] - pre[i];
        ans = max(ans, pre[n] + 1LL * (idx + lo) * a[i] - val);
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}