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

void ChatGptDeepSeek() // Date: 2025-07-27
{                      // Time: 22:55:56 
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    /*
    最大的方式就是
    x / 2, 
    如果前面有比 x / 2 还小的数字，百分百不行
    否则一定可以
    */
    int min_val = a[1];
    for(int i = 2; i <= n; i++){
        int x = a[i] / 2 + 1;

        if(min_val < x){
            cout << "NO\n";
            return;
        }
        cmin(min_val, a[i]);    
    }
    cout << "YES\n";
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