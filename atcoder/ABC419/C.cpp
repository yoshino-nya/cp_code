#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> r[i] >> c[i];
    ranges::sort(r), ranges::sort(c);
    int ans = (max(r[n - 1] - r[0], c[n - 1] - c[0]) + 1) / 2;
    cout << ans << '\n';
    return 0;
}