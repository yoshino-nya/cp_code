#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL dp[20][4];
int a[20];
LL dfs(int cur, int cnt, bool limit)
{
    if(cur == 0) return 1LL;
    if(!limit && dp[cur][cnt] != -1) return dp[cur][cnt];
    int r = limit ? a[cur] : 9;
    LL ans = 0;
    for(int i = 0; i <= r; i++){
        if(i == 0) ans += dfs(cur - 1, cnt, limit && i == a[cur]);
        else if(cnt < 3) ans += dfs(cur - 1, cnt + 1, limit && i == a[cur]);
    }
    if(!limit && dp[cur][cnt] == -1) dp[cur][cnt] = ans;
    return ans;
}
LL get(LL lmt)
{
    int len = 0;
    while(lmt){
        a[++len] = lmt % 10;
        lmt /= 10;
    }
    return dfs(len, 0, true);
}
void solve()
{
    LL l, r; cin >> l >> r;
    cout << get(r) - get(l - 1) << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
    for(int i = 0; i <= 19; i++)
        for(int j = 0; j < 4; j++)
            dp[i][j] = -1;
    int t; cin >> t; while(t--)
    {solve();} return 0;
}