#include <bits/stdc++.h>
// #include "/home/skadi/codes/cp_code/template/debug.hpp"
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 20:37:10 
    int n, m;
    cin >> n >> m; 
    set<pii> edges;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        edges.insert({x, y});
        edges.insert({y, x});
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int ans = 100;
    // dbg(p);
    do{
        set<pii> nedges(edges);
        int res = m + n;
        for(int i = 0; i < n; i++){
            if(edges.find({p[i], p[(i + 1) % n]}) != edges.end()){
                // nedges.erase({p[i], p[(i + 1) % n]});
                // nedges.erase({p[(i + 1) % n], p[i]});
                res -= 2;
            }
        }
        
        for(int x = 3; x < n; x++){
            if(n - x < 3) break;
            int resu = n + m;
            for(int i = 0; i < x; i++){
                if(edges.find({p[i], p[(i + 1) % x]}) != edges.end())
                    resu -= 2;
            }
            int y = n - x;
            vector<int> q(p.begin() + x, p.end());
            for(int i = 0; i < y; i++){
                if(edges.find({q[i], q[(i + 1) % y]}) != edges.end())
                    resu -= 2;
            }
            res = min(res, resu);
        }
        // if(res == 4){
        //     dbg(p);
        // }
        // 6 4 1 5 3 2
        // dbg(nedges.size());
        // ans = min(ans, nedges.size() - m * 2);
        ans = min(ans, res);
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}