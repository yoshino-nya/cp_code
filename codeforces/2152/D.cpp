#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int lowbit(int x){return (x) & (-x);}
void solve()
{
    int n, q; cin >> n >> q;
    vector<LL> pre1(n + 1), pre2(n + 1), pre0(n + 1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre0[i] = pre0[i - 1] + __lg(x), pre1[i] = pre1[i - 1], pre2[i] = pre2[i - 1];
        if(lowbit(x) == x) continue;
        if(lowbit(x - 1) == x - 1) pre1[i]++;
        else if(lowbit(x) != x) pre2[i]++;
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << pre0[r] - pre0[l - 1] + pre2[r] - pre2[l - 1] + (pre1[r] - pre1[l - 1]) / 2 << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}