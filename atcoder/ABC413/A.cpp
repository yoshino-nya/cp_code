// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 20:00:31
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        m -= x;
    }
    cout << (m >= 0 ? "Yes" : "No") << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}