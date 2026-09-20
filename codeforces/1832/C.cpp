#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    /*
    怎么写来着，把递增递减的子数组大小都弄成2
    这个要怎么写。。。
    先去重就很简单了，那美食了
    */
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    n = a.size() - 1;
    if(n == 1){
        cout << "1\n";
        return;
    }
    int ans = 2;
    for(int i = 2; i < n; i++){
        if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
| a[1] - a[2] | + | a[2] - a[3] |
a[1] - a[2] + a[2] - a[3] = a[1] - a[3]
a[2] - a[1] + a[2] - a[3]
*/