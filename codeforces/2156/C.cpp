#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200000;
int bit[N + 1];
int lowbit(int x){return (x) & (-x);}
void add(int i, int x){
    while(i <= N){
        bit[i] += x;
        i += lowbit(i);
    }
}
int ask(int i){
    assert(i >= 0);
    i = min(N, i);
    int res = 0;
    while(i){
        res += bit[i];
        i -= lowbit(i);
    }
    return res;
}
void solve()
{
    /*
    首先，倍数的数量必须是 >= n - k
    
    找 > 3x，且不是 x 的倍数的数字
    那么直接找不整除的，然后减去 [1, 2x] + cnt[x] + cnt[2 * x]
    */
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // for(int j = 1; j * j <= a[i]; j++){
        //     if(a[i] % j == 0){
        //         cnt[j]++;
        //         if(a[i] / j != j)
        //             cnt[a[i] / j]++;
        //     }
        // }
        add(a[i], 1);
    }
    int ans = 1;
    for(int val = n; val >= 1; val--){
        // cerr << cnt[val] << " \n" [val == n];
        int ct = ask(4 * val - 1);
        // cerr << ct << " ";
        for(int i = 1; i <= 3 && i * val <= n; i++)
            ct -= ask(i * val) - ask(i * val - 1);
        // cerr << ct << " \n";
        if(ct <= k){
            ans = val;
            break;
        }
    }
    cout << ans << "\n";
    for(int i = 1; i <= n; i++)
        add(a[i], -1);
}
// x x + r 2x
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);

    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}