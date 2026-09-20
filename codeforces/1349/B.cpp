// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
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

void ChatGptDeepSeek() // Date: 2025-07-23
{                      // Time: 22:15:14 
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(find(ALL(a), k) == a.end())
    {
        cout << "NO\n";
        return;
    }
    if(n == 1){
        cout << "YES\n";
        return;
    }
    for(int i = 1; i < n; i++){
        if(a[i] >= k && a[i + 1] >= k){
            cout << "YES\n"; return;
        }
        if(i > 1 && a[i - 1] >= k && a[i + 1] >= k){
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
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