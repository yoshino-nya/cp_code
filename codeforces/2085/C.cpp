// Date: 2025-03-22
// Time: 23:18:38
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    /*
    (x+k) + (y+k) = (x+k)^(y+k)


    */
    int x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << "-1\n";
        return;
    }
    if (x < y)
        swap(x, y);
    long long n = 1LL << (__lg(x) + 1);
    long long k = n - x;
    assert((x + k) + (y + k) == ((x + k) ^ (y + k)));
    cout << k << '\n';
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