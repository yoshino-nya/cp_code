// Date: 2025-03-24
// Time: 10:14:47
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;
vector<int> minp(N + 1);

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> ans;
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        if (minp[mid - i] == mid - i)
        {
            mid -= i;
            break;
        }
        if (minp[mid + i] == mid + i)
        {
            mid += i;
            break;
        }
    }
    cout << mid << " ";
    int l = mid - 1, r = mid + 1;
    while (l >= 1 || r <= n)
    {
        if (l >= 1)
        {
            cout << l << ' ';
            l--;
        }
        if (r <= n)
        {
            cout << r << " ";
            r++;
        }
    }
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= N; i++)
    {
        if (minp[i])
            continue;
        minp[i] = i;
        if (1LL * i * i > N)
            continue;
        for (int j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}