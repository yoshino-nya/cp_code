// Date: 2025-03-31
// Time: 18:05:03
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    priority_queue<array<int, 5>, vector<array<int, 5>>, greater<>> pq;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq1;
    vector<multiset<int>> price(n, multiset<int>());
    vector<int> days;
    for (int i = 1; i <= m; i++)
    {
        int s, t, p, c;
        cin >> s >> t >> p >> c;
        days.push_back(s);
        days.push_back(t + 1);
        for (int j = 1; j <= c; j++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            pq.push({s, t, a, b, p});
            price[a].insert(b);
        }
    }
    long long cost = 0;
    for (int i = 0; i < n; i++)
        cost += *price[i].begin();
    long long ans = cost;
    sort(days.begin(), days.end());
    days.erase(unique(days.begin(), days.end()), days.end());
    for (auto now : days)
    {
        while (!pq.empty() && pq.top()[0] == now)
        {
            auto [s, t, a, b, p] = pq.top();
            pq.pop();
            int val = 1LL * b * p / 100;
            cost -= *price[a].begin();
            price[a].insert(val);
            cost += *price[a].begin();
            pq1.push({t + 1, a, b, p});
        }
        while (!pq1.empty() && pq1.top()[0] == now)
        {
            auto [t, a, b, p] = pq1.top();
            pq1.pop();
            int val = 1LL * b * p / 100;
            cost -= *price[a].begin();
            price[a].erase(price[a].find(val));
            cost += *price[a].begin();
        }
        ans = min(cost, ans);
    }
    cout << ans << '\n';
    return 0;
}