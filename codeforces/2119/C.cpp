// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 23:07:51
using ll = long long;
void solve(){
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n & 1){
        cout << l << '\n';
    }else{
        if(n == 2) cout << "-1\n";
        else{
            // 1 0，  0 1
            // 答案好像只能是0
            // 如果奇数个1 则这一位是1 不行
            // 如果偶数个1 则这一位是0 不行
            // 所以答案只能是 0
            ll lmt = 1 << (__lg(l) + 1);
            if(lmt <= r){
                if(k <= n - 2) cout << l << '\n';
                else cout << lmt << '\n';
            }else {
                cout << "-1\n";
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}