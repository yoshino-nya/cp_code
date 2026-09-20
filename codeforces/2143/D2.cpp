#include<bits/stdc++.h>
using namespace std;
// created: 2025-10-13 14:37:55
constexpr int mod = 1000000007;
int dp[2005][2005];

void ADD(int &x, int y){
    x += y;
    if(x >= mod) x-= mod;
}
struct BIT{
    vector<int> bit; int sz;
    int lowbit(int x){return (x) & (-x);}
    BIT(int n) : bit(n + 1), sz(n) {}
    
    void add(int i, int x){
        if(!i) ADD(bit[0], x);
        while(i && i <= sz){
            ADD(bit[i], x);
            i += lowbit(i);
        }
    }
    int get(int i){
        int res = bit[0];
        for( ; i; i -= lowbit(i)){
            ADD(res, bit[i]);
        }
        return res;
    }
};
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<BIT> r(n + 1, BIT(n)), c(n + 1, BIT(n));
    r[0].add(0, 1);
    c[0].add(0, 1);
    for(int i = 1; i <= n; i++){
        for(int x = 0; x < a[i]; x++){
            int v = c[x].get(a[i]);
            r[a[i]].add(x, v);
            c[x].add(a[i], v);
        }
        for(int x = a[i] + 1; x <= n; x++){
            int v = r[x].get(a[i]);
            r[x].add(a[i], v);
            c[a[i]].add(x, v);
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        ADD(ans, r[i].get(n));
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}