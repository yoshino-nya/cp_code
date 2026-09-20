// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 18:16:00
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), '1') <= k){
        cout << "Alice\n";
    }else if(k > n / 2){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}