#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200005;
int a[N], b[N];
int cnt[N], pos[N];
// array<int, N> cnt, pos;
set<int> ans[N];
mt19937 rng(time(NULL));
int rnd(int l, int r){
    uniform_int_distribution<int> dis(l, r);
    return dis(rng);
}
struct node{
    int l, r, idx;
};
node Q[N];
void solve()
{
    int n, q; cin >> n >> q;
    int siz = sqrt(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        pos[i] = i / siz;
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
        // cerr << a[i] << " \n" [i == n];
    }
    for(int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }
    sort(Q, Q + q, [&](const node &x, const node &y){
        return pos[x.l] == pos[y.l] ? ((pos[x.l] & 1) ? 
        pos[x.r] < pos[y.r] : pos[x.r] > pos[y.r]) : pos[x.l] < pos[y.l];
        // return pos[x.l] == pos[y.l] ? pos[x.r] < pos[y.r] : pos[x.l] < pos[y.l];
    });
    int L = 1, R = 0;
    auto del = [&](int i){
        // assert(i)
        --cnt[a[i]];
    };
    auto add = [&](int i){
        ++cnt[a[i]];
    };
    for(int i = 0; i < q; i++){
        auto [l, r, idx] = Q[i];
        while(L < l) del(L++);
        while(L > l) add(--L);
        while(R > r) del(R--);
        while(R < r) add(++R);
        set<int> st;
        for(int _ = 1; _ <= 35 && st.size() < 2; _++){
            int index = rnd(l, r);
            // cerr << index << " " << cnt[index] << '\n';
            if(cnt[a[index]] > (r - l + 1) / 3) st.insert(b[a[index]]);
        }
        // cerr << '\n';
        if(st.size()){
            ans[idx] = st;
        }
    }

    for(int i = 0; i < q; i++){
        if(ans[i].empty()) cout << "-1\n";
        else{
            for(auto x : ans[i])
                cout << x << " ";
            cout << '\n';
        }
        ans[i].clear();
    }
    for(int i = 1; i <= n; i++){
        cnt[a[i]] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}