#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-26
{                      // Time: 16:04:12 
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans = s[0] + s.substr(k, n);
    if(s[0] < s[k - 1]){
        cout << s[k - 1] << '\n';
        return;
    }
    vector<string> res(k);
    for(int i = 0, p = 0; i < n; i++){
        if(i % k == 0) p ^= 1;
        if(p)
            res[i % k] += s[i];
        else
            res[k - 1 - (i % k)] += s[i];
    }
    ans = min(ans, *max_element(res.begin(), res.end()));
    cout << ans << '\n';
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