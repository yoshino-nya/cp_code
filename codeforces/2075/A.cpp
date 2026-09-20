// Date: 2025-03-17
// Time: 22:36:14

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (n & 1) {
        n -= k;
        ans++;
    }
    k--;
    if (n)
        ans += (n - 1) / k + 1;
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