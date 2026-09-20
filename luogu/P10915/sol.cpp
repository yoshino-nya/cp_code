// Date: 2025-03-28
// Time: 14:49:22
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int n = s.size();
    auto check = [&](int len)
    {
        string t = s.substr(0, len);
        reverse(t.begin(), t.end());
        for (int i = n - 1; i >= n - len; i--)
        {
            if (t.back() == s[i])
                t.pop_back();
            else
                break;
        }

        if (t.empty())
            return true;
        int i = len, m = t.size();
        vector<int> p(m);
        for (int i = 1; i < m; i++)
        {
            int j = i - 1;
            while (j > 0 && t[i] != t[j])
                j = p[j - 1];
            p[i] = j;
            if (t[i] == t[j])
                p[i]++;
        }
        int j = 0;
        while (i < n)
        {
            while (j > 0 && s[i] != t[j])
                j = p[j - 1];
            if (s[i] == t[j])
                i++, j++;
            else
                i++; // 如果不相等 那么j 必然等于0 所以直接看下一个1
            if (j == t.size())
                return true;
        }
        return false;
    };
    int lo = 0, hi = n / 2 + 1;
    while (lo < hi - 1)
    {
        int mid = (lo + hi) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}
void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int ans = solve(s);
    reverse(s.begin(), s.end());
    ans = max(ans, solve(s));
    cout << ans << '\n';
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