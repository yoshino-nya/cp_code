#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    /*
    a[l] + a[r] + x > a[n], x < a[l] + a[r]
    x > a[n] - a[l] - a[r]
    */
    long long ans = 0;
    for(int l = 1; l <= n; l++){
        for(int r = l + 1; r < n; r++){
            auto L = upper_bound(a.begin() + r + 1, a.end(), a[n] - a[l] - a[r]) - a.begin();
            auto R = lower_bound(a.begin() + r + 1, a.end(), a[l] + a[r]) - a.begin() - 1;
            if(L <= R)
                ans += R - L + 1;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}