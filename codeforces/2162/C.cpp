#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<int> op;
    for(int i = 0; i < 31; i++){
        if((b >> i & 1) != (a >> i & 1)){
            if((1 << i) > a){
                cout << "-1\n";
                return;
            }
            a ^= 1 << i;
            op.push_back(1 << i);
        }
    }
    cout << op.size() << "\n";
    for(auto x : op)
        cout << x << " ";
    cout << "\n";
}
int main()
{
    // freopen("1.in", "r", stdin);
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}