// Date: 2025-02-27
// Time: 22:43:07

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    long long k;
    cin >> n >> x >> k;
    // 看-x有没有出现过
    // 然后再看 0 出现一次要多久
    string s;
    cin >> s;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i - 1] == 'L')
            pre[i]--;
        else
            pre[i]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i] == -x && i <= k) {
            ans++;
            k -= i;
            break;
        }
    }
    if(!ans){
        cout<<"0\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if(pre[i]==0){
            ans+=k/i;
            break;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}