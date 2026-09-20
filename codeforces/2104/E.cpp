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

// Date: 2025-05-29
// Time: 10:50:06
void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vc<vi> pre(n + 1, vi(k));
    vc<vi> nxt(n + 1, vi(k));
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        pre[i][s[i] - 'a']++;
    }
    vi lst(k, n + 1);
    for(int i = n; i >= 1; i--){
        nxt[i] = lst;
        lst[s[i] - 'a'] = i;
    }
    nxt[0] = lst;
    vi ans(n + 1, n + 1);
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < k; j++){
            if(nxt[i][j] > n)
                ans[i] = 1;
            else
                cmin(ans[i], ans[nxt[i][j]] + 1);
        }
    }
    auto ask = [&](){
        string t;
        cin >> t;
        int j = 0;
        for(int i = 0; i < sz(t); i++){
            j = nxt[j][t[i] - 'a'];
            if(j > n){
                cout << "0\n";
                return;
            }
        }
        cout << ans[j] << '\n';
    };
    int q; cin >> q;
    while(q--){
        ask();
    }
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