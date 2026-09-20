#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL DP[20][10];
int a[20];
LL dfs(int cur, int lst, bool fst, bool limit)
{
    if(cur == 0) return 1LL;
    if(fst && !limit && DP[cur][lst] != -1) return DP[cur][lst];
    LL ans = 0, up = limit ? a[cur] : 9;
    for(int i = 0; i <= up; i++){
        if(!fst || abs(i - lst) >= 2) ans += dfs(cur - 1, i, fst || (i != 0), limit && i == a[cur]);
    }
    // cerr << format("cur : {}, lst : {}, fst : {}, limit : {}, ans : {}\n", cur, lst, fst, limit, ans);
    if(fst && !limit) DP[cur][lst] = ans;
    return ans;
}
LL get(LL lmt)
{
    int len = 0;
    while(lmt){
        a[++len] = lmt % 10;
        lmt /= 10;
    }
    return dfs(len, 0, 0, 1);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(DP, -1, sizeof(DP));
    LL l, r; cin >> l >> r;
    cout << get(r) - get(l - 1) << "\n";
}