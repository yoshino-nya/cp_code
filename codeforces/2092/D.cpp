/*
5
TILII
TLITLTLII

AAC
AABC
AACBC
AABCBC

AAAAAABCBBCCCC

*/
// Date: 2025-03-29
// Time: 23:12:50
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> cnt(130);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i]]++;
    }
    vector<int> a(3);
    a[0] = cnt['L'], a[1] = cnt['I'], a[2] = cnt['T'];
    sort(a.begin(), a.end());
    vector<int> ans;
    auto Ins = [&](char ch)
    {
        for (int i = 0; i + 1 < s.size(); i++)
        {

            if (s[i] != s[i + 1] && s[i] != ch && s[i + 1] != ch)
            {
                s.insert(s.begin() + i + 1, ch);
                cnt[ch]++;
                a[0] = cnt['L'], a[1] = cnt['I'], a[2] = cnt['T'];
                sort(a.begin(), a.end());
                ans.push_back(i + 1);
                return true;
            }
        }
        return false;
    };
    // Ins('T');
    // cerr<<s<<'\n';
    while (1)
    {
        // break;
        if (a[0] == a[2])
            break;
        if (cnt['L'] == a[0])
        {
            if (Ins('L'))
                continue;
            else
            {
                if (cnt['I'] == a[1])
                {
                    if (Ins('I'))
                        continue;
                    else if (Ins('T'))
                        continue;
                }
                else
                {
                    if (Ins('T'))
                        continue;
                    else if (Ins('I'))
                        continue;
                }
            }
        }
        else if (cnt['I'] == a[0])
        {
            if (Ins('I'))
                continue;
            else
            {
                if (cnt['L'] == a[1])
                {
                    if (Ins('L'))
                        continue;
                    else if (Ins('T'))
                        continue;
                }
                else
                {
                    if (Ins('T'))
                        continue;
                    else if (Ins('L'))
                        continue;
                }
            }
        }
        else
        { // T
            if (Ins('T'))
                continue;
            else
            {
                if (cnt['L'] == a[1])
                {
                    if (Ins('L'))
                        continue;
                    else if (Ins('I'))
                        continue;
                }
                else
                {
                    if (Ins('I'))
                        continue;
                    else if (Ins('L'))
                        continue;
                }
            }
        }
        cout << "-1\n";
        return;
    }
    // cerr << s << '\n';
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << '\n';
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