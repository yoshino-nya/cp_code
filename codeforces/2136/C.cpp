#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1), nxt(n + 1), cnt(n + 1), idx(n + 1), lst(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(!cnt[a[i]]){
            idx[a[i]] = i;
        }
        cnt[a[i]]++;
        nxt[lst[a[i]]] = i;
        while(cnt[a[i]] > a[i]){
            cnt[a[i]]--;
            idx[a[i]] = nxt[idx[a[i]]];
        }
        dp[i] = max(dp[i], dp[i - 1]);
        if(cnt[a[i]] == a[i]){
            // cerr << idx[a[i]] << " \n";
            dp[i] = max(dp[i], dp[idx[a[i]] - 1] + a[i]);
        }
        // cerr << "dp[i] : " << dp[i] << " \n";
        lst[a[i]] = i;
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}