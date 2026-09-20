#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    vector<LL> pre1(n + 1), pre2(n + 1);
    for(int i = 1; i <= 2 * n; i++){
        if(i & 1) pre1[(i + 1) / 2] = pre1[(i + 1) / 2 - 1] + a[i];
        else pre2[i / 2] = pre2[i / 2 - 1] + a[i];
    }
    LL sum = accumulate(a.begin() + 1, a.end(), 0LL);
    LL pre = 0;
    for(int i = 1; i <= n; i++){
        pre += a[i];
        if(i & 1){
            cout << sum - 2 * ((pre1[(i + 1) / 2 + n - i] - pre1[(i + 1) / 2]) + pre) << " \n" [i == n];
        }else{
            cout << sum - 2 * ((pre2[i / 2 + n - i] - pre2[i / 2]) + pre) << " \n" [i == n];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}