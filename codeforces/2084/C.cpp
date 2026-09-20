// Date: 2025-04-05
// Time: 22:52:14
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    /*
    必然是有 x y
    就會有 y x 不然就不行
    若n為奇數 則肯定會有一個位置兩邊是相同的 這個一定要放在中間
    */
    vector<int> p1(n + 1), p2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p1[a[i]] = i;
        p2[b[i]] = i;
    }
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == b[i])
                cnt++;
            if (p1[b[i]] != p2[a[i]])
            {
                cout << "-1\n";
                return;
            }
        }
        if ((n & 1) && cnt > 1)
        {
            cout << "-1\n";
            return;
        }
        if ((n % 2 == 0) && cnt)
        {
            cout << "-1\n";
            return;
        }
    }
    vector<pair<int, int>> ans;
    if (n & 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == b[i])
            {
                if (i != (n + 1) / 2)
                {
                    ans.push_back({i, (n + 1) / 2});

                    swap(a[i], a[(n + 1) / 2]);
                    swap(b[i], b[(n + 1) / 2]);
                    p1[a[i]] = i;
                    p2[b[i]] = i;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i + 1;
        if (b[j] != a[i])
        {
            int k = p1[b[i]];
            // swap(k,j)
            swap(a[j], a[k]);
            swap(b[j], b[k]);
            ans.push_back({k, j});
            p1[a[k]] = k;
            p2[b[k]] = k;
        }
        // for (int j = 1; j <= n; j++)
        //     cerr << a[j] << " \n"[j == n];
        // for (int j = 1; j <= n; j++)
        //     cerr << b[j] << " \n"[j == n];
    }
    // {
    //     vector c = a;
    //     reverse(c.begin() + 1, c.end());
    //     assert(c == b);
    // }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans)
        cout << l << " " << r << '\n';
}
/*
4
1 3 2 4
2 4 1 3

3 1 2 4
4 2 1 3

5
2 5 1 3 4
3 5 4 2 1

1 2 3 4
4 3 2 1
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