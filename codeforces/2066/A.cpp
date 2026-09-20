// Date: 2025-03-13
// Time: 23:27:29

#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> x(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        vis[x[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (ask(i, i % n + 1))
                cout << "! B" << endl;
            else
                cout << "! A" << endl;
            return;
        }
    }
    int p1 = min_element(x.begin() + 1, x.end()) - x.begin();
    int p2 = max_element(x.begin() + 1, x.end()) - x.begin();
    int X = ask(p1, p2), Y = ask(p2, p1);
    if (X == Y && X >= n - 1)
        cout << "! B" << endl;
    else
        cout << "! A" << endl;
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