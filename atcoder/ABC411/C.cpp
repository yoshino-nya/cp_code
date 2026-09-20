#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> st(n + 2);
    int ans = 0;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        if(st[x]){
            // to be white
            if(st[x - 1] && st[x + 1])
                ans++;
            else if(st[x - 1] == 0 && st[x + 1] == 0)
                ans--;
        }else{
            if(st[x - 1] && st[x + 1])
                ans--;
            else if(st[x - 1] == 0 && st[x + 1] == 0)
                ans++;
        }
        st[x] ^= 1;
        cout << ans << '\n';
    }
    return 0;
}