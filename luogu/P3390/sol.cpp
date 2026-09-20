// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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

constexpr int mod = int(1e9) + 7;

void ChatGptDeepSeek() // Date: 2025-04-28
{                      // Time: 16:37:41 
    int n;
    ll k;
    cin >> n >> k;
    vector<vl> a(n + 1, vl(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    auto matrix_ksm = [&](){
        vector<vl> res(n + 1, vl(n + 1));
        for(int i = 1; i <= n; i++) res[i][i] = 1;
        while(k){
            if(k&1){
                vector<vl> tmp(n + 1, vl(n + 1));
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        for(int k = 1; k <= n; k++){
                            tmp[i][j] = (tmp[i][j] + res[i][k] * a[k][j] % mod) % mod;
                        }
                    }
                }
                res = tmp;
            }
            {
                vector<vl> tmp(n + 1, vl(n + 1));
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        for(int k = 1; k <= n; k++){
                            tmp[i][j] = (tmp[i][j] + a[i][k] * a[k][j] % mod) % mod;
                        }
                    }
                }
                a = tmp;
            }
            k >>= 1;
        }
        return res;
    };
    vector ans = matrix_ksm();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << ans[i][j] << " \n"[j == n];
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