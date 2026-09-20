// Date: 2025-03-22
// Time: 22:36:43
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(25 + 1);
    for (auto c : s)
        cnt[c - 'a']++;
    if (*max_element(cnt.begin(), cnt.end()) == n)
    {
        cout << "NO\n";
    }
    else
    {
        string t = s;
        reverse(t.begin(), t.end());
        if (k)
            cout << "YES\n";
        else if (s < t)
            cout << "YES\n";
        else
            cout << "No\n";
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