// Date: 2025-03-14
// Time: 08:08:23

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        int j = i + 1;
        string t(1, s[i]);
        while (j < s.size() && s[j] != s[j - 1]) {
            t += s[j];
            j++;
        }
        i = j - 1;
        if (t.size() > 1)
            v.push_back(t);
    }
    sort(v.begin(), v.end(), [](string x, string y) {
        if ((x.size() ^ y.size() ^ 1) & 1)
            return x.size() < y.size();
        // if(x.size()==y.size())
        //     return x<y;
        return x.size() % 2 < y.size() % 2;
    });
    int A = count(s.begin(), s.end(), 'A'), B = s.size() - A;
    for (auto x : v) {
        // cerr<<x<<" \n";
        int len = x.size();
        if (x.size() & 1) {
            // 奇数用谁都一样的
            while (ab && len > 1) {
                A--, B--;
                ab--;
                len -= 2;
            }
            while (ba && len > 1) {
                A--, B--;
                ba--;
                len -= 2;
            }
        } else {
            if (x.front() == 'A') {
                if (ab >= len / 2) {
                    ab -= len / 2;
                    A -= len / 2, B -= len / 2;
                    len = 0;
                    // cerr<<ab<<'\n';
                } else {
                    len -= 2 * ab;
                    A -= ab, B -= ab;
                    ab = 0;
                }
                if (len) {
                    if (ba >= (len - 2) / 2) {
                        ba -= (len - 2) / 2;
                        A -= (len - 2) / 2, B -= (len - 2) / 2;
                    } else {
                        A -= ba, B -= ba, ba = 0;
                    }
                }
            } else {
                if (ba >= len / 2) {
                    ba -= len / 2;
                    A -= len / 2, B -= len / 2;
                    len = 0;
                } else {
                    len -= 2 * ba;
                    A -= ba, B -= ba;
                    ba = 0;
                }
                if (len) {
                    if (ab >= (len - 2) / 2) {
                        ab -= (len - 2) / 2;
                        A -= (len - 2) / 2, B -= (len - 2) / 2;
                    } else {
                        A -= ab, B -= ab, ab = 0;
                    }
                }
            }
        }
    }
    // cerr<<ab<<" "<<ba<<'\n';
    assert(A >= 0 && B >= 0);
    if (A <= a && B <= b)
        cout << "YES\n";
    else
        cout << "NO\n";
}

// ABABBAABBAAB
// ABA BAB?
// ABABBAABBA
// ABABBAAB
// ABABBA
// ABAB BABA

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