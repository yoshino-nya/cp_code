#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int cnt[401][401], c[401];
void solve()
{
    int n; cin >> n;
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> s[i]; s[i] += 200;
    }
    int res = INT_MAX, num = 0;
    for(int i = 1; i <= n - i + 1; i++){
        if(s[i] > s[n - i + 1]) swap(s[i], s[n - i + 1]);
        if(s[i] != s[n - i + 1]){
            num += 2;
            c[s[i]]++, c[s[n - i + 1]]++;
            cnt[s[i]][s[n - i + 1]]++;
        }
    }
    if(!num){
        cout << "0\n";
        return;
    }
    for(int x = 0; x <= 400; x++){
        if(!c[x]) continue;
        for(int y = 0; y < x; y++){
            if(!c[y]) continue;
            res = min(res, num - c[x] - c[y] + cnt[y][x]);
            // if(res == 3) cerr << x << " " << y << '\n';
        }
    }
    for(int x = 0; x <= 400; x++){
        c[x] = 0;
        for(int y = 0; y < x; y++)
            cnt[y][x] = 0;
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}