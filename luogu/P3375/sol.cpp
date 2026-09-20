// Date: 2025-03-28
// Time: 10:32:02
#include <bits/stdc++.h>
using namespace std;

vector<int> get_next(string s)
{
    vector<int> nxt(s.size());
    for (int i = 1; i < s.size(); i++)
    {
        int j = nxt[i - 1];
        while (j > 0 && s[j] != s[i])
            j = nxt[j - 1];
        nxt[i] = j;
        // cerr << i << " " << j << " " << nxt[j] << '\n';
        if (s[i] == s[j])
            nxt[i]++;
    }
    return nxt;
}
void ChatGptDeepSeek()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> p = get_next(s2);
    // for (auto x : p)
    //     cerr << x << " ";
    // cerr << '\n';
    int i = 0, j = 0;
    while (i < s1.size())
    {
        // cerr << i << " " << j << '\n';
        while (j > 0 && s1[i] != s2[j])
            j = p[j - 1];
        if (s1[i] == s2[j])
            i++, j++;
        else
            i++;
        if (j == s2.size())
        {
            cout << i - j + 1 << '\n';
            j = p[j - 1];
        }
    }
    // p = get_next(s2);
    for (auto x : p)
        cout << x << " ";
    cout << '\n';
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