// Date: 2025-03-25
// Time: 17:44:37
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    constexpr int mod = 1e9 + 7;
    int m, n;
    cin >> m >> n;
    /*
    1 0 1
    0 1 1

    第一天 1->1 1->2 1->3 (S,L)
    第二天
    d[1]=1 d[2]=1 d[3]=2

    S=3 L=3
    */
    vector<int> s(m + 1), l(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i];
    ll S = s[1], L = l[1];
    vector<ll> ways(m + 1);
    for (int i = 1; i <= n; i++)
    {
        ll nS = 0, nL = 0;
        for (int j = 1; j <= m; j++)
        {
            ways[j] = (1LL * s[j] * (S + L) % mod + 1LL * l[j] * S % mod) % mod;
            nS = (nS + 1LL * ways[j] * s[j] % mod) % mod;
            nL = (nL + 1LL * ways[j] * l[j] % mod) % mod;
            // cerr << ways[j] << " \n"[j == m];
        }
        S = nS, L = nL;
        // cerr << S << " " << L << '\n';
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + ways[i]) % mod;
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