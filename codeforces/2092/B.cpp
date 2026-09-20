// Date: 2025-03-29
// Time: 22:42:08
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {
            if (i % 2 == 0)
                cnt1++;
            else
                cnt2++;
        }
        if (s2[i] == '1')
        {
            if (i % 2 == 0)
                cnt2++;
            else
                cnt1++;
        }
    }
    int x = n / 2;
    if (cnt1 > x || cnt2 > n - x)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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