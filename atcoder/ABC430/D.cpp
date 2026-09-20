#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> b(a), p(n + 1), c(a), id(n + 1);
    ranges::sort(b);
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        id[a[i]] = i;
    }
    set<int> st;
    st.insert(0);
    LL sum = INT_MAX;
    p[0] = INT_MAX;
    for(int i = 1; i <= n; i++){
        auto it = st.upper_bound(a[i]);
        p[a[i]] = INT_MAX;
        if(it != st.begin()){
            sum -= p[*prev(it)];
            p[*prev(it)] = min(p[*prev(it)], abs(c[i] - c[id[*prev(it)]]));
            p[a[i]] = min(p[a[i]], abs(c[i] - c[id[*prev(it)]]));
            sum += p[*prev(it)];
        }
        if(it != st.end()){
            sum -= p[*it];
            p[*it] = min(p[*it], abs(c[i] - c[id[*it]]));
            p[a[i]] = min(p[a[i]], abs(c[i] - c[id[*it]]));
            sum += p[*it];
        }
        sum += p[a[i]];
        st.insert(a[i]);
        cout << sum << "\n";

    }
}