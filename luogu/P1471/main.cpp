#include <bits/stdc++.h>
using namespace std;

// (x - y) ^ 2 = x ^ 2 + y ^ 2 - 2xy
struct node{
	double sum1, sum2, lazy;
	node(){sum1 = sum2 = lazy = 0;}
};
constexpr int N = 100005;
double a[N];
node seg[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)
constexpr double eps = 1e-9;
void build(int p, int l, int r){
	if(l == r){
		seg[p].sum1 = a[l] * a[l];
		seg[p].sum2 = a[l];
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	seg[p].sum1 = seg[ls].sum1 + seg[rs].sum1;
	seg[p].sum2 = seg[ls].sum2 + seg[rs].sum2;
}
void push_down(int p, int l, int r){
	if(abs(seg[p].lazy) > eps){
		seg[ls].sum1 += (mid - l + 1) * seg[p].lazy * seg[p].lazy + 2 * seg[p].lazy * seg[ls].sum2;
		seg[rs].sum1 += (r - mid) * seg[p].lazy * seg[p].lazy + 2 * seg[p].lazy * seg[rs].sum2;
		seg[ls].sum2 += (mid - l + 1) * seg[p].lazy;
		seg[rs].sum2 += (r - mid) * seg[p].lazy;
		seg[ls].lazy += seg[p].lazy;
		seg[rs].lazy += seg[p].lazy;
		seg[p].lazy = 0;
	}
}
void update(int p, int l, int r, int lx, int rx, double val){
	if(l >= lx && r <= rx){
		seg[p].sum1 += (r - l + 1) * val * val + 2 * val * seg[p].sum2;
		seg[p].sum2 += (r - l + 1) * val;
		seg[p].lazy += val;
		return;
	}
	push_down(p, l, r);
	if(lx <= mid) update(ls, l, mid, lx, rx, val);
	if(rx > mid) update(rs, mid + 1, r, lx, rx, val);
	seg[p].sum1 = seg[ls].sum1 + seg[rs].sum1;
	seg[p].sum2 = seg[ls].sum2 + seg[rs].sum2;
}
node query(int p, int l, int r, int lx, int rx){
	if(l >= lx && r <= rx) return seg[p];
	push_down(p, l, r);
	node res;
	if(lx <= mid) res = query(ls, l, mid, lx, rx);
	if(rx > mid){ node tmp = query(rs, mid + 1, r, lx, rx); res.sum1 += tmp.sum1, res.sum2 += tmp.sum2;}
	return res;
}
int main()
{
	// freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(4);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	int op, x, y;
	double k;
	while(q--){
		cin >> op >> x >> y;
		if(op == 1){
			cin >> k;
			update(1, 1, n, x, y, k);
		}else if(op == 2)
			cout << query(1, 1, n, x, y).sum2 / (y - x + 1) << "\n";
		else{
			node res = query(1, 1, n, x, y);
			double z = res.sum2 / (y - x + 1);
			double ans = (res.sum1 + z * z * (y - x + 1) - 2 * res.sum2 * z) / (y - x + 1);
			cout << ans << "\n";
		}
	}
	return 0;
}