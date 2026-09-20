// Date: 2025-03-11
// Time: 13:51:36

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    ll x = 0, L = 1, R = 1;
    while (n--) {
        char o1, o2;
        int x1, x2;
        cin >> o1 >> x1 >> o2 >> x2;
        if (o1 == 'x' && o2 == 'x') {
            if (x1 > x2) {
                L += x;
                x = L * (x1 - 1) + R * (x2 - 1);
            } else if (x1 < x2) {
                R += x;
                x = L * (x1 - 1) + R * (x2 - 1);
            } else {
                x = x * x1 + L * (x1 - 1) + R * (x2 - 1);
            }
        } else if (o1 == 'x') {
            L += x;
            x = L * (x1 - 1) + x2;
        } else if (o2 == 'x') {
            R += x;
            x = R * (x2 - 1) + x1;
        } else {
            x += x1 + x2;
        }
    }
    cout << L + R + x << '\n';
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