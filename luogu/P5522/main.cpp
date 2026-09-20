#include<bits/stdc++.h>
using namespace std;

struct node{
    int a, b;
};
int n, m, q;
constexpr int N = 100010;
string s[N];
node tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
node merge(const node &x, const node &y)
{
    node res;
    for(int i = 0; i < n; i++){
        res.a = x.a | y.a;
        res.b = x.b | y.b;
    }
    return res;
}
void build(int p, int l, int r)
{
    // cerr << l << " " << r << '\n';
    if(l == r){
        tr[p] = {0, 0};
        for(int i = 0; i < n; i++){
            if(s[l][i] == '0') tr[p].a |= 1 << i;
            else if(s[l][i] == '1') tr[p].b |= 1 << i;
        }
        return;
    }
    build(ls, l, mi), build(rs, mi + 1, r);
    tr[p] = merge(tr[ls], tr[rs]);
}
void change(int p, int l, int r, int index)
{
    if(l == r){
        tr[p] = {0, 0};
        for(int i = 0; i < n; i++){
            if(s[l][i] == '0') tr[p].a |= 1 << i;
            else if(s[l][i] == '1') tr[p].b |= 1 << i;
        }
        return;
    }
    if(index <= mi) change(ls, l, mi, index);
    else change(rs, mi + 1, r, index);
    tr[p] = merge(tr[ls], tr[rs]);
}
node query(int p, int l, int r, int lx, int rx)
{
    // cerr << "query : " << l << " " << r << '\n';
    if(l >= lx && r <= rx) return tr[p];
    node res{0, 0};
    if(lx <= mi) res = merge(res, query(ls, l, mi, lx, rx));
    if(rx > mi) res = merge(res, query(rs, mi + 1, r, lx, rx));
    return res;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
        cin >> s[i];
    build(1, 1, m);
    int ans = 0;
    while(q--){
        int op; cin >> op;
        if(op){
            int pos; string t;
            cin >> pos >> t;
            s[pos] = t;
            change(1, 1, m, pos);
        }else{
            int l, r; cin >> l >> r;
            node res = query(1, 1, m, l, r);
            if(!(res.a & res.b)){
                int x = 1;
                for(int i = 0; i < n; i++){
                    if((res.a >> i & 1) == (res.b >> i & 1))
                        x *= 2;
                }
                ans ^= x;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
只记必须填 0/1 的位置
若 & 不等于 0, 则 no

*/