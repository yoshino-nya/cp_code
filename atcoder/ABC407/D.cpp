// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-24
// Time: 20:25:23
void ChatGptDeepSeek()
{
    int h, w;
    cin >> h >> w;
    vc<vl> A(h, vl(w));
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> A[i][j];
    int all = h * w;
    vi p;
    for(int i = 0; i < (1 << all); i++){
        if(__builtin_popcount(i) % 2 == 0)
            p.push_back(i);
    }
    auto check = [&](auto &&self, int x){
        if(x == 0) return true;
        bool res = false;
        for(int i = 0; i < all; i++){
            if(x >> i & 1){
                int r = i / w, c = i % w; // 这里是 1，
                if(c != w - 1){
                    if(x >> (i + 1) & 1){
                        res |= self(self, x ^ (1 << i) ^ (1 << (i + 1)));
                    }
                }
                if(r != h - 1){
                    if(x >> (i + w) & 1){
                        res |= self(self, x ^ (1 << i) ^ (1 << (i + w)));
                    }
                }
                break;
            }
        }
        return res;
    };
    ll ans = 0;
    for(auto now : p){
        if(check(check, now)){
            ll res = 0;
            // int cnt = 0;
            for(int i = 0; i < all; i++){
                if(now >> i & 1){
                    // cnt++;
                    continue;
                }
                // cerr << i << '\n';
                res ^= A[i / w][i % w];
            }
            // assert(cnt % 2 == 0);
            // if(res == 131071){
            //     for(int i = 0; i < all; i++){
            //         cout << (now >> i & 1) << " ";
            //         if(i % w == w - 1) cout << '\n';
            //     }
            // }
            cmax(ans, res);
        }
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}