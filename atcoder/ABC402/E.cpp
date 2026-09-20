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

void ChatGptDeepSeek() // Date: 2025-04-20
{                      // Time: 14:46:23
    int n, X;
    cin >> n >> X;
    vi s(n + 1), c(n + 1);
    vector<double> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> c[i] >> p[i], p[i] /= 100;
    vector<vector<double>> dp(1 << n, vector<double>(X + 1));
    for (int j = 0; j < (1 << n); j++)
    {
        for (int k = 0; k <= X; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (k < c[i])
                    continue;
                if (j >> (i - 1) & 1)
                {
                    int last = j ^ (1 << (i - 1));
                    dp[j][k] = max(dp[j][k], (dp[last][k - c[i]] + s[i]) * p[i] + max(dp[j][k - c[i]], dp[last][k - c[i]]) * (1 - p[i]));
                }
            }
        }
    }
    cout << fixset(16) << dp[(1 << n) - 1][X] << '\n';
}
/*
n个问题
第i个问题的分是si 每次提交的cost是ci 每次提交正确的概率是 pi
求最大的得分的期望
*/

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    // cout<<fixset(10);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}