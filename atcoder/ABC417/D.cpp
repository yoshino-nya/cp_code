#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[10010][1010];
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> p[i] >> a[i] >> b[i];
    for(int i = 0; i <= 1000; i++){
        dp[n + 1][i] = i;
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1000; j >= 0; j--){
            int k = j;
            if(p[i] >= j) k += a[i];
            else k -= b[i];
            k = max(0, k);
            dp[i][j] = dp[i + 1][k];
        }
    }
    vector<int> pre(n + 1);
    // 看 x 啥时候变成小于等于 500
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + b[i];
    int q;
    cin >> q;
    while(q--){
        int x; cin >> x;
        if(x <= 500){
            cout << dp[1][x] << '\n';
            continue;
        }
        // 看 x 啥时候小于等于 500
        // 也就是找最小的 idx, 满足 x - pre[idx] <= 500
        int idx = lower_bound(pre.begin() + 1, pre.end(), x - 500) - pre.begin();
        if(idx == n + 1){
            cout << x - pre[n] << '\n';
        }else{
            // assert(x - pre[idx] <= 500 && x - pre[idx - 1] > 500);
            cout << dp[idx + 1][x - pre[idx]] << '\n';
        }
    }
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T; while(T--)
    {solve();} return 0;
}