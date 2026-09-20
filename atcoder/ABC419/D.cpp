#include<bits/stdc++.h>
using namespace std;

constexpr int N = int(2e5) + 1;
struct node{
    int l, r;
};
node seg[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < m; i++){
        cin >> seg[i].l >> seg[i].r;
    }
    sort(seg, seg + m, [](node x, node y){
        return x.l < y.l;
    });
    vector<int> a(n + 1), d(n + 2);
    int now = 0;
    for(int i = 1, j = 0; i <= n; i++){
        while(j < m && seg[j].l == i){
            now ^= 1, d[seg[j].r + 1] ^= 1;
            j++;
        }
        now ^= d[i];
        a[i] ^= now;
    }
    for(int i = 0; i < n; i++){
        if(a[i + 1]){
            swap(s[i], t[i]);
        }
    }
    cout << s << '\n';
    return 0;
}