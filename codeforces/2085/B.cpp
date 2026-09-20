// Date: 2025-03-22
// Time: 22:44:37
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    /*
    要满足最后一次操作为0
    那么在这前一次 里面不能有0
    在这前两次 就必须要有0

    0 0 -> 1
    0 1 -> 2

    实际上就是把数组里的0变没

    如果有0 就合并他们


    */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (count(a.begin(), a.end(), 0) == n)
    {
        cout << "3\n";
        cout << "3 " << n << '\n';
        cout << "1 2\n";
        cout << "1 2\n";
        return;
    }
    vector<pair<int, int>> ans;
    int l = 0;
    vector<int> b;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            int j = i + 1, cnt = 1;
            while (j < a.size() && a[j] == 0)
            {
                j++;
                cnt++;
            }
            if (b.empty())
            {
                if (j == a.size())
                {
                    ans.push_back({1, n - 1});
                    ans.push_back({1, 2});
                    b.push_back(1);
                    break;
                }
                else
                {
                    if (cnt == 1)
                    {
                        ans.push_back({1, 2});
                    }
                    else
                    {
                        ans.push_back({i + 1, i + cnt});
                        b.push_back(1);
                    }
                }
            }
            else
            {
                if (cnt == 1)
                {
                    ans.push_back({b.size(), b.size() + cnt});
                }
                else
                {
                    ans.push_back({b.size() + 1, b.size() + cnt});
                    b.push_back(1);
                }
            }
            i = j - 1;
        }
        else
            b.push_back(1);
    }
    // if (ans.empty())
    //     ans.push_back({1, n});
    if (b.size() > 1)
        ans.push_back({1, b.size()});
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << " " << y << '\n';
    // cout << '\n';
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