#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = accumulate(a.begin() + 1, a.end(), 0);
    if(sum == s){
        cout << "-1\n";
        return;
    }
    if(sum > s){
        for(int i = 1; i <= n; i++)
            cout << a[i] << " \n" [i == n];
        return;
    }
    /*
    不能让 01 相邻
    因为正好可以随便 + 1

    21相邻一次可以 +3
    02 相邻一次可以 +2
    因此当且仅当差值为 1 时可以做到
    */
    if(sum != s - 1)
        cout << "-1\n";
    else{
        int x = count(a.begin() + 1, a.end(), 0);
        int y = count(a.begin() + 1, a.end(), 2);
        for(int i = 1; i <= x; i++)
            cout << "0 ";
        for(int i = 1; i <= y; i++)
            cout << "2 ";
        for(int i = 1; i <= n - x - y; i++)
            cout << "1 ";
        cout << '\n';
    }
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}