// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 22:44:18
using pii = pair<int, int>;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    ll sx, sy, ex,ey;
    cin >> sx >> sy >> ex >> ey;
    vector<double> a(n + 1);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey));
    ranges::sort(a);
    if(accumulate(a.begin(), a.begin() + n, 0) < a[n])
        cout << "No\n";
    else
        cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}