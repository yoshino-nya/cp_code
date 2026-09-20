#include <bits/stdc++.h>
using namespace std;

struct query
{
    int i, l, r;
};
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> L(n + 1), R(n + 1);
    for(int i = 1, last = n + 1; i <= n; i++){
        if(s[i] == '#')
            last = i;
        L[i] = last;
    }
    for(int i = n, last = 0; i >= 1; i--){
        if(s[i] == '#')
            last = i;
        R[i] = last;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        if(R[l] <= L[r] && R[l] >= l && L[r] <= r){
            // cerr << R[l] << " " << L[r] << '\n';
            cout << L[r] - R[l] + 1 << '\n';
        }else{
            cout << "0\n";
        }
    }
    return 0;
}