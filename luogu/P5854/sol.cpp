// Date: 2025-04-01
// Time: 15:17:56
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    auto build = [&]()
    {
        vector<int> stk;
        for (int i = 1; i <= n; i++)
        {
            while (!stk.empty() && p[stk.back()] > p[i])
                l[i] = stk.back(), stk.pop_back();
            if (!stk.empty())
                r[stk.back()] = i;
            stk.push_back(i);
        }
    };
    build();

    long long L = 0, R = 0;
    for (int i = 1; i <= n; i++)
    {
        // cerr << l[i] << " " << r[i] << " \n";
        L ^= 1LL * i * (l[i] + 1);
        R ^= 1LL * i * (r[i] + 1);
    }
    cout << L << " " << R << '\n';
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