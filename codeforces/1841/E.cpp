// 没有太读懂题目。。。
// 没事了
//  Date: 2025-03-20
//  Time: 16:08:24

#include <bits/stdc++.h>
// #include "C:/usr/codes/cp/template/debug.hpp"

using namespace std;
using ll = long long;
// #define int ll

struct seg{
	int l, r;
};
 
bool operator <(const seg &a, const seg &b){
	return a.l < b.l;
}

void ChatGptDeepSeek()
{
    map<seg, int> mp;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    mp[{ 0, n }] = n;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&a](int x, int y) {
        return a[x] > a[y];
    });
    // for (int i = 1; i <= n; i++)
    //     cerr << ord[i] << " \n"[i == n];
    // dbg(ord);
    vector<ll> cnt(n + 2);
    int j = 0;
    for (int i = n; i >= 0; i--) {
        while (j < n && a[ord[j]] >= i) {
            auto it = mp.upper_bound({ ord[j], -1 });
            // cerr << j << '\n';
            --it;
            //    it = prev(it);
            auto tmp = it->first;

            cnt[tmp.r - tmp.l] += it->second - i;
            mp.erase(it);

            if (tmp.l != ord[j])
                mp[{ tmp.l, ord[j] }] = i;
            if (ord[j] + 1 != tmp.r)
                mp[{ ord[j] + 1, tmp.r }] = i;
            // 需要找第一个 l<= ord_j 的位置
            j++;
        }
    }
    // dbg(mp);
    // dbg(cnt);
    ll ans = 0;
    // for (int i = n; i >= 1; i--) {
    //     // dbg(i, cnt[i], m);
    //     if (m >= 1LL * cnt[i] * i) {
    //         m -= 1LL * cnt[i] * i;
    //         ans += 1LL * cnt[i] * (i - 1);
    //     } else {
    //         ans += 1LL * (i - 1) * (m / i);
    //         m %= i;
    //         if (m)
    //             ans += m - 1;
    //         break;
    //     }
    // }
    for (int i = n; i > 0; --i) {
        long long t = min(cnt[i], m / i);
        ans += t * 1ll * (i - 1);
        m -= t * 1ll * i;
        if (t != cnt[i] && m > 0) {
            ans += m - 1;
            m = 0;
        }
    }
    cout << ans << '\n';
}
/*
没事了 题看错了 是第 i 列的前 ai个是黑色。。。



10
*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}