// Date: 2025-03-22
// Time: 23:32:06
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    reverse(d.begin() + 1, d.end());
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = k + 1; i <= n; i++)
    {
        // cerr<<d[i]<<'\n';
        if (1LL * ((int)pq.size() + 1) * (k + 1) <= i)
            pq.push(d[i]);
        else
        {
            pq.push(d[i]);
            // cerr << pq.top() << '\n';
            pq.pop();
        }
    }
    // cerr<<'\n';
    long long ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        // cerr<<ans<<'\n';
        pq.pop();
    }
    // cerr<<'\n';
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}