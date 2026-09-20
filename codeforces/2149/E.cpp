#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// constexpr int N = 200005;
// int b[N];
// int lowbit(int x){
//     return (x) & (-x);
// }
// void add(int i, int x){
//     while(i && i < N){
//         b[i] += x;
//         i += lowbit(i);
//     }
// }
// int query(int i){
//     int res = 0;
//     while(i){
//         res += b[i];
//         i -= lowbit(i);
//     }
//     return res;
// }
void solve()
{
    int n, k, l, r; cin >> n >> k >> l >> r;
    vector<int> a(n + 1), lst(n + 1), cnt(n + 1);
    {
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> b(a);
        sort(b.begin(), b.end());
        for(int i = 1; i <= n; i++)
            a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
    }
    int now = 0, L = 1;
    LL ans = 0;
    set<int> st;
    for(int i = 1, j = 1; i <= n; i++){
        if(++cnt[a[i]] == 1) now++;
        if(now > k){
            while(now > k){
                if(--cnt[a[j]] == 0){
                    now--;
                    st.erase(j);
                    lst[a[j]] = 0;
                }
                j++;
            }
            L = j;
        }
        if(lst[a[i]]) st.erase(lst[a[i]]);
        st.insert(i);
        lst[a[i]] = i;
        if(st.size() < k) continue;
        assert(st.size() == k);
        int R = *st.begin();
        // cerr << format("i : {}, l : {}, r : {}\n", i, L, R);
        int ll = i - r + 1, rr = i - l + 1;
        rr = min(rr, R), ll = max(ll, L);
        if(rr < ll) continue;
        ans += rr - ll + 1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}