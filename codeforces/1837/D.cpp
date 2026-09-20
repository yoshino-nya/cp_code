// Date: 2025-03-25
// Time: 19:26:39
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, color = 0;
    char lst = s[0];
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt > 0 && lst != '(')
            color ^= 1, lst = '(';
        else if (cnt < 0 && lst != ')')
            color ^= 1, lst = ')';
        ans.push_back(1 + color);
    }
    if (cnt != 0)
    {
        cout << "-1\n";
        return;
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (auto x : ans)
        cout << x << " ";
    cout << '\n';
    /*
     */
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