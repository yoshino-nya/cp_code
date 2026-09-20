// Date: 2025-04-06
// Time: 01:47:58
#include <bits/stdc++.h>
using namespace std;

int dp[2][25005];

void ChatGptDeepSeek()
{
    int D, G;
    cin >> D >> G;
    vector<int> T(G), F(G), H(G);
    {
        vector<array<int, 3>> tmp(G);
        for (int i = 0; i < G; i++)
            cin >> tmp[i][0] >> tmp[i][1] >> tmp[i][2];
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < G; i++)
            T[i] = tmp[i][0], F[i] = tmp[i][1], H[i] = tmp[i][2];
    }
    // for (int i = 0; i < G; i++)
    //     cin >> T[i] >> F[i] >> H[i];
    dp[1][0] = 10;
    // for (int i = 1; i <= 25000; i++)
    //     dp[1][i] = dp[0][i] = -1;

    for (int i = 0; i < G; i++)
    {
        for (int j = 0; j <= 25000; j++)
        {

            if (dp[(i & 1) ^ 1][j] >= T[i])
            {
                if (j + H[i] >= D)
                {
                    // cerr << j << " " << dp[(i & 1) ^ 1][j] << " \n";
                    cout << T[i] << '\n';
                    return;
                }
                if (j + H[i] <= 25000)
                    dp[(i & 1)][j + H[i]] = max(dp[(i & 1)][j + H[i]], dp[(i & 1) ^ 1][j]);
                dp[(i & 1)][j] = max(dp[(i & 1)][j], dp[(i & 1) ^ 1][j] + F[i]);
                // cerr << i << " " << j << '\n';
            }
        }
        // for (int j = 1; j <= 25000; j++)
        //     dp[(i & 1) ^ 1][j] = -1;
    }
    // 如果不行的话 就一直吃！
    int now = 10;
    for (int i = 0; i < G; i++)
    {
        // cerr << now << " " << T[i] << '\n';
        if (now < T[i])
            break;
        now += F[i];
    }
    cout << now << '\n';
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