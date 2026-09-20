// Date: 2025-03-26
// Time: 20:37:35
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m, k;
    cin >> n >> m >> k;
    int lo = 0, hi = m + 1;
    auto check = [&](int len)
    {
        int num = (m + 1) / (len + 1) * len;
        int rest = (m + 1) % (len + 1);

        return 1LL * (num + max(0, rest - 1)) * n >= k;
    };
    while (lo < hi - 1)
    {
        int mid = (lo + hi) >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
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