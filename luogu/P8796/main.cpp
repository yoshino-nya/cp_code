#include <bits/stdc++.h>
using namespace std;

struct node{
    vector<int> lazy;
    node(){
        lazy.assign(26, {});
        for(int i = 0; i < 26; i++)
            lazy[i] = i;
    }
};
constexpr int N = 100005;
node seg[N << 2];
string s;
void push_down(int p){
    for(int i = 0; i < 26; i++){
        seg[p << 1].lazy[i] = seg[p].lazy[seg[p << 1].lazy[i]];
        seg[p << 1 | 1].lazy[i] = seg[p].lazy[seg[p << 1 | 1].lazy[i]];
    }
    for(int i = 0; i < 26; i++)
        seg[p].lazy[i] = i;
}
void change(int p, int l, int r, int lx, int rx, array<int, 2> op){
    if(l >= lx && r <= rx){
        for(int i = 0; i < 26; i++)
            if(seg[p].lazy[i] == op[0])
                seg[p].lazy[i] = op[1];
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if(lx <= mid) change(p << 1, l, mid, lx, rx, op);
    if(rx > mid) change(p << 1 | 1, mid + 1, r, lx, rx, op);
}
int query(int p, int l, int r, int i){
    if(l == r){
        return seg[p].lazy[s[l] - 'a'];
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if(i <= mid) return query(p << 1, l, mid, i);
    return query(p << 1 | 1, mid + 1, r, i);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> s;
    int n = s.size();
    s = " " + s;
    int q; cin >> q;
    while(q--){
        int l, r;
        char x, y;
        cin >> l >> r >> x >> y;
        array<int, 2> op{x - 'a', y - 'a'};
        change(1, 1, n, l, r, op);
    }
    for(int i = 1; i <= n; i++){
        cout << char(query(1, 1, n, i) + 'a');
    }
    cout << "\n";
    return 0;
}