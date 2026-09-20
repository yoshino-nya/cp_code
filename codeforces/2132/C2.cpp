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

int a[33];
void ChatGptDeepSeek() // Date: 2025-08-21
{                      // Time: 22:55:14 
    int n, k; cin >> n >> k;
    ll cost = 0;
    auto get = [&](int i){
        if(i == 0) return 3LL;
        return 1LL * a[i + 1] + 1LL * i * a[i - 1];
    };
    vector<ll> cnt(20);
    ll sum = 0;
    while(n){
        for(int i = 19; i >= 0; i--){
            if(a[i] <= n){
                n -= a[i];
                cnt[i]++;
                sum++;
                break;
            }
        }
    }
    if(sum > k){
        cout << "-1\n";
        return;
    }
    for(int i = 19; i >= 1 && sum <= k; i--){
        if(cnt[i]){
            int x = k - sum;
            if(x >= cnt[i] * 2){
                cnt[i - 1] += cnt[i] * 3;
                sum += 2 * cnt[i];
                cnt[i] = 0;
            }else{
                cnt[i - 1] += x / 2 * 3;
                cnt[i] -= x / 2;
                break;
            }
        }
    }
    for(int i = 0; i <= 19; i++){
        if(cnt[i])
            cost += get(i) * cnt[i];
    }
    cout << cost << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    a[0] = 1;
    for(int i = 1; i <= 19; i++){
        a[i] = a[i - 1] * 3;
        // cerr << a[i] << " \n" [i == 20];
    }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}