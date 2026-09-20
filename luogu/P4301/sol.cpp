#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<>());
    vector<int> v(32);
    auto Insert = [&](int x){
        for(int i = 31; i >= 0; i--){
            if(x >> i & 1){
                if(v[i]){
                    x ^= v[i];
                }else{
                    v[i] = x;
                    // cerr << i << " " << x << '\n';
                    return true;
                }
            }
        }
        return false;
    };
    /*
    别人也要拿啊 所以要使得另外一个人
    无论如何都凑不出异或和为0的堆
    那么也就是只给他留一个线性基
    */
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(!Insert(a[i])) ans += a[i];
    }
    cout << ans << '\n';
    return 0;
}