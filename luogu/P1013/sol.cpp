// Date: 2025-03-27
// Time: 23:47:40
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<vector<string>> s(n, vector<string>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    vector<int> p(n - 1);
    iota(p.begin(), p.end(), 0);
    auto check = [&]()
    {
        vector<int> q(129);
        for (int i = 0; i < n - 1; i++)
            q[s[0][i + 1][0]] = p[i];
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 1; i < n; i++)
            a[0][i] = p[i - 1];
        for (int i = 1; i < n; i++)
            a[i][0] = p[i - 1];
        auto get = [&](string x)
        {
            int res = 0;
            for (auto y : x)
                res = res * (n - 1) + q[y];
            return res;
        };
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
            {
                // if (i == j && i == 1)
                // {
                //     cerr << p[i - 1] << " " << p[j - 1] << " " << get(s[i][j]) << '\n';
                // }
                if (p[i - 1] + p[j - 1] != get(s[i][j]))
                    return false;
            }
        return true;
    };
    do
    {
        if (check())
        {
            for (int i = 1; i < n; i++)
                cout << s[0][i] << "=" << p[i - 1] << " \n"[i + 1 == n];
            cout << n - 1 << '\n';
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << "ERROR!\n";
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