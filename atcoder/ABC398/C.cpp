// Date: 2025-03-22
// Time: 20:06:45
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    set<int> st, st1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (st.count(a[i]))
        {
            st1.erase(a[i]);
            continue;
        }
        else
        {
            st1.insert(a[i]);
            st.insert(a[i]);
        }
    }
    if (st1.empty())
    {
        cout << "-1\n";
        return;
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i]==*st1.rbegin())
        {
            cout << i << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}