#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = int(1e6) + 1;
struct node{
    int l, r, id;
}Q[N];
int a[N], b[N], pos[N], cnt[N], ans[N], res;
inline void add (int i){
    if(!cnt[a[i]]) res++;
    cnt[a[i]]++;
}
inline void del (int i){
    cnt[a[i]]--;
    if(!cnt[a[i]]) res--;
}
// bool cmp(node x, node y)
// {
//     return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
//     // return pos[x.l] == pos[y.l] ? (pos[x.l] & 1 ? x.r < y.r : x.r > y.r) : pos[x.l] < pos[y.l];
// }
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    // vector<int> a(n + 1), pos(n + 1), cnt(N);
    int siz = sqrt(n);
    for(int i = 1, tot = 0; i <= n; i++){
        cin >> a[i];
        if(!b[a[i]]){
            b[a[i]] = ++tot;
        }
        a[i] = b[a[i]];
        pos[i] = i / siz;
    }
    int q; cin >> q;
    // vector<node> Q(q);
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q, Q + q, [&](node x, node y){
        return pos[x.l] == pos[y.l] ? (pos[x.l] & 1 ? x.r < y.r : x.r > y.r) : pos[x.l] < pos[y.l];
    });
    // sort(Q, Q + q, cmp);
    int L = 1, R = 0;
    // vector<int> ans(q);

    for(int i = 0; i < q; i++){
        while(Q[i].l < L)
            add(--L);
        while(Q[i].l > L)
            del(L++);
        while(Q[i].r < R)
            del(R--);
        while(Q[i].r > R)
            add(++R);
        // for(int j = 1; j <= 5; j++)
        //     cerr << cnt[j] << " \n" [j == 5];
        ans[Q[i].id] = res;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}