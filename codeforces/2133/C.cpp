#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> len(n + 1);
    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    for(int i = 1; i <= n; i++){
        cout << "? " << i << " " << n << " ";
        for(auto s : st)
            cout << s << " ";
        cout << endl;
        cin >> len[i];
    }
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int x, int y){
        return len[x] > len[y];
    });
    vector<int> ans;
    set<int> st1;
    int root = p[1];
    for(int i = 1; i <= n; i++){
        cout << "? " << root << " " << st1.size() + 1  << " " << p[i] << " ";
        for(auto s : st1)
            cout << s << " ";
        cout << endl;
        int x; cin >> x;
        if(x == st1.size() + 1){
            st1.insert(p[i]), ans.push_back(p[i]);
        }
    }
    cout << "! " << ans.size() << " ";
    for(auto u : ans)
        cout << u << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}