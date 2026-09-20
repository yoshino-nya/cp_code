// Date: 2025-02-24
// Time: 20:22:49

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (auto x : s)
        cnt[x - 'A']++;
    int vowels = cnt['A' - 'A'] + cnt['E' - 'A'] + cnt['I' - 'A'] + cnt['O' - 'A'] + cnt['U' - 'A'];
    int consonants = s.size() - vowels;
    if (vowels * 2 > consonants) {
        // cerr << "1\n";
        vowels = consonants / 2;
        int ans = vowels * 3;
        int rest = consonants % 2;
        int x = cnt['N' - 'A'], y = cnt['G' - 'A'];
        if (x > y)
            swap(x, y);
        // 最多只能多加x个
        ans += min({ vowels * 2, x, rest });
        cout << ans << '\n';
    } else {
        // 可能需要用y
        int x = cnt['N' - 'A'], y = cnt['G' - 'A'], z = cnt['Y' - 'A'];
        if (x > y)
            swap(x, y);
        if ((vowels + z) * 3 <= s.size()) {
            // 肯定全拿
            // cerr << "2\n";
            int ans = (vowels + z) * 3;
            int rest = s.size() - ans;
            ans += min({ (vowels + z) * 2, x, rest });
            cout << ans << '\n';
        } else {
            // 否则只能加一部分
            // 直接拿成s.size()/3
            vowels = s.size() / 3;
            if (vowels * 3 == s.size()) {
                // cerr << "3\n";
                cout << s.size() << '\n';
            } else {
                // 否则继续之前的操作
                // cerr << "4\n";
                int ans = vowels * 3;
                int rest = s.size() - ans;
                int x = cnt['N' - 'A'], y = cnt['G' - 'A'];
                if (x > y)
                    swap(x, y);
                // 最多只能多加x个
                ans += min({ vowels * 2, x, rest });
                cout << ans << '\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}