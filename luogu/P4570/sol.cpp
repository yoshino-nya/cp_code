#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int n; cin >> n;
    vector<LL> v(64);
    auto Insert = [&](LL x){
        for(int i = 63; i >= 0; i--){
            if(x >> i & 1){
                if(v[i])
                    x ^= v[i];
                else{
                    v[i] = x;
                    return true;
                }
            }
        }
        return false;
    };
    vector<pair<LL, int>> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    ranges::sort(vec, [](pair<LL, int> x, pair<LL, int> y){
        return x.second > y.second;
    });
    int ans = 0;
    for(auto [number, magic] : vec){
        if(Insert(number))
            ans += magic;
    }
    cout << ans << '\n';
    return 0;
}