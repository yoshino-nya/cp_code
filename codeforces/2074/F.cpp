// Date: 2025-03-25
// Time: 16:02:27
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long ans = 1ll * (r1 - l1) * (r2 - l2);
    for (int i = 1; i < 30; i++)
    {
        int s = 1 << i;
        int L1 = (l1 + s - 1) / s * s;
        int L2 = (l2 + s - 1) / s * s;
        int R1 = r1 / s * s;
        int R2 = r2 / s * s;
        if (L1 >= R1 || L2 >= R2)
            continue;
        ans -= 3LL * (R1 - L1) / s * (R2 - L2) / s;
    }
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