// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
// created: 2025-06-25 22:16:33
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    int lo = a[1] -1 , hi = accumulate(a.begin() + 1, a.end(), 0LL) / n + 1;
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        ll s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i++){
            s1 += max(0, mid - a[i]);
            s2 += max(0, a[i] - k - mid);
        }
        if(s1 <= s2) lo = mid;
        else hi = mid;
    }
    ll def = 0, exc = 0, defs = 0, excs = 0, ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] <= lo){
            def += lo - a[i];
            defs++;
            a[i] = lo;
        }else if(a[i] > k + lo){
            exc += a[i] - k - lo;
            excs++;
            a[i] = k + lo;
        }
    }
    exc -= def;
    for(int i = 1; i <= min(exc, excs); i++)
        a[n - i + 1]++;
    exc -= excs;
    for(int i = 1; i <= exc; i++)
        a[i]++, def++;
    ans += def * k;
    for(int i = 1; i <= n; i++)
        ans += 1LL * a[i] * (a[i] + 1) / 2;
    cout << ans << '\n';
}
/* <think>
移走之后，如果多了一些
那就加回去
要是加回去，还剩了一些，就移过去
好好好，还行
</think> */
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}