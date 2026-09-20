// Date: 2025-04-01
// Time: 18:10:44
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int m, s, t;
    cin >> m >> s >> t;
    // 水题 枚举用了多少次魔法就行

    vector<int> d(t + 1), T(t + 1), r(t + 1), ned(t + 1);
    r[0] = m;               // 用 i 次魔法后 剩余的魔法
    T[0] = 0;               // 用 i 次魔法 恢复需要的时间
    ned[0] = (s + 16) / 17; // 用 i 次魔法 走到终点需要的时间

    d[0] = (t + 16) / 17 * 17; // 用 i 次魔法 t时间走的距离
    for (int i = 1; i <= t; i++)
    {
        T[i] = T[i - 1];
        r[i] = r[i - 1];
        if (r[i - 1] < 10)
        {
            T[i] += (10 - r[i - 1] + 3) / 4;
            r[i] = r[i] + (T[i] - T[i - 1]) * 4 - 10;
        }
        else
            r[i] -= 10;
        // 剩下 t-T[i]的时间 看能走多少
        ned[i] = T[i] + i;
        if (ned[i] > t)
            break;
        d[i] = i * 60 + (t - ned[i]) * 17;

        if (s >= i * 60)
        {
            ned[i] += (s - i * 60 + 16) / 17;
        }
        // cerr << i << " " << r[i] << " " << T[i] << " " << ned[i] << " \n";
    }
    int time = t + 1;
    for (int i = 0; i <= t; i++)
    {
        if (d[i] >= s && ned[i] <= t)
        {
            // cerr << i << " " << ned[i] << " \n";
            time = min(time, ned[i]);
        }
    }
    if (time != t + 1)
        cout << "Yes\n"
             << time << '\n';
    else
        cout << "No\n"
             << *max_element(d.begin(), d.end()) << '\n';
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