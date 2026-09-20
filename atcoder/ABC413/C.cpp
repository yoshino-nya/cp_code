// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 20:06:41
void solve(){
    int q;
    cin >> q;
    deque<pair<int, int>> dq;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int c, x;
            cin >> c >> x;
            dq.push_back({c, x});
        }else{
            long long k;
            cin >> k;
            long long sum = 0;
            while(k > 0){
                auto [c, x] = dq.front();
                dq.pop_front();
                if(c > k){
                    sum += k * x;
                    dq.push_front({c - k, x});
                    k = 0;
                }else{
                    sum += 1LL * c * x;
                    k -= c;
                }
            }
            cout << sum << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}