#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1);
    vector<pair<int, int>> op(m);
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        op[i - 1] = {l, r};
        for(int j = l; j <= r; j++){
            d[j]++;
        }
    }
    vector<int> ans(n + 1, -1);
    int tot = 0;
    auto otpt = [&](){
        for(int i = 1; i <= n; i++){
            if(ans[i] < 0) ans[i] = tot++;
            cout << ans[i] << " \n" [i == n];
        }
    };
    for(int i = 1; i <= n; i++){
        if(d[i] == m){
            ans[i] = tot++;
            otpt();
            return;
        }
    }
    for(int i = 1; i + 1 <= n; i++){
        bool ok1 = true, ok2 = true;
        for(auto [l, r] : op){
            if(l == i + 1) ok2 = false;
            if(r == i) ok1 = false;
        }
        if(ok1){
            ans[i] = tot++, ans[i + 1] = tot++;
            otpt();
            return;
        }
        if(ok2){
            ans[i + 1] = tot++, ans[i] = tot++;
            otpt();
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(d[i]){
            ans[i] = tot++;
            break;
        }
    }
    for(int i = n; i >= 1; i--){
        if(d[i] && ans[i] < 0){
            ans[i] = tot++;
            break;
        }
    }
    otpt();
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}