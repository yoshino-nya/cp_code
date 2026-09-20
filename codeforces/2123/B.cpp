// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 18:01:36
void solve(){
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(k > 1){
        cout << "Yes\n";
        return;
    }
    if(a[j] < *max_element(a.begin() + 1, a.end())){
        cout << "No\n";
    }else{
        cout << "YEs\n";
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}