// Date: 2025-09-25 09:58:26
// 
// Problem: D. The Child and Sequence
// Contest: Codeforces - Codeforces Round 250 (Div. 1)
// URL: https://codeforces.com/problemset/problem/438/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 100005;
struct node{
	int max;
	LL sum;
};
node seg[N << 2];
int a[N];
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

void push_up(int p){
	seg[p].max = max(seg[ls].max, seg[rs].max);
	seg[p].sum = seg[ls].sum + seg[rs].sum;
}
void build(int p, int l, int r){
	if(l == r){
		seg[p].max = seg[p].sum = a[l];
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	push_up(p);
}
void update(int p, int l, int r, int lx, int rx, int mod){
	if(seg[p].max < mod) return;
	if(l == r){
		seg[p].sum = seg[p].max = seg[p].max % mod;
		return;
	}
	if(lx <= mid) update(ls, l, mid, lx, rx, mod);
	if(rx > mid) update(rs, mid + 1, r, lx, rx, mod);
	push_up(p);
}
void change(int p, int l, int r, int i, int x){
	if(l == r){
		seg[p].max = seg[p].sum = x;
		return;
	}
	if(i <= mid) change(ls, l, mid, i, x);
	else change(rs, mid + 1, r, i, x);
	push_up(p);
}
LL query(int p, int l, int r, int lx, int rx){
	if(l >= lx && r <= rx) return seg[p].sum;
	LL sum = 0;
	if(lx <= mid) sum += query(ls, l, mid, lx, rx);
	if(rx > mid) sum += query(rs, mid + 1, r, lx, rx);
	return sum;
}
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    build(1, 1, n);
    int op, l, r, k, x;
    while(m--){
    	cin >> op;
    	if(op == 1){
    		cin >> l >> r;
    		cout << query(1, 1, n, l, r) << "\n";
    	}else if(op == 2){
    		cin >> l >> r >> x;
    		update(1, 1, n, l, r, x);
    	}else{
    		cin >> k >> x;
    		change(1, 1, n, k, x);
    	}
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
