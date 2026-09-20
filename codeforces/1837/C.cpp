// Date: 2025-03-25
// Time: 19:15:56
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '?')
        {
            int j = i - 1;
            while (j >= 0)
            {
                s[j] = s[i];
                j--;
            }
            break;
        }
    }
    if (s[0] == '?')
    {
        string t(s.size(), '0');
        cout << t << '\n';
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            s[i] = s[i - 1];
    }
    cout << s << '\n';
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