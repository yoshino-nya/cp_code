// Date: 2025-04-01
// Time: 17:51:53
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> pre(233), suf(233), t(n + 1), d1(n + 1);
    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        for (int j = 1; j < t[i]; j++)
            pre[t[i]] = max(pre[t[i]], pre[j] + 1);
        d1[i] = pre[t[i]];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j < t[i]; j++)
        {
            suf[t[i]] = max(suf[t[i]], suf[j] + 1);
        }
        // cerr << pre[t[i]] << " " << suf[t[i]] << '\n';
        ans = max(ans, suf[t[i]] + d1[i] - 1);
    }
    cout << n - ans << '\n';
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