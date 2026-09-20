#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++) cnt[a[i]]++;
    int mex = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[mex]) mex++;
        else break;
    }
    if(mex > k) cout << cnt[k] << '\n';
    // else if(mex == k) cout << "0\n";
    else{
        int ans = 0;
        for(int i = mex; i < k; i++){
            if(!cnt[i]){
                ans++;
                cnt[k]--;
            }
        }
        if(cnt[k] > 0) ans += cnt[k];
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}