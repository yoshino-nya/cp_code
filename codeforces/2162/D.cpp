#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    auto ask = [](int tp, int l, int r){
        cout << tp << " " << l << " " << r << endl;
        int res; cin >> res;
        return res;
    };
    int l = 0, r = n + 1;
    while(l < r - 1){
        int mid = (l + r) >> 1;
        if(ask(1, 1, mid) != ask(2, 1, mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    int L = r;
    int len = ask(2, 1, n) - ask(1, 1, n);
    cout << "! " << L << " " << L + len - 1 << endl;
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}