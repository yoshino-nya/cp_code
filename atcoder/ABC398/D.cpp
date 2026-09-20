// Date: 2025-03-22
// Time: 20:21:47
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    int x = 0, y = 0;
    // 看有多少个 r,c?
    set<pair<int, int>> st;
    st.insert(make_pair(0, 0));
    for (auto ch : s)
    {
        if (ch == 'N')
            x--;
        else if (ch == 'S')
            x++;
        else if (ch == 'W')
            y--;
        else if (ch == 'E')
            y++;
        if (st.count(make_pair(x - r, y - c)))
            cout << 1;
        else
            cout << 0;
        // cerr << "now:::  " << x << " " << y << " " << x - r << " " << y - c << '\n';
        // for (auto [x, y] : st)
        //     cerr << x << " " << y << '\n';
        st.insert(make_pair(x, y));
    }
}
/*
6 -2 1
001010
NNEEWS
-1 0
-2 0
-2 1
-2 2
-2 1
-1 1
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}