// Date: 2025-09-29 11:19:58
// Author: wuyi
// 
// Problem: E. XOR and Favorite Number
// Contest: Codeforces - Codeforces Round 340 (Div. 2)
// URL: https://codeforces.com/problemset/problem/617/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int cnt[2000001], pos[100001], a[100001], pre[100001];
LL ans[100000];
struct node{
	int l, r, idx;
};
node Q[100000];
void solve(){
    int n, m, k; cin >> n >> m >> k;
    int siz = sqrt(n);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	pos[i] = i / siz;
    	pre[i] = pre[i - 1] ^ a[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> Q[i].l >> Q[i].r;
    	Q[i].l--;
    	Q[i].idx = i;
    }
    sort(Q, Q + m, [&](node x, node y){
    	if(pos[x.l] != pos[y.l]) return pos[x.l] < pos[y.l];
    	if(pos[x.l] & 1) return pos[x.r] > pos[y.r];
    	return pos[x.r] < pos[y.r];
    });
    int L = 0, R = -1;
    LL now = 0;
    auto add = [&](int i){
    	now += cnt[pre[i] ^ k];
    	cnt[pre[i]]++;
    };
    auto del = [&](int i){
    	cnt[pre[i]]--;
    	now -= cnt[pre[i] ^ k];
    };
    for(int _ = 0; _ < m; _++){
    	auto [l, r, idx] = Q[_];
    	while(L > l) add(--L);
    	while(L < l) del(L++);
    	while(R > r) del(R--);
    	while(R < r) add(++R);
    	ans[idx] = now;
    }
    for(int i = 0; i < m; i++)
    	cout << ans[i] << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}