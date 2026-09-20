#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s; s = " " + s;
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (s[i] == 'a');
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        int lo = i - 1, hi = n + 1;
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            if(pre[mid] - pre[i - 1] < a)
                lo = mid;
            else
                hi = mid;
        }
        if(hi == n + 1) continue;
        int L = hi;
        lo = i - 1, hi = n + 1;
        while(lo < hi - 1){
            int mid = (lo + hi) >> 1;
            if(mid - i + 1 - (pre[mid] - pre[i - 1]) < b)
                lo = mid;
            else hi = mid;
        }
        // cerr << lo << " " << L << " \n";

        if(lo < L) continue;
        ans += lo - L + 1;
    }
    cout << ans << "\n";
}