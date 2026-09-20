#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
    int mx, lazy;
    node(){mx = lazy = 0;}
};
constexpr int N = 300005;
node seg[N << 2];
void build(int p, int l, int r){
    seg[p].mx = seg[p].lazy = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}
void push_down(int p){
    if(seg[p].lazy){
    	seg[p << 1].mx += seg[p].lazy;
    	seg[p << 1 | 1].mx += seg[p].lazy;
    	seg[p << 1].lazy += seg[p].lazy;
    	seg[p << 1 | 1].lazy += seg[p].lazy;
    	seg[p].lazy = 0;
    }
}
void change(int p, int l, int r, int i){
    if(l == r){
    	seg[p].mx = seg[p].lazy = 0;
	   return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if(i <= mid) change(p << 1, l, mid, i);
    else change(p << 1 | 1, mid + 1, r, i);
    seg[p].mx = max(seg[p << 1].mx, seg[p << 1 | 1].mx);
}
void upd(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx){
    	seg[p].mx += 1;
    	seg[p].lazy += 1;
    	return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if(lx <= mid) upd(p << 1, l, mid, lx, rx);
    if(rx > mid) upd(p << 1 | 1, mid + 1, r, lx, rx);
    seg[p].mx = max(seg[p << 1].mx, seg[p << 1 | 1].mx);
}
int query(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx) return seg[p].mx;
    push_down(p);
    int res = 0, mid = (l + r) >> 1;
    if(lx <= mid) res = max(res, query(p << 1, l, mid, lx, rx));
    if(rx > mid) res = max(res, query(p << 1 | 1, mid + 1, r, lx, rx));
    return res;
}
void solve()
{
    int n; cin >> n;
    build(1, 0, n);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	change(1, 0, n, a[i]);
    	if(a[i]) upd(1, 0, n, 0, a[i] - 1);
    	cout << seg[1].mx << " \n" [i == n];
    }
}

int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
