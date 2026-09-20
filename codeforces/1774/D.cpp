// Author: Zhangwuji
// Date: 2025-01-06
// Time: 13:46:56

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

void solve()
{
    /*
    一个数量大于x的一定可以和一个小于x的进行交换

    */
    int n, m;
    cin >> n >> m;
    vector<vi> a(n + 1, vi(m + 1));
    vi cnt(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            cnt[i] += a[i][j];
            sum += a[i][j];
        }
    if (sum % n) {
        cout << "-1\n";
        return;
    }
    sum /= n;
    vector<set<int>> st(m + 1); // 记录这一列有0 且总数小于平均值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0 && cnt[i] < sum)
                st[j].insert(i);
        }
    }
    // cerr << sum << "\n";
    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] <= sum)
            continue;
        for (int j = 1; j <= m && cnt[i] > sum; j++) {
            if (a[i][j]) {
                while (!st[j].empty() && cnt[*st[j].begin()] == sum)
                    st[j].erase(st[j].begin());
                if (!st[j].empty()) {
                    // swap(a[i][j], a[*st[j].begin()][j]);
                    ans.push_back({ i, *st[j].begin(), j });
                    cnt[*st[j].begin()]++;
                    st[j].erase(st[j].begin());
                    cnt[i]--;
                }
            }
        }
        // assert(cnt[i] == sum);
    }
    // dbg(a);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=n;j++)
    //         cerr<<a[i][j]<<" \n"[j==n];
    cout << sz(ans) << '\n';
    for (auto [i, j, k] : ans)
        cout << i << " " << j << " " << k << '\n';
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
        solve();
    return 0;
}