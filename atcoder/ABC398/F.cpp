// Date: 2025-03-24
// Time: 00:59:38
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    /*
    怎么跟KMP结合呢？
    我们实际上是去求最长的回文后缀
    这个东西可以用KMP来求
    ABCD#DCBA
    */
    string t = s;
    int n = s.size();
    // cerr << n << '\n';
    s = s + "#" + s;
    reverse(s.begin(), s.begin() + n);
    vector<int> p(2 * n + 1);
    // cerr<<s<<'\n';
    for (int i = 1; i <= 2 * n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        // cerr<<i<<" "<<j<<" "<<p[j]<<'\n';
        p[i] = j;
        if (s[i] == s[j])
        {
            p[i]++;
            // cerr<<i<<" "<<j<<" "<<p[i]<<'\n';
        }
    }
    // cerr << *max_element(p.begin() + n + 1, p.end()) << '\n';
    n += n - p.back();
    // cerr << n << '\n';
    while (t.size() < n)
        t.push_back('@');
    for (int i = 0; i < n - i - 1; i++)
        if (t[i] != t[n - i - 1])
            t[n - i - 1] = t[i];
    // GVGG#GGVG
    cout << t << '\n';
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