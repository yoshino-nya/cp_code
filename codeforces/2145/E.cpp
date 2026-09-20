// Date: 2025-10-09 08:34:58
// Author: wuyi
// 
// Problem: E. Predicting Popularity
// Contest: Codeforces - Educational Codeforces Round 183 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2145/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

struct node{
	int min, lazy;
};
constexpr int N = 1000005;
node seg[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
void build(int p, int l, int r){
	seg[p].lazy = 0;
	if(l == r){
		seg[p].min = -l;
		return;
	}
	build(ls, l, mi), build(rs, mi + 1, r);
	seg[p].min = min(seg[ls].min, seg[rs].min);
}
void push_dwon(int p){
	if(seg[p].lazy){
		seg[ls].min += seg[p].lazy;
		seg[rs].min += seg[p].lazy;
		seg[ls].lazy += seg[p].lazy;
		seg[rs].lazy += seg[p].lazy;
		seg[p].lazy = 0;
	}
}
void add(int p, int l, int r, int lx, int rx, int x){
	if(l >= lx && r <= rx){
		seg[p].min += x;
		seg[p].lazy += x;
		return;
	}
	push_dwon(p);
	if(lx <= mi) add(ls, l, mi, lx, rx, x);
	if(rx > mi) add(rs, mi + 1, r, lx, rx, x);
	seg[p].min = min(seg[ls].min, seg[rs].min);
}
int find(int p, int l, int r){
	if(l == r) return l;
	push_dwon(p);
	if(seg[ls].min < 0) return find(ls, l, mi);
	return find(rs, mi + 1, r);
}
void solve(){
    int ac, dr; cin >> ac >> dr;
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	p[i] += max(x - ac, 0);
    }
    build(1, 1, n + 1);
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	p[i] += max(x - dr, 0);
    	if(p[i] <= n)
    		add(1, 1, n + 1, p[i] + 1, n, 1);
    	// cerr << p[i] << " \n" [i == n];
    }
    int q; cin >> q;
    while(q--){
    	int idx, x, y; cin >> idx >> x >> y;
    	if(p[idx] <= n)
    		add(1, 1, n + 1, p[idx] + 1, n + 1, -1);
    	p[idx] = max(x - ac, 0) + max(y - dr, 0);
    	// cerr << p[idx] << "\n";
    	if(p[idx] <= n)
    		add(1, 1, n + 1, p[idx] + 1, n + 1, 1);
    	cout << find(1, 1, n + 1) - 1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}