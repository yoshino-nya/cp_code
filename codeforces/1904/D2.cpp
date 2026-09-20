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

// Date: 2025-05-13
// Time: 14:42:04
struct ST{
    vector<vector<int>> MIN;
    vector<vector<int>> MAX;
    ST(vector<int> &a, vector<int> &b){
        int n = a.size();
        // MIN = MAX = vector<vector<int>> (n, vector<int> (__lg(n) + 1));
        MIN.assign(n, vi(__lg(n) + 1));
        MAX.assign(n, vi(__lg(n) + 1));
        n--;
        for(int i = 1; i <= n; i++)
            MAX[i][0] = a[i], MIN[i][0] = b[i];
        for(int k = 1; (1 << k) <= n; k++){
            for(int s = 1; s + (1 << k) <= n + 1; s++){
                MIN[s][k] = min(MIN[s][k - 1], MIN[s + (1 << (k - 1))][k - 1]);
                MAX[s][k] = max(MAX[s][k - 1], MAX[s + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int queryMin(int l, int r){
        int k = __lg(r - l + 1);
        return min(MIN[l][k], MIN[r - (1 << k) + 1][k]);
    }
    int queryMax(int l, int r){
        int k = __lg(r - l + 1);
        return max(MAX[l][k], MAX[r - (1 << k) + 1][k]);
    }
};

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    /*
    <think>
        向左找 X:
            X 必须是 a[j, i] 之间的最大值， 小于等于 b[j, i] 之间的最小值
        向右同理

        有没有其他限制呢？
        不满足这个条件，一定不行
        满足这个条件，一定可以吗？
    </think>
    */
    vc<bool> ok(n + 1);
    ST st(a, b);
    vi l(n + 1), r(n + 1);
    for(int i = 1; i <= n; i++){
        l[a[i]] = i;
        if(l[b[i]]){
            // cerr << format("[l, i] : {} {}, MAX: {}, MIN: {}\n", l[b[i]], i, st.queryMax(l[b[i]], i), st.queryMin(l[b[i]], i));
            if(st.queryMax(l[b[i]], i) == b[i] && st.queryMin(l[b[i]], i) == b[i])
                ok[i] = true;
        }
    }
    for(int i = n; i >= 1; i--){
        r[a[i]] = i;
        if(r[b[i]]){
            if(st.queryMax(i, r[b[i]]) == b[i] && st.queryMin(i, r[b[i]]) == b[i])
                ok[i] = true;
        }
        if(!ok[i]){
            // cout << i << '\n';
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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