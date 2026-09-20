#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // int l, r;
    string l, r;
    cin >> l >> r;
    int ans = 100;
    auto dfs = [&](auto &&self, int cur, int a, int b, int res, int id) -> void{
        if(id == l.size()){
            ans = min(ans, res);
            return;
        }
        a = a * 10 + l[id] - '0';
        b = b * 10 + r[id] - '0';
        for(int i = 0; i < 10; i++){
            int nxt = cur * 10 + i;
            if(nxt >= a && nxt <= b){
                if(nxt != a && nxt != b){
                    ans = min(ans, res);
                    return;
                }
                // ans += (i == l[id] -'0') + (i == r[id] - '0');
                self(self, nxt, a, b, res + (i == l[id] -'0') + (i == r[id] - '0'), id + 1);
            }
        }
    };
    dfs(dfs, 0, 0, 0, 0, 0);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}