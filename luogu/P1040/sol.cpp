// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1 &x, const T2 &y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1 &x, const T2 &y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 10:13:41
    int n;
    cin >> n;
    vector<int> d(n + 1);

    vector<vi> dp(n + 1, vi(n + 1, 1));
    vector<vi> root(n + 1, vi(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> d[i], dp[i][i] = d[i], root[i][i] = i;
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;

            for (int k = l; k < r; k++)
            {
                if (dp[l][r] < dp[l][k - 1] * dp[k + 1][r] + dp[k][k])
                {
                    dp[l][r] = dp[l][k - 1] * dp[k + 1][r] + dp[k][k];
                    root[l][r] = k;
                }
            }
        }
    }
    auto Print = [&](auto &&self, int l, int r) -> void
    {
        if (l > r)
            return;
        cout << root[l][r] << ' ';
        if (l == r)
            return;
        self(self, l, root[l][r] - 1);
        self(self, root[l][r] + 1, r);
    };
    cout << dp[1][n] << '\n';
    Print(Print, 1, n);
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}