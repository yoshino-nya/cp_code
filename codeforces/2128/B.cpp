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
{                      // Time: 22:43:27 
    int n;
    cin >> n;
    vi p(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    int L = 1, R = n, lst = 0;
    string ans;
    while(L < R){
        if(p[L] > lst && p[R] > lst){
            if(p[L] > p[R])
                ans += "LR";
            else
                ans += "RL";
        }else if(p[L] < lst && p[R] < lst){
            if(p[L] > p[R])
                ans += "RL";
            else
                ans += "LR";
        }else if(p[L] > lst){
            ans += "LR";
        }else if(p[L] < lst){
            ans += "RL";
        }
        if(ans.back() == 'L')
            lst = p[L];
        else
            lst = p[R];
        L++, R--;
    }
    if(ans.size() != n) ans += "L";
    assert(sz(ans) == n);
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