#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1);
    vector<long long> pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    map<long long, int> mp;
    long long ans = 0;
    for(int i = 1, j = 0; i <= n; i++){
        if(a[i] == x){
            while(j < i)
                mp[pre[j]]++, j++;
        }else if(a[i] > x){
            mp.clear();
            j = i;
        }
        if(mp.contains(pre[i] - s))
            ans += mp[pre[i] - s];
    }
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