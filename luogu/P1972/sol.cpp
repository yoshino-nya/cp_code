#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(1e6) + 1;
struct node{
    int l, r, id;
}Q[N];
int a[N], lst[N], b[N], ans[N];
inline int lowbit(int x){return (x) & (-x);}
inline void add(int i, int x)
{
    while(i < N){
        b[i] += x;
        i += lowbit(i);
    }
}
inline int query(int i)
{
    int res = 0;
    while(i){
        res += b[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q, Q + q, [&](node x, node y){
        return x.r < y.r;
    });
    for(int i = 1, j = 0; i <= n; i++){
        if(lst[a[i]])
            add(lst[a[i]], - 1);
        lst[a[i]] = i;
        add(lst[a[i]], 1);
        while(j < q && Q[j].r == i){
            ans[Q[j].id] = query(i) - query(Q[j].l - 1);
            j++;
        }
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}