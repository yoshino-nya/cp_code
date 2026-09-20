// Date: 2025-03-19
// Time: 08:20:54

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; i++)
        cin >> x[i];
    int lst = 0;
    bool ok = true;
    for (int i = 0; i < q; i++) {
        // cerr << "lst:" << lst << " \n";
        if (!ok) {
            if (x[i] <= x[0] && x[i] >= lst) {
                cout << "1";
                lst = x[i];
            } else
                cout << "0";
            continue;
        }
        if (x[i] >= lst) {
            cout << "1";
            lst = x[i];
        } else if (ok && x[i] <= x[0]) {
            cout << "1";
            ok = false;
            lst = x[i];
        } else
            cout << "0";
    }
    cout << '\n';
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