// Date: 2025-03-15
// Time: 20:03:40

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0, x = 1; i < s.size(); i++, x ^= 1) {
        if (x) {
            if (s[i] != 'i'){
                ans++;
                x^=1;
            }
        }else{
            if(s[i]!='o'){
                ans++;
                x^=1;
            }
        }
    }
    if((ans+s.size())&1) ans++;
    cout<<ans<<'\n';
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