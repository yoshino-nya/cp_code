#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> ans(n + 1, 1), t(n + 1), num(n + 1);
    // 2 1 x x
    int res;
    auto ask = [&](int i){
        cout << "throw " << i << endl;
        cin >> res; return res;
    };
    auto swap = [&](int i){
        cout << "swap " << i << endl;
    };
    if(ask(n - 1) == 1) ans[n - 1] = 2;
    swap(n - 1);
    if(ask(n - 1) == 1) ans[n] = 2;
    t[n] = 1;
    if(ans[n] == 1) t[n - 1] = 2;
    else t[n - 1] = 1;
    num[n] = ans[n - 1], num[n - 1] = ans[n];
    for(int i = n - 3; i >= 1; i -= 2){
        // 1 1 , 2 2
        int x = ask(i);
        swap(i);
        int y = ask(i);
        if(x == y){
            // 1 2 x x, 2 1 x x 

            // 2 2 x x
        }else{
            // 1 1 x x
            // 1 2 x x, 2 1 x x
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}