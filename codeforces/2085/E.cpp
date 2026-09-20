// Date: 2025-03-24
// Time: 16:37:50
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    if (a == b)
    {
        cout << "998244353\n";
        return;
    }
    /*
    k的最小的可能的值是 b中最大值+1
    但这远远不够的

    如果b中没有对应的a 那么必然要模了
    并且模了之后 对应的值的数量还不能变的

    那么比k最小值还小的数字 自然不可能会变了
    但这个根本不够

    x%k=A
    suma%k = sumb%k
    k | suma - sumb
    也就是说 可行的 k 的数量是有限的

    值是 1e10 枚举因子范围 1e5
    因子数量应该只有log个
    */
    long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += a[i] - b[i];
    }
    if (s < 0)
    {
        cout << "-1\n";
        return;
    }
    auto check = [&](long long x)
    {
        if (x <= b[n] || x > 1000000000)
            return false;
        vector<int> c = a;
        for (int i = 1; i <= n; i++)
            c[i] %= x;
        sort(c.begin() + 1, c.end());
        return c == b;
    };
    for (long long i = 1; i * i <= s; i++)
    {
        if (s % i == 0)
        {
            if (check(i))
            {
                cout << i << '\n';
                return;
            }
            if (check(s / i))
            {
                cout << s / i << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
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