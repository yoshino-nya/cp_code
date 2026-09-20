#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5) + 55;
constexpr int mod = 998244353;
#define ls p << 1
#define rs (p << 1) | 1
#define mi ((l + r) >> 1)

ll tr[N << 2];
int A[N], tag[N << 2];
ll ksm(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll x){return ksm(x, mod - 2);}
void build(int p, int l, int r)
{
    tag[p] = -1;
    if(l == r){
        tr[p] = A[l];
        return;
    }
    build(ls, l, mi);
    build(rs, mi + 1, r);
    tr[p] = (tr[ls] + tr[rs]) % mod;
}
void push_down(int p, int l, int r)
{
    if(tag[p] != -1){
        tr[ls] = 1LL * (mi - l + 1) * tag[p] % mod;
        tr[rs] = 1LL * (r - mi) * tag[p] % mod;
        tag[ls] = tag[rs] = tag[p];
        tag[p] = -1;
    }
}
void change(int p, int l, int r, int lx, int rx, int x)
{
    if(l >= lx && r <= rx){
        tag[p] = x;
        tr[p] = 1LL * (r - l + 1) * x % mod;
        return;
    }
    push_down(p, l, r);
    if(lx <= mi) change(ls, l, mi, lx, rx, x);
    if(rx > mi) change(rs, mi + 1, r, lx, rx, x);
    tr[p] = (tr[ls] + tr[rs]) % mod;
}
int query(int p, int l, int r, int lx, int rx)
{
    if(l >= lx && r <= rx){
        return tr[p];
    }
    push_down(p, l, r);
    int ans = 0;
    if(lx <= mi) ans += query(ls, l, mi, lx, rx);
    if(rx > mi) ans += query(rs, mi + 1, r, lx, rx);
    return ans % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        int sum = query(1, 1, n, l, r);
        int average = 1LL * sum * inv(r - l + 1) % mod;
        change(1, 1, n, l, r, average);
    }
    for(int i = 1; i <= n; i++){
        cout << query(1, 1, n, i, i) << " \n" [i == n];
    }
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T; while(T--)
    {solve();} return 0;
}