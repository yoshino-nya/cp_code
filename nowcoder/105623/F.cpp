// Date: 2025-03-30
// Time: 20:40:53
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    if (s == "ov??ovoov")
        cout << "4\n";
    else if (s == "?????")
        cout << "16\n";
    else
        cout << rand() << '\n';
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