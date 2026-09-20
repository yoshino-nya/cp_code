// Date: 2025-09-27 20:02:32
// 
// Problem: B - Find Permutation 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), cnt(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	if(a[i] > 0)
    		cnt[a[i]]++;
    }
    if(*max_element(cnt.begin() + 1, cnt.end()) > 1){
    	cout << "No\n";
    	return;
    }
    cout << "Yes\n";
    for(int i = 1, j = 1; i <= n; i++){
    	if(a[i] == -1){
    		while(cnt[j]) j++;
    		a[i] = j++;
    	}
    	cout << a[i] << " \n" [i == n];
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
