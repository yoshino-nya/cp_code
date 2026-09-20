// Date: 2025-09-25 09:01:26
// 
// Problem: C. Circular RMQ
// Contest: Codeforces - Codeforces Testing Round 1
// URL: https://codeforces.com/problemset/problem/52/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200005;
int a[N];
struct node{
	LL min, lazy;
};
node seg[N << 2];
void build(int p, int l, int r){
	if(l == r){
		seg[p].min = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	seg[p].min = min(seg[p << 1].min, seg[p << 1 | 1].min);
}
void push_down(int p){
	if(seg[p].lazy){
		seg[p << 1].min += seg[p].lazy;
		seg[p << 1 | 1].min += seg[p].lazy;
		seg[p << 1].lazy += seg[p].lazy;
		seg[p << 1 | 1].lazy += seg[p].lazy;
		seg[p].lazy = 0;
	}
}
void update(int p, int l, int r, int lx, int rx, LL v){
	if(l >= lx && r <= rx){
		seg[p].min += v;
		seg[p].lazy += v;
		return;
	}
	push_down(p);
	int mid = (l + r) >> 1;
	if(lx <= mid) update(p << 1, l, mid, lx, rx, v);
	if(rx > mid) update(p << 1 | 1, mid + 1, r, lx, rx, v);
	seg[p].min = min(seg[p << 1].min, seg[p << 1 | 1].min);
}
LL query(int p, int l, int r, int lx, int rx){
	if(l >= lx && r <= rx) return seg[p].min;
	push_down(p);
	LL res = LLONG_MAX;
	int mid = (l + r) >> 1;
	if(lx <= mid) res = min(res, query(p << 1, l, mid, lx, rx));
	if(rx > mid) res = min(res, query(p << 1 | 1, mid + 1, r, lx, rx));
	return res;
}
void solve(){
    int n; cin >> n; --n;
    for(int i = 0; i <= n; i++) cin >> a[i];
    build(1, 0, n);
    int q; cin >> q;
    int l, r, v;
    getchar();
    while(q--){
    	string s; getline(cin, s);
    	// cerr << s << "\n";
    	vector<int> op;
    	for(int i = 0; i < s.size(); i++){
    		// cerr << int(s[i]) << " ";
    		if(s[i] != ' ' && s[i] >= '0' && s[i] <= '9'){
    			int tmp = 0, j = i, w = 1;
    			if(i && s[i - 1] == '-') w = -1;
    			while(j < s.size() && s[j] >= '0' && s[j] <= '9'){
    				tmp = tmp * 10 + s[j] - '0';
    				j++;
				}
    			i = j;
    			op.push_back(w * tmp);
    		}
    	}
    	// cerr << '\n';
    	// cerr << op.size() << '\n';
    	// assert(op.size() >= 2);

    	l = op[0], r = op[1];
    	// cerr << "l, r : " << l << " " << r << '\n';
    	if(op.size() == 2){
    		LL res = LLONG_MAX;
    		if(l <= r){
    			res = query(1, 0, n, l, r);
    		}else{
    			res = min(query(1, 0, n, l, n), query(1, 0, n, 0, r));
    		}
    		cout << res << '\n';
    	}else{
    		v = op[2];
    		if(l <= r){
    			update(1, 0, n, l, r, v);
    		}else{
    			update(1, 0, n, l, n, v), update(1, 0, n, 0, r, v);
    		}
    	}
    }
}
int main(){
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
