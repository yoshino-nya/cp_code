#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e5 + 7;
int n, cnt = INT_MAX;
ll ans, m;
struct node {
    int f, s;
} p[N];

inline int check(int x, int y)
{
    int k = 0;
    for (int i = x; i <= y; i++)
        k = max(k, p[i].s);
    return k;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i].f >> p[i].s;
    int l = 1, r = 1;
    while (r <= n) {
        while (ans < m && r <= n) {
            ans += p[r].f;
            r++;
        }
        while (ans >= m && l <= n) {
            ans -= p[l].f;
            l++;
        }
        cnt = min(cnt, check(l - 1, r - 1));
    }
    cout << cnt;
    return 0;
}