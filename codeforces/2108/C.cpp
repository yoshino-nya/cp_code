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

// Date: 2025-05-01
// Time: 23:35:57
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int now = a[1], cnt = 0;
    vc<array<int, 3>> info;
    for(int i = 1; i <= n; i++){
        if(a[i] == now)
            cnt++;
        else{
            info.push_back({now, i - cnt, i - 1});
            now = a[i], cnt = 1;
        }
    }
    info.push_back({now, n - cnt + 1, n});
    sort(all(info), greater<>());
    vc<bool> vis(n + 1);
    int ans = 0;
    for(auto [val, l ,r] : info){
        // cerr << val << " " << l << " " << r <<'\n';
        if(l && vis[l - 1]){
            vis[r] = true;
        }else if(r < n && vis[r + 1]){
            vis[l] = true;
        }else{
            vis[l] = vis[r] = true;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}