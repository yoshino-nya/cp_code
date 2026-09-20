
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    long long lc = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(lc <= n + m)
            lc = lcm(a[i], lc);
    }
    sort(a.begin() + 1, a.end());
    vector<bool> ok(n + m + 1);
    for(int i = 1; i <= n; i++){
        if(ok[a[i]]) continue;
        for(int x = a[i]; x <= n + m; x += a[i])
            ok[x] = true;
    }
    int A = 0, B = 0, C = 0;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        if(x % lc == 0) A++;
        else if(!ok[x]) B++;
        else C++;
    }
    A += C & 1;
    cout << (A > B ? "Alice\n" : "Bob\n");
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}