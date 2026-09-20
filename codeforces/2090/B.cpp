// Date: 2025-03-23
// Time: 13:46:57
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (s[i][j] != '0')
            {
                int ok = 0, cnt = 0;
                for (int k = 0; k < i; k++)
                {
                    if (s[k][j] != '0')
                        cnt++;
                }
                ok |= (cnt == i);
                cnt = 0;
                for (int k = 0; k < j; k++)
                {
                    if (s[i][k] != '0')
                        cnt++;
                }
                ok |= (cnt == j);
                if (!ok)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    cout << "YES\n";
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
/*
001
100
100
*/