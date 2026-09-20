// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

int lowbit(int x) { return (x) & (-x); }
void ChatGptDeepSeek() // Date: 2025-04-10
{                      // Time: 20:26:45
    int n, k;
    cin >> n >> k;
    vector<vi> trie(n * 31, vi(2));
    vi p(n * 32);
    int tot = 0, ans = n + 1;
    auto Insert = [&](int Val, int idx)
    {
        int cur = 0;
        for (int i = 30; i >= 0; i--)
        {
            int x = Val >> i & 1;
            if (trie[cur][x] == 0)
                trie[cur][x] = ++tot;
            cur = trie[cur][x];
            p[cur] = idx;
        }
    };
    auto Find = [&](int Val)
    {
        int cur = 0, now = 0, L = -1;
        for (int i = 30; i >= 0; i--)
        {
            int x = Val >> i & 1;
            int y = k >> i & 1;
            if (y)
            {
                if (!trie[cur][x ^ 1])
                    return L;
                cur = trie[cur][x ^ 1];
            }
            else
            {
                if (trie[cur][x ^ 1])
                    cmax(L, p[trie[cur][x ^ 1]]);
                if (trie[cur][x] == 0)
                    return L;
                cur = trie[cur][x];
            }
        }
        cmax(L,p[cur]);
        return L;
    };
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int L=Find(x);
        if(L>0) ans=min(ans,i-L+1);
        Insert(x, i);
    }
    if (k == 0)
        cout << "1\n";
    else if (ans == n + 1)
        cout << "-1\n";
    else
        cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}