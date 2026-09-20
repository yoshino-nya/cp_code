// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 20:02:41
void solve(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    set<string> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            st.insert(s[i] + s[j]);
            st.insert(s[j] + s[i]);
        }
    }
    cout << st.size() << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}