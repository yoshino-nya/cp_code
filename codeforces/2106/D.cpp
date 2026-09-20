#include <bits/stdc++.h>
using namespace std;

#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
constexpr int N = int(2e5) + 10;
int MIN[N << 2];
int query(int p, int l, int r, int lx, int rx)
{
    if (l >= lx && r <= rx)
        return MIN[p];
    int res = 1000000001;
    if (lx <= mi)
        res = min(res, query(ls, l, mi, lx, rx));
    if (rx > mi)
        res = min(res, query(rs, mi + 1, r, lx, rx));
    return res;
}

void Codeforces()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    auto build = [&](auto&& self, int p, int l, int r) -> void {
        if (l == r) {
            MIN[p] = b[l];
            return;
        }
        self(self, ls, l, mi);
        self(self, rs, mi + 1, r);
        MIN[p] = min(MIN[ls], MIN[rs]);
    };
    build(build, 1, 1, m);
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1, j = 1; i <= n; i++) {
        if (a[i] >= b[j]) {
            j++;
            if (j == m + 1) {
                cout << "0\n";
                return;
            }
        }
        pre[i] = j;
    }
    for (int i = n, j = m; i >= 1; i--) {
        if (a[i] >= b[j]) {
            j--;
            if (j == 0) {
                cout << "0\n";
                return;
            }
        }
        suf[i] = j;
    }
    // for(int i = 1; i <= n; i++)
    //     cerr << pre[i] << " \n" [i == n];
    // for(int i = 1; i <= n; i++)
    //     cerr << suf[i] << " \n" [i == n];
    suf[n + 1] = m, pre[0] = 1;
    int ans = 1000000001;
    for (int i = 0; i <= n; i++) {
        if (pre[i] >= suf[i + 1]) {
            // ans = min(ans, b[suf[i]]);
            // ans = min(ans, b[pre[i]]);
            // cerr << pre[i] << " " << suf[i + 1] <<'\n';
            ans = min(ans, query(1, 1, m, suf[i + 1], pre[i]));
        }
    }
    if (ans == 1000000001)
        ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        Codeforces();
}