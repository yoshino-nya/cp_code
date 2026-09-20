#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-26
{                      // Time: 15:55:58 
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    set<int> st(a.begin() + 1, a.end());
    if(st.size() > k){
        cout << "-1\n";
        return;
    }
    // while(st.size() < k) st.insert(k);
    for(int i = 1;i <= n && st.size() < k; i++)
        st.insert(i);
    cout << n * k << '\n';
    for(int i = 1; i <= n; i++){
        for(auto x : st)
            cout << x << " ";
        // cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}