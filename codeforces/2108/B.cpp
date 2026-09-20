// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for (int i = 1; i <= N; i++)

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

// Date: 2025-05-01
// Time: 22:56:16
void ChatGptDeepSeek()
{
    int n, x;
    cin >> n >> x;
    int cnt = 0, tmp = x;
    while (tmp) {
        cnt += tmp & 1;
        tmp >>= 1;
    }
    // cout <<cnt <<'\n';

    if (x == 0) {
        if (n == 1)
            cout << "-1\n";
        else{
            if(n % 2 == 0) cout << n << '\n';
            else{// 1 1 1 1, 2, 3
                cout << n + 3 <<'\n';
            }
        }
        return;
    }
    if (cnt < n) {
        if ((n - cnt) & 1) {
            if (cnt == 1) {
                // 1 2 3, 
                if(x == 1){
                    //2 3， 其他全取1
                    cout << 3 + n <<'\n';
                }else{
                    //x+1 1
                    cout << n + x << '\n';
                }
            }// 8, 9 ^ 1
            else{
                cout << x + n - cnt + 1 << '\n';
            }
        }else {
            cout << x + n - cnt << '\n';
        }
    }else{
        cout << x <<'\n';
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}