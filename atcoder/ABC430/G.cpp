#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 300005;
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
struct segtree{
    int tr[N << 2], lazy[N << 2];
    void push_down(int p, int l, int r){
        if(lazy[p]){
            tr[ls] = lazy[p] == 1 ? (mi - l + 1) : 0;
            tr[rs] = lazy[p] == 1 ? (r - mi) : 0;
            lazy[ls] = lazy[rs] = lazy[p];
            lazy[p] = 0;            
        }
    }
    void add(int p, int l, int r, int lx, int rx, int x){
        if(l >= lx && r <= rx){
            tr[p] = x == 1 ? (r - l + 1) : 0;
            lazy[p] = x;
            return;
        }
        push_down(p, l, r);
        if(lx <= mi) add(ls, l, mi, lx, rx, x);
        if(rx > mi) add(rs, mi + 1, r, lx, rx, x);
        tr[p] = tr[ls] + tr[rs];
    }
    int query(int p, int l, int r, int lx, int rx){
        if(l >= lx && r <= rx) return tr[p];
        push_down(p, l, r);
        int res = 0;
        if(lx <= mi) res += query(ls, l, mi, lx, rx);
        if(rx > mi) res += query(rs, mi + 1, r, lx, rx);
        return res;
    }
}seg[63];
struct segtree1{
    LL tr[N << 2], lazy1[N << 2], lazy2[N << 2];
    void push_down(int p, int l, int r){
        if(lazy1[p]){
            lazy1[ls] |= lazy1[p];
            lazy1[rs] |= lazy1[p];
            tr[ls] |= lazy1[p];
            tr[rs] |= lazy1[p];
            lazy1[p] = 0;
        }
        if(lazy2[p]){
            lazy2[ls] &= lazy2[p];
            lazy2[rs] &= lazy2[p];
            tr[ls] &= lazy2[p];
            tr[rs] &= lazy2[p];
            lazy2[p] = 0;
        }
    }
    void add(int p, int l, int r, int lx, int rx, int x){
        if(l >= lx && r <= rx){
            tr[p] |= 1LL << x;
            lazy1[p] |= 1LL << x;
            lazy2[p] |= 1LL << x;
            return;
        }
        push_down(p, l, r);
        if(lx <= mi) add(ls, l, mi, lx, rx, x);
        if(rx > mi) add(rs, mi + 1, r, lx, rx, x);
        tr[p] = tr[ls] | tr[rs];
    }
    void rmv(int p, int l, int r, int lx, int rx, int x){
        if(l >= lx && r <= rx){
            tr[p] &= 1LL << x;
            lazy2[p] &= 1LL << x;
            lazy1[p] &= 1LL << x;
            return;
        }
        push_down(p, l, r);
        if(lx <= mi) add(ls, l, mi, lx, rx, x);
        if(rx > mi) add(rs, mi + 1, r, lx, rx, x);
        tr[p] = tr[ls] | tr[rs];
    }
    LL query(int p, int l, int r, int lx, int rx){
        if(l >= lx && r <= rx) return tr[p];
        push_down(p, l, r);
        LL res = 0;
        if(lx <= mi) res |= query(ls, l, mi, lx, rx);
        if(rx > mi) res |= query(rs, mi + 1, r, lx, rx);
        return res;
    }
}st;
void solve()
{
    int n, q;
    cin >> n >> q;
    int op, l, r, x;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            x--;
            st.add(1, 1, n, l, r, x);
            seg[x].add(1, 1, n, l, r, 1);
        }else if(op == 2){
            cin >> l >> r >> x;
            x--;
            st.rmv(1, 1, n, l, r, x);
            seg[x].add(1, 1, n, l, r, -1);
        }else{
            cin >> l >> r;
            LL val = st.query(1, 1, n, l, r);
            if(!val){
                cout << "0 0\n";
                continue;
            }
            val = __lg(val);
            cout << val + 1 << " " << seg[val].query(1, 1, n, l, r) << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}