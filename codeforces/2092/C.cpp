/*
3
5 3 9

2
3 2

4
1 2 2 1

5
5 4 3 2 9
1 3 2 17
*/
// Date: 2025-03-29
// Time: 22:54:10
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), p, q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            p.push_back(a[i]);
        else
            q.push_back(a[i]);
    }
    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    if (p.empty() || q.empty())
    {
        cout << a[n] << '\n';
        return;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    ans -= p.size() - 1;
    cout << ans << '\n';
}//3 3 4 5 9
//3 3 16 1 1

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