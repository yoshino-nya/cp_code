#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-13
{                      // Time: 20:21:07
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int cnt = 0;
    do
    {
        vector<int> v1(n + n + 1), v2(2 * n + 1);
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (v1[i + p[i]] || v2[i - p[i] + n])
            {
                ok = false;
                break;
            }

            v1[i + p[i]]++;
            v2[i - p[i] + n]++;
        }
        if (ok)
        {
            cnt++;
            if(cnt<=3)
                for(int i=1;i<=n;i++)
                    cout<<p[i]<<" \n"[i==n];
        }
    } while (next_permutation(p.begin() + 1, p.end()));
    cout<<cnt<<'\n';
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