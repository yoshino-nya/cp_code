// Date: 2025-10-12 23:43:12
// Author: wuyi
// 
// Problem: C. Reverse XOR
// Contest: Codeforces - Codeforces Round 1058 (Div. 2)
// URL: https://codeforces.com/contest/2160/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    /*
	    1
	    1
	    
	    10
	    01
	    
	    11
	    11
	    
	    101
	    101 -> 0
	    
	    110
	    001 -> 111
	    
	    1010
	    0101 -> 1111
	    
	    1011
	    1101 -> 110
	    
	    
		
		    
    */
    // set<int> st;
    // for(int i = 1; i <= 65536; i++){
    	// vector<int> s;
    	// int x = i;
    	// while(x) s.push_back(x & 1), x /= 2;
    	// // reverse(s.begin(), s.end());
    	// for(int i : s)
    		// x = x * 2 + i;
    	// st.insert(x ^ i);
    // }
    // for(auto x : st){
    	// // cerr << x << '\n';
    	// vector<int> s;
    	// while(x) s.push_back(x & 1), x /= 2;
    	// reverse(s.begin(), s.end());
    	// for(int i : s)
    		// cerr << i;
    	// cerr << '\n';
	// }

	auto check = [](int x){
		vector<int> s;
		int c = 0;
		while(x){
			s.push_back(x & 1);
			c += x & 1;
			x >>= 1;
		}
		if(c & 1) return false;
		reverse(s.begin(), s.end());
		while(s.size() && s.back() == 0)
			s.pop_back();
		for(int l = 0, r = int(s.size()) - 1; l < r; l++, r--)
			if(s[l] != s[r]) return false;
		return true;
	};
	cout << (check(n) ? "YES" : "NO") << '\n';
	// for(int i = 1; i <= 1024; i++){
		// int x = i, c = 0;
    	// while(x) c += x & 1, x /= 2;
    	// if(!check(i) || st.contains(i)) continue;
    	// x = i;
    	// vector<int> s;
    	// while(x) s.push_back(x & 1), x /= 2;
    	// reverse(s.begin(), s.end());
    	// for(int i : s)
    		// cerr << i;
    	// cerr << '\n';
	// }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}