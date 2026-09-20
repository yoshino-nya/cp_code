#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 20:24:37 
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    // if(n == 2){
    //     if(a[1] * 2 < a[n]){
    //         cout << "-1\n";
    //     }else{
    //         cout << "2\n";
    //     }
    //     return;
    // }
    multiset<int> st(a.begin() + 2, a.begin() + n);
    int now = a[1], ans = 2;
    while(st.size() && now * 2 < a[n]){
        auto it = st.upper_bound(now * 2);
        if(it == st.begin()){
            break;
        }
        ans++;
        now = *prev(it);
        st.erase(prev(it));
    }
    if(now * 2 >= a[n]) cout << ans << '\n';
    else cout << "-1\n";
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