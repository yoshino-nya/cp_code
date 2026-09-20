#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> p(n + 1), q(n + 1);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        p[x] = i;
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        q[i] = p[x];
        // cerr << q[i] << " \n" [i == n];
    }
    set<int> st;
    for(int i = 1; i <= n; i++){
        auto it = st.upper_bound(q[i]);;
        if(it != st.end()) st.erase(it);
        st.insert(q[i]);
    }
    cout << st.size() << '\n';
    return 0;
}
/*
3 2 1 4 5
3 2 1 4 5

本质就是求最长递增子序列
*/