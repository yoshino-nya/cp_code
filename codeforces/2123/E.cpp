// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 18:21:37
using pii = pair<int, int>;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a.begin() + 1, a.end());
    int mex = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == mex)
            mex++;
        else if(a[i] > mex) break;
    }
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++)
        cnt[a[i]]++;
    /*
    mex <= n - k
    cnt[mex] <= k
    */
    // set<pii> st1, st2;
    priority_queue<pii, vector<pii>, greater<>> pq1;
    priority_queue<pii> pq2;
    for(int i = 0; i <= mex; i++){
        // st1.insert({cnt[i], i});
        pq1.push({cnt[i], i});
    }
    for(int k = 0; k <= n; k++){
        while(pq1.size() && pq1.top().first <= k){
            auto [c, i] = pq1.top();
            pq1.pop();
            pq2.push({i, c});
        }
        while(pq2.size() && pq2.top().first > n - k)
            pq2.pop();
        cout << pq2.size() << " \n" [k == n];
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}