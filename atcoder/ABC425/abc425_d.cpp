// Date: 2025-09-27 20:16:23
// 
// Problem: D - Ulam-Warburton Automaton
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h, w; cin >> h >> w;
    vector<vector<char>> ss(h + 1, vector<char> (w + 1));
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++)
    		cin >> ss[i][j];
    }
    auto check = [&](int x, int y){
    	return x >= 1 && x <= h && y >= 1 && y <= w;
    };
    vector<vector<int>> cnt(h + 1, vector<int> (w + 1));
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		if(ss[i][j] == '#'){
    			for(auto [dx, dy] : dirs){
    				int nx = i + dx, ny = j + dy;
    				if(check(nx, ny) && ss[nx][ny] == '.')
    					cnt[nx][ny]++;
    			}
    			cnt[i][j] = 4;
    		}
    	}
    }
    set<pair<int, int>> st1;
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		// if(cnt[i][j] == 0) st0.insert({i, j});
    		if(cnt[i][j] == 1) st1.insert({i, j});
    	}
    }
    while(!st1.empty()){
    	vector<pair<int, int>> tmp;
    	for(auto [i, j] : st1){
    		for(auto [dx, dy] : dirs){
				int nx = i + dx, ny = j + dy;
				if(check(nx, ny) && ss[nx][ny] == '.'){
					cnt[nx][ny]++;
					tmp.push_back({nx, ny});
				}
    		}
    		ss[i][j] = '#';
    	}
    	st1.clear();
    	for(auto [i, j] : tmp){
    		if(ss[i][j] == '.' && cnt[i][j] == 1){
    			st1.insert({i, j});
    		}
    	}
    }
    int ans = 0;
    for(int i = 1; i <= h; i++)
    	for(int j = 1; j <= w; j++) if(ss[i][j] == '#') ans++;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}
