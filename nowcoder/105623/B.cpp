// Date: 2025-03-30
// Time: 20:31:39
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    auto get = [&](string s)
    {
        int res = 0;
        for (auto x : s)
            res = res * 10 + x - '0';
        return res;
    };
    int ans=0;
    for (int i = 1; i < s.size(); i++)
    {
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, 100);
        ans=max(ans,get(s1)+get(s2));
    }
    cout<<ans<<'\n';
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