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

void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 22:07:05
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        if (mp.contains(a[i] - 1))
            cmax(mp[a[i]], mp[a[i] - 1]+1);
        else
            mp[a[i]] = 1;
    }
    int len = 0, val = 0;
    for (auto [x, y] : mp)
    {
        // cerr<<x<<" "<<y<<'\n';
        if (y > len)
        {
            len = y;
            val = x;
        }
    }
    vector<int> ans;
    for (int i = n; i >= 1; i--)
    {
        if(a[i]==val){
            ans.push_back(i);
            val--;
        }
    }
    cout<<len<<'\n';
    reverse(all(ans));
    for(auto x:ans)
        cout<<x<<" ";
    cout<<'\n';
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