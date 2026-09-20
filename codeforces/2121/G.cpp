#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 08:56:42
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> pre(n + 1);
    long long ans = 0;
    for(int i  = 1, c0 = 0, c1 = 0; i <= n; i++){
        if(s[i] == '0') c0++;
        else c1++;
        pre[i] = c0 - c1;
        ans += 1LL * i * (n - i + 1);
    }
    sort(pre.begin(), pre.end());
    for(int i = 0; i <= n; i++){
        ans += 1LL * (i + 1) * pre[i] - 1LL * (n - i + 1) * pre[i];
    }
    cout << ans / 2 << '\n';
}
/*
<think>
0110
1 0 -1 0
1 + 1 + 3  = 5

0110
-1 0 1 0
2 + 3 + 3 = 8, -1
</think>
*/
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