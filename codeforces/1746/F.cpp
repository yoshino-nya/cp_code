// Date: 2025-09-12 09:09:58
// Author: wuyi
// 
// Problem: F. Kazaee
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/problemset/problem/1746/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
mt19937_64 rng(time(NULL));
LL rnd(LL l, LL r){
	uniform_int_distribution<LL> dis(l, r);
	return dis(rng);
}
constexpr int inf = int(1e9);
constexpr int N = int(6e5) + 5;
// int val[N]; LL bit[N];
array<int, N> val{};
array<LL, N> bit{};
int lowbit(int x){return (x) & (-x);}
void add(int i, int x){
	while(i < N){
		bit[i] += x;
		i += lowbit(i);
	}
}
LL ask(int i){
	LL res = 0;
	while(i){
		res += bit[i];
		i -= lowbit(i);
	}
	return res;
}
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // return;
    vector<int> b(a), c(n + 1);
    vector<vector<int>> op(q);
    vector<int> ans;
    for(int i = 0; i < q; i++){
    	int o; cin >> o;
    	if(o == 1){
    		// int i, x; cin >> i >> x; 666
    		int id, x; cin >> id >> x;
    		op[i] = {id, x};
    		b.push_back(x);
    	}else{
    		int l, r, k; cin >> l >> r >> k;
    		op[i] = {l, r, k};
    		ans.push_back(1);
    	}
    }
    // 也就是说这上面的部分有数组越界，6 哪有问题了
    // 哦我服了，输入咋也有个 i 。。。
    // return;
	sort(b.begin() + 1, b.end());
	b.erase(unique(b.begin() + 1, b.end()), b.end());
	auto get_id = [&](int x){
		return lower_bound(b.begin() + 1, b.end(), x) - b.begin();
	};
	for(int i = 1; i <= n; i++) a[i] = get_id(a[i]);
	for(auto &v : op){
		if(v.size() == 2){
			v[1] = get_id(v[1]);
		}
	}
	// for(int i = 1; i <= n; i++) cerr << a[i] << " \n"[i == n];
	// for(auto &v : op){
		// if(v.size() == 2){
			// cerr << v[1] << "\n";
		// }
	// }
	// return;
	/*
	cnt[x] % k, cnt[y] % k
	k | x * cnt[x] + y * cnt[y]
	*/
    for(int tt = 1; tt <= 30; tt++){
    	// memset(bit, 0, sizeof(bit));
    	for(int i = 1; i < b.size(); i++){
    		val[i] = rnd(1, inf);
    		// cerr << val[i] << " \n" [i == b.size() - 1];
    	}
    	assert(a.size() == n + 1);
		for(int i = 1; i <= n; i++){
			c[i] = val[a[i]];
			add(i, c[i]);
		}
		int id = 0;
		for(auto v : op){
			if(v.size() == 2){
				int i = v[0], x = val[v[1]];
				assert(i <= n);
				add(i, -c[i] + x);
				c[i] = x;
			}else{
				assert(v.size() == 3);
				int l = v[0], r = v[1], k = v[2];
				assert(id < ans.size());
				// % k 不等于 0，则说明，NO。
				// 只要有一次，就是NO
				ans[id] &= ((ask(r) - ask(l - 1)) % k) == 0;
				++id;
			}
		}
		for(int i = 1; i <= n; i++)
			add(i, -c[i]);
    }
    for(auto x : ans)
    	cout << (x ? "YES" : "NO") << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}