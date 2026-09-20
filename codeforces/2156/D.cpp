#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    /*
    n + n / 2 + n / 4

    0 or 1
    -> 0, 10 or 00
    */
    int n, sum;
    cin >> n; sum = n;
    
    int cur = 0;
    vector<int> items(n - 1);
    iota(items.begin(), items.end(), 1);
    auto calc = [&](int x){
        int res = 0;
        for(int i = 1; i <= n; i++){
            bool ok = true;
            for(int j = __lg(x); j >= 0 && ok; j--)
                if((i >> j & 1) != (x >> j & 1))
                    ok = false;
            if(ok) res++;
        }
        return res;
    };
    for(int i = 0; (1 << i) <= n; i++){
        vector<int> i0, i1;
        cur |= 1 << i;
        for(auto it : items){
            cout << "? " << it << " " << (1 << i) << endl;
            int res; cin >> res;
            if(!res) i0.push_back(it);
            else i1.push_back(it);
        }
        int x = calc(cur), y = items.size() + 1 - x;
        // cerr << format("x : {}, i1 : {}, i0 : {}", x, i1.size(), i0.size()) << endl;
        if(x != int(i1.size())){
            // cur |= 1 << i;
            items = i1;
        }else{
            items = i0;
            cur ^= 1 << i;
        }
    }
    // int vis = 0;
    // for(int i = 1, p = cur; i <= n; i++)
    //     if((i & p) == p){
    //         cur = i;
    //         cerr << "ok : "<< i << endl;
    //         vis++;
    //     }
    // assert(vis == 1);
    cout << "! " << cur << endl;
}
// x x + r 2x
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);

    // freopen("1.err", "w", stderr);
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
// 6 : [1, 2, 3, 4, 5, 6]
// 6 : [4, 5, 3, 1, 6, 2]
// [100, 101, 011, 001, 110, 010]