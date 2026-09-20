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

void ChatGptDeepSeek() // Date: 2025-04-10
{                      // Time: 10:31:36
    int n;
    cin >> n;
    vector<vector<int>> trie(n * 51, vector<int>(26, 0));
    vector<bool> word(n * 51), vis(n * 51);
    int tot = 0;
    auto Insert = [&](string s)
    {
        int cur = 0;
        for (auto x : s)
        {
            if (trie[cur][x - 'a'] == 0)
                trie[cur][x - 'a'] = ++tot;
            cur = trie[cur][x - 'a'];
        }
        word[cur] = true;
    };
    auto Find = [&](string s)
    {
        int cur = 0;
        for (auto x : s)
        {
            if (trie[cur][x - 'a'] == 0)
            {
                cout << "WRONG\n";
                return;
            }
            cur = trie[cur][x - 'a'];
        }
        if (vis[cur])
            cout << "REPEAT\n";
        else if (word[cur])
            cout << "OK\n", vis[cur] = true;
        else
            cout << "WRONG\n";
    };
    for (int i = 1; i <= n; i++)
    {
        string x;
        cin >> x;
        Insert(x);
    }
    int m;
    cin >> m;
    while (m--)
    {
        string x;
        cin >> x;
        Find(x);
    }
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