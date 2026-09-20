// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// created: 2025-07-05 22:36:16
void solve(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if(a <= b){
        ll ans = 0;
        for(int i = a + 1; i <= b; i++){
            if(((i - 1) ^ 1) == i) ans += min(x, y);
            else ans += x;
        }
        cout << ans << '\n';
    }else if((a & 1) && (a == b + 1)){
        cout << y << '\n';
    }else{
        cout << "-1\n";
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}