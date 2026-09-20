// Date: 2025-03-15
// Time: 20:07:56

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        cin >> a[i];
        if (vis[a[i]])
            continue;
        vis[a[i]] = true;
        pre[i]++;
    }
    vis = vector<bool>(n + 1);
    vis[a[n]] = true, suf[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (vis[a[i]])
            continue;
        vis[a[i]] = true;
        suf[i]++;
    }
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum=max(sum,pre[i]+suf[i+1]);
    }
    cout<<sum<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}