// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 20:17:00
void solve(){
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), [](long long x, long long y){
        return abs(x) < abs(y);
    });
    /*
    a[i + 1] / a[i] == a[i] / a[i - 1]
    */
    if(abs(a[1]) == abs(a[n])){
        int cnt = count_if(a.begin() + 1, a.end(), [](int x){
            return x > 0;
        });
        if(abs(n - 2 * cnt) <= 1 || cnt == 0 || cnt == n){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
        return;
    }
    for(int i = 2; i < n; i++){
        if((a[i] * a[i]) != (a[i - 1] * a[i + 1])){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}