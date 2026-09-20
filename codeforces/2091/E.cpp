// Date: 2025-03-26
// Time: 09:22:23
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e7;
int minp[N + 1];

/*
ab/gcd/gcd
x*gcd*gcd*y /gcd*gcd
也就是说 y是一个质数
x是1
*/
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (minp[i] == i)
        {
            ans += n / i;
        }
    }
    cout << ans << '\n';
}
/*
2 , 1 2, 2 4,
3 , 1 3
4 , 1 4
5 , 1 5
*/

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
        if (i * i > N)
            continue;
        if(1LL*i*i>N) continue;
        for (int j = i * i; j <= N; j += i)
            minp[j] = i;
    }

    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}