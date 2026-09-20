#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 10:08:29
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        auto it = st.upper_bound(r);
        if (it != st.end())
            st.erase(it);
        st.insert(l);
        cout << st.size() << " \n"[i == n];
    }
}
/*
666
首先 i = 1 时，st.size()是答案
如果有比 r 大的 l，那么答案肯定不变，没问题
否则后面加个 r 肯定能 +1
所以。。。
*/

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