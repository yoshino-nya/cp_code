#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), cnt(3);
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        cnt[a[i] + 1]++;
    }
    int ans = cnt[1];
    if(cnt[0] & 1) ans += 2;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}