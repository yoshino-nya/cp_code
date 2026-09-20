#include <bits/stdc++.h>
using namespace std;

void man()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = k / 2 + 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = k - min(k, n - i + 1) + 1; j <= min(i, k) && j / 2 <= ans; j++)
        {
            // if(i==3) cerr<<j<<'\n';
            if (j & 1)
            {
                if (n == k)
                    continue;
                // cerr << j << " " << a[i] << '\n';
                if (j != 1 && a[i] != a[i - 1] + 1)
                {
                    ans = min(ans, j / 2 + 1);
                }
                continue;
            }
            // cerr << j << " " << a[i] << " \n";
            if (a[i] != j / 2)
            {
                // cout << j / 2 + 1 << '\n';
                ans = min(ans, j / 2);
                // return;
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        man();
    return 0;
}