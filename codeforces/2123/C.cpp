// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 18:06:14
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 1, INT_MAX), suf(n + 1);
    for(int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], a[i]);
    for(int i = n, mx = 0; i >= 1; i--){
        mx = max(mx, a[i]);
        suf[i] = mx;
    }
    for(int i = 1; i <= n; i++){
        if((a[i] == pre[i]) || (a[i] == suf[i])){
            cout << "1";
        }else{
            cout << "0";
        }
        
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}