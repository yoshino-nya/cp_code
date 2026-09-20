// Date: 2025-04-04
// Time: 20:39:26
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    if (x > k * sum)
    {
        cout << "0\n";
        return;
    }
    ll ned = x / sum * sum;
    // 完整的區間需要減去 x/sum 個，這部分的 sum 是 ned
    // 也許剛好整除了 那麽答案就是

    if (x % sum == 0)
    {
        cout << (k - x / sum) * n + 1 << '\n';
        return;
    }

    ll idx = 1LL * n * k - x / sum * n;

    // 我們找一個後綴 使得這個後綴的 sum 小於 x
    // 并且這個後綴 再多加一個數字 就會使得 sum 大於等於 x
    

    for (int i = n; i >= 1; i--)
    {
        if (ned + a[i] >= x)
        {
            cout << idx << '\n';
            return;
        }
        ned += a[i];
        idx--;
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