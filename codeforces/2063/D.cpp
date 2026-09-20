// Date: 2025-03-12
// Time: 09:59:43

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    // 主要是看上面取多少个 下面取多少个
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    set<int> u, d;
    priority_queue<int, vector<int>, greater<>> uq, dq;
    for (int i = 1; i <= n; i++)
        cin >> a[i], u.insert(a[i]);
    for (int i = 1; i <= m; i++)
        cin >> b[i], d.insert(b[i]);
    int U = 0, D = 0;
    ll ans = 0;
    vector<ll> res;
    for (int i = 1;; i++)
    {
        int uu = 0, dd = 0;
        if (u.size() >= U + 2 && d.size() >= D + 1)
        {
            uu = *u.rbegin() - *u.begin();
        }
        if (d.size() >= D + 2 && u.size() >= U + 1)
        {
            dd = *d.rbegin() - *d.begin();
        }
        // cerr<<dd<<" "<<uu<<'\n';
        if (dd + uu == 0)
        {
            // cerr<<u.size()<<" "<<U<<" "<<d.size()<<" "<<D<<'\n';
            // cerr<<"empty: "<<uq.size()<<'\n';
            // 上面的减去两个，或者是下面的减去两个
            if (u.size() >= U + 3 && !dq.empty())
            {
                ans += *u.rbegin() - *u.begin();
                // uq.push(*u.rbegin() - *u.begin());
                u.erase(u.begin()), u.erase(prev(u.end()));
                ans += *u.rbegin() - *u.begin();
                // uq.push(*u.rbegin() - *u.begin());
                u.erase(u.begin()), u.erase(prev(u.end()));
                ans -= dq.top();
                dq.pop();
                U--;
            }
            else if (d.size() >= D + 3 && !uq.empty())
            {
                // cerr<<"here\n";
                ans += *d.rbegin() - *d.begin();
                // dq.push(*d.rbegin() - *d.begin());
                d.erase(d.begin()), d.erase(prev(d.end()));
                ans += *d.rbegin() - *d.begin();
                // dq.push(*d.rbegin() - *d.begin());
                d.erase(d.begin()), d.erase(prev(d.end()));
                ans -= uq.top();
                uq.pop();
                D--;
            }
            else
                break;
        }
        else if (dd >= uu)
        {
            d.erase(d.begin());
            d.erase(prev(d.end()));
            U++;
            ans += dd;
            dq.push(dd);
        }
        else
        {
            u.erase(u.begin());
            u.erase(prev(u.end()));
            D++;
            ans += uu;
            uq.push(uu);
        }
        // cout<<ans<<" ";
        res.push_back(ans);
    }
    cout << res.size() << '\n';
    for (auto x : res)
        cout << x << " ";
    cout << '\n';
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