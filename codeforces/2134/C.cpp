#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        if(i & 1){
            int mn = INT_MAX;
            if(i - 1 > 0) mn = min(mn, a[i - 1]);
            if(i + 1 <= n) mn = min(mn, a[i + 1]);
            if(a[i] > mn){
            ans += a[i] - mn;
            a[i] = mn;
            }
        }else{
            if(i < n){
                int sum = a[i - 1] + a[i + 1];
                if(sum > a[i]){
                    ans += sum - a[i];
                    a[i + 1] -= min(a[i + 1], sum - a[i]);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}