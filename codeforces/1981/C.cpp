// Date: 2025-03-14
// Time: 14:42:08

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 1;
    int l = -1, r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1) {
            r = i;
            if (l == -1) {
                for (int j = i - 1; j >= 1; j--)
                    a[j] = a[j + 1] == 1 ? 2 : a[j + 1] / 2;
            } else {
                int L = l, R = r;
                while (L < R - 1) {
                    if (a[L] >= a[R]) {
                        a[L + 1] = a[L] == 1 ? 2 : a[L] / 2;
                        L++;
                    } else {
                        a[R - 1] = a[R - 1] == 1 ? 2 : a[R] / 2;
                        R--;
                    }
                }
                if (a[L] != a[R] / 2 && a[L] / 2 != a[R]) {
                    cout << "-1\n";
                    return;
                }
            }
            l=i;
        }
    }
    for (int i = r + 1; i <= n; i++)
        a[i] = a[i - 1] == 1 ? 2 : a[i - 1] / 2;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
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