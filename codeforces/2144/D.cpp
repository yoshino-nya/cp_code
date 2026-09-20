#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 200005;
int cnt[N], pre[N];
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        cnt[c[i]]++;
    }
    for(int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + cnt[i];
    LL ans = LLONG_MIN;
    for(int x = 2; x < N; x++){
        LL res = -1LL * n * k;
        for(int y = 1; y < N; y += x){
            int cnt1 = pre[min(y + x - 1, N - 1)] - pre[y - 1];
            res += 1LL * min(cnt1, cnt[y / x + 1]) * k + 1LL * cnt1 * (y / x + 1);
        }
        ans = max(ans, res);
    }
    for(int i = 1; i <= n; i++) cnt[c[i]] = 0;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}