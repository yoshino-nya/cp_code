#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    {
        int cnt = 0, L = 0, R = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= k)
                cnt++;
            if (cnt * 2 >= i)
            {
                L = i;
                break;
            }
        }
        cnt = 0;
        for (int i = n; i > 1; i--)
        {
            if (a[i] <= k)
                cnt++;
            if (cnt * 2 >= n - i + 1)
            {
                R = i;
                break;
            }
        }
        cnt = 0;
        if (L && R && (L + 1 < R))
        {
            cout << "YEs\n";
            return;
        }
    }
    auto check = [&]()
    {
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > k)
                s[i] = s[i - 1] - 1;
            else
                s[i] = s[i - 1] + 1;
        }
        multiset<int> st{s.begin() + 1, s.begin() + n};
        for (int i = 1; i + 1 < n; i++)
        {
            st.erase(st.find(s[i]));
            if (s[i] >= 0)
            {
                auto it = st.lower_bound(s[i]);
                if (it != st.end())
                    return true;
            }
        }
        return false;
    };
    bool ans = false;
    ans |= check();
    reverse(a.begin() + 1, a.end());
    ans |= check();
    cout << (ans ? "YES" : "NO") << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}