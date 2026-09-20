#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if(x + y == s && dx * dy < 0) ans++;
        else if(x == y && dx * dy > 0) ans++;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    solve();
    return 0;
}