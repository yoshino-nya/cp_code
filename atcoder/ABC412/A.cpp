#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 20:00:38 
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(y > x) ans++;
    }
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