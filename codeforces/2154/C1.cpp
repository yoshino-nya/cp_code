#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int N = 200000;
vector<int> primes;
int minp[N + 1], cnt1[N + 1], cnt2[N + 1];
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
    }
    int ans = 2;
    vector<int> vec;
    for(int i = 1; i <= n; i++){
        int x = a[i];
        for(int j = 2; j * j <= x; j++){
            if(x % j == 0){
                vec.push_back(j);
                if(cnt1[j]) ans = min(ans, 0);
                if(cnt2[j]) ans = min(ans, 1);
                cnt1[j]++;
                while(x % j == 0) x /= j;
            }
        }
        if(x != 1){
            vec.push_back(x);
            if(cnt1[x]) ans = min(ans, 0);
            if(cnt2[x]) ans = min(ans, 1);
            cnt1[x]++;
        }
        x = a[i] + 1;
        for(int j = 2; j * j <= x; j++){
            if(x % j == 0){
                vec.push_back(j);
                if(cnt1[j]) ans = min(ans, 1);
                cnt2[j]++;
                while(x % j == 0) x /= j;
            }
        }
        if(x != 1){
            vec.push_back(x);
            if(cnt1[x]) ans = min(ans, 1);
            cnt2[x]++;
        }
    }
    for(auto x : vec)
        cnt1[x] = cnt2[x] = 0;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(!minp[i]){
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes){
            if(i * p > N) break;
            minp[i * p] = p;
        }
    }
    cerr << primes.size() << '\n';
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}